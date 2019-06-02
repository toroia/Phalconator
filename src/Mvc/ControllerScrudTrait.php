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

use DateTime;
use MongoDB\BSON\UTCDateTime;
use Phalcon\Di;
use Phalcon\Di\Injectable;
use Phalcon\DiInterface;
use Phalcon\Filter;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\ModelInterface;
use Phalconator\Http\Response\StatusCode;

/**
 * Trait ScrudControllerTrait
 *
 * @package Phalconator\Mvc
 * @method void beforeSearch(array $parameters) Effectue des actions avant la recherche
 * @method void fetchSearch(ModelInterface | CollectionInterface $record) Modifie le retour d'une itération de recherche
 * @method void beforeCreate(ModelInterface | CollectionInterface $record) Effectue des opérations avant la création
 * @method void beforeUpdate(ModelInterface | CollectionInterface $record) Effectue des opérations avant la modification
 * @method array afterCreate(ModelInterface | CollectionInterface $record) Effectue des opérations après la création
 * @method array afterUpdate(ModelInterface | CollectionInterface $record) Effectue des opérations après la modification
 */
trait ControllerScrudTrait
{
    /** @var ModelInterface|CollectionInterface $source */
    protected $source;

    /** @var int $defaultRowCount */
    protected $defaultRowCount = 7;

    /**
     * @return DiInterface
     */
    public function getDI(): DiInterface
    {
        if (is_subclass_of($this, Injectable::class)) {
            return call_user_func(['parent', 'getDI']);
        }
        return Di::getDefault();
    }

    /**
     * @inheritDoc
     */
    public function searchAction(): array
    {
        $parameters = [];
        $request = $this->getDI()->get('request');
        $responseBuilder = $this->getDI()->get('responseBuilder');

        $pageIndex = $request->get('pageIndex', Filter::FILTER_INT_CAST, 1);
        $rowCount = $request->get('rowCount', Filter::FILTER_INT_CAST, $this->defaultRowCount);

        if (method_exists($this, 'beforeSearch')) {
            $this->beforeSearch($parameters);
        }

        $total = $this->source::count((array)$parameters);

        $parameters['limit'] = $rowCount;
        $parameters['offset'] = ($pageIndex - 1) * $rowCount;

        $records = $this->source::find((array)$parameters);

        if (method_exists($this, 'fetchSearch')) {
            return $responseBuilder->success(
                [
                    'rows' => array_map([$this, 'fetchSearch'], $records),
                    'total' => $total
                ]
            );
        }

        return $responseBuilder->success(
            [
                'rows' => array_map(function ($record) {
                    if (is_object($record)) {
                        if (method_exists($record, 'toJsonify')) {
                            return $this->toJsonify($record);
                        }

                        if (method_exists($record, 'toArray')) {
                            return $record->toArray();
                        }
                        return get_object_vars($record);
                    }
                    return $record;
                }, $records),
                'total' => $total
            ]
        );
    }

    /**
     * @inheritDoc
     */
    public function createAction(): array
    {
        $responseBuilder = $this->getDI()->get('responseBuilder');

        /** @var ModelInterface|Model|CollectionInterface|Collection $record */
        $record = new $this->source;

        if (!method_exists($this, 'beforeCreate')) {
            return $this->getDI()->get('response')->error("A manufacturing error in the API has occuzrred");
        }

        $this->beforeCreate($record);

        if ($record->save()) {
            if (method_exists($this, 'afterCreate')) {
                return $responseBuilder->success($this->afterCreate($record), StatusCode::CREATED);
            }

            if (method_exists($record, 'toJsonify')) {
                return $responseBuilder->success($this->toJsonify($record), StatusCode::CREATED);
            }

            return $responseBuilder->success($record->toArray(), StatusCode::CREATED);
        }
        return $responseBuilder->error($record->getMessages(), StatusCode::BAD_REQUEST);
    }

    /**
     * @inheritDoc
     */
    public function readAction(): array
    {
        $responseBuilder = $this->getDI()->get('responseBuilder');
        $dispatcher = $this->getDI()->get('dispatcher');

        $id = $dispatcher->getParam(0, Filter::FILTER_STRING);

        /** @var ModelInterface|Model|CollectionInterface|Collection $record */
        if ($record = $this->source::findById($id)) {
            if (method_exists($this, 'afterRead')) {
                return $responseBuilder->success($this->afterRead($record));
            }

            if (method_exists($record, 'toJsonify')) {
                return $responseBuilder->success($this->toJsonify($record));
            }
            return $responseBuilder->success($record->toArray());
        }
        return $responseBuilder->error("No elements were found", StatusCode::NOT_FOUND);
    }

    /**
     * @inheritDoc
     */
    public function updateAction(): array
    {
        $responseBuilder = $this->getDI()->get('responseBuilder');
        $dispatcher = $this->getDI()->get('dispatcher');

        $id = $dispatcher->getParam(0, Filter::FILTER_STRING);

        /** @var ModelInterface|Model|CollectionInterface|Collection $record */
        if ($record = $this->source::findById($id)) {
            if (method_exists($this, 'beforeUpdate')) {
                $this->beforeUpdate($record);
            } else {
                if (!method_exists($this, 'beforeCreate')) {
                    return $this->getDI()->get('response')->error("A manufacturing error in the API has occuzrred");
                }
                $this->beforeCreate($record);
            }

            if ($record->save()) {
                if (method_exists($this, 'afterUpdate')) {
                    return $responseBuilder->success($this->afterUpdate($record), StatusCode::CREATED);
                } elseif (method_exists($this, 'afterCreate')) {
                    return $responseBuilder->success($this->afterCreate($record), StatusCode::CREATED);
                }

                if (method_exists($record, 'toJsonify')) {
                    return $responseBuilder->success($this->toJsonify($record), StatusCode::CREATED);
                }

                return $responseBuilder->success($record->toArray(), StatusCode::CREATED);
            }
            return $responseBuilder->error($record->getMessages(), StatusCode::BAD_REQUEST);
        }
        return $responseBuilder->error("No elements were found", StatusCode::NOT_FOUND);
    }

    /**
     * @inheritDoc
     */
    public function deleteAction(): array
    {
        $responseBuilder = $this->getDI()->get('responseBuilder');
        $dispatcher = $this->getDI()->get('dispatcher');

        $id = $dispatcher->getParam(0, Filter::FILTER_STRING);

        /** @var ModelInterface|Model|CollectionInterface|Collection $record */
        if ($record = $this->source::findById($id)) {
            if ($record->delete()) {
                if (method_exists($this, 'afterDelete')) {
                    return $responseBuilder->success($this->afterDelete($record), StatusCode::ACCEPTED);
                }

                return $responseBuilder->success('the element has been deleted', StatusCode::ACCEPTED);
            }
            return $responseBuilder->error($record->getMessages(), StatusCode::BAD_REQUEST);
        }
        return $responseBuilder->error('No elements were found', StatusCode::NOT_FOUND);
    }

    /**
     * Transforme les objets avant la sérialisation en JSON
     *
     * @param CollectionInterface $record
     * @return array
     */
    protected function toJsonify($record): array
    {
        return $record->toJsonify(function ($rec) {
            if (is_object($rec)) {
                if ($rec instanceof UTCDateTime) {
                    return $rec->toDateTime()->format(DateTime::ISO8601);
                }
                return strval($rec);
            }
            return $rec;
        });
    }
}
