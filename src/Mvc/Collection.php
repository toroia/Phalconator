<?php declare(strict_types=1);

/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator\Mvc;

use MongoDB\BSON\ObjectId;
use MongoDB\BSON\Unserializable;
use Phalcon\Di;
use Phalcon\Mvc\Collection as CollectionBase;
use Phalcon\Mvc\Collection\Document;
use Phalcon\Mvc\Collection\Exception;
use Phalcon\Mvc\CollectionInterface;

/**
 * Class ControllerApi
 *
 * @package Phalconator\Mvc
 */
abstract class CollectionX extends CollectionBase implements Unserializable
{
    public function setId($id)
    {
        $objectId = null;

        if (!is_object($id)) {

            /**
             * Check if the model use implicit ids
             */
            if ($this->_modelsManager->isUsingImplicitObjectIds($this)) {
                $objectId = new ObjectId($id);
            } else {
                $objectId = $id;
            }

        } else {

            $objectId = $id;
        }

        $this->_id = $objectId;
    }

    protected function _exists($collection)
    {
        $objectId = null;

        if (!$id = $this->_id) {
            return false;
        }
        if (!$this->_dirtyState) {
            return true;
        }
        if (is_object($id)) {
            $objectId = $id;
        } else {
            /**
             * Check if the model use implicit ids
             */
            if ($this->_modelsManager->isUsingImplicitObjectIds($this)) {
                $objectId = new ObjectID($id);
            } else {
                $objectId = $id;
            }
        }
        /**
         * Perform the count using the function provided by the driver
         */
        $exists = $collection->count(["_id" => $objectId]) > 0;
        if ($exists) {
            $this->_dirtyState = self::DIRTY_STATE_PERSISTENT;
        } else {
            $this->_dirtyState = self::DIRTY_STATE_TRANSIENT;
        }

        return $exists;
    }

    public function save()
    {
        $dependencyInjector = $this->_dependencyInjector;
        if (!is_object($dependencyInjector)) {
            throw new Exception(
                "A dependency injector container is required to obtain the services related to the ODM"
            );
        }
        $source = $this->getSource();
        if (empty($source)) {
            throw new Exception("Method getSource() returns empty string");
        }
        $connection = $this->getConnection();
        $collection = $connection->selectCollection($source);
        $exists = $this->_exists($collection);
        if (false === $exists) {
            $this->_operationMade = self::OP_CREATE;
        } else {
            $this->_operationMade = self::OP_UPDATE;
        }
        /**
         * The messages added to the validator are reset here
         */
        $this->_errorMessages = [];
        $disableEvents = self::$_disableEvents;
        /**
         * Execute the preSave hook
         */
        if (false === $this->_preSave($dependencyInjector, $disableEvents, $exists)) {
            return false;
        }
        $data = $this->toArray();
        /**
         * We always use safe stores to get the success state
         * Save the document
         */
        switch ($this->_operationMade) {
            case self::OP_CREATE:
                $status = $collection->insertOne($data);
                break;
            case self::OP_UPDATE:
                unset($data['_id']);
                $status = $collection->updateOne(['_id' => $this->_id], ['$set' => $data]);
                break;
            default:
                throw new Exception('Invalid operation requested for ' . __METHOD__);
        }
        $success = false;
        if ($status->isAcknowledged()) {
            $success = true;
            if (false === $exists) {
                $this->_id = $status->getInsertedId();
                $this->_dirtyState = self::DIRTY_STATE_PERSISTENT;
            }
        }
        /**
         * Call the postSave hooks
         */
        return $this->_postSave($disableEvents, $success, $exists);
    }

    protected static function _getResultset($params, CollectionInterface $collection, $connection, $unique)
    {
        /**
         * @codingStandardsIgnoreEnd
         * Check if "class" clause was defined
         */
        if (isset($params['class'])) {
            $classname = $params['class'];
            $base = new $classname();
            if (!$base instanceof CollectionInterface || $base instanceof Document) {
                throw new Exception(
                    sprintf(
                        'Object of class "%s" must be an implementation of %s or an instance of %s',
                        get_class($base),
                        CollectionInterface::class,
                        Document::class
                    )
                );
            }
        } else {
            $base = $collection;
        }
        if ($base instanceof Collection) {
            $base->setDirtyState(Collection::DIRTY_STATE_PERSISTENT);
        }
        $source = $collection->getSource();
        if (empty($source)) {
            throw new Exception("Method getSource() returns empty string");
        }
        /**
         * @var \Phalcon\Db\Adapter\MongoDB\Collection $mongoCollection
         */
        $mongoCollection = $connection->selectCollection($source);
        if (!is_object($mongoCollection)) {
            throw new Exception("Couldn't select mongo collection");
        }
        $conditions = [];
        if (isset($params[0])||isset($params['conditions'])) {
            $conditions = (isset($params[0]))?$params[0]:$params['conditions'];
        }
        /**
         * Convert the string to an array
         */
        if (!is_array($conditions)) {
            throw new Exception("Find parameters must be an array");
        }
        $options = [];
        /**
         * Check if a "limit" clause was defined
         */
        if (isset($params['limit'])) {
            $limit = $params['limit'];
            $options['limit'] = (int)$limit;
            if ($unique) {
                $options['limit'] = 1;
            }
        }
        /**
         * Check if a "sort" clause was defined
         */
        if (isset($params['sort'])) {
            $sort = $params["sort"];
            $options['sort'] = $sort;
        }
        /**
         * Check if a "skip" clause was defined
         */
        if (isset($params['skip'])) {
            $skip = $params["skip"];
            $options['skip'] = (int)$skip;
        }
        if (isset($params['fields']) && is_array($params['fields']) && !empty($params['fields'])) {
            $options['projection'] = [];
            foreach ($params['fields'] as $key => $show) {
                $options['projection'][$key] = $show;
            }
        }
        /**
         * Perform the find
         */
        $cursor = $mongoCollection->find($conditions, $options);
        $cursor->setTypeMap(['root' => get_class($base), 'document' => 'array']);
        if (true === $unique) {
            /**
             * Looking for only the first result.
             */
            return current($cursor->toArray());
        }
        /**
         * Requesting a complete resultset
         */
        $collections = [];
        foreach ($cursor as $document) {
            /**
             * Assign the values to the base object
             */
            $collections[] = $document;
        }
        return $collections;
    }

    public function bsonUnserialize(array $data)
    {
        $this->setDI(Di::getDefault());
        $this->_modelsManager = Di::getDefault()->getShared('collectionManager');
        foreach ($data as $key => $val) {
            $this->{$key} = $val;
        }
        if (method_exists($this, "afterFetch")) {
            $this->afterFetch();
        }
    }
}
