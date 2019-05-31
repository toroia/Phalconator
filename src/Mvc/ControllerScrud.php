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
use Phalcon\Filter;
use Phalcon\Mvc\ModelInterface;
use Phalconator\Http\Response\StatusCode;

/**
 * Class ControllerScrud
 *
 * @package Phalconator\Mvc
 * @method void beforeSearch(array $parameters) Effectue des actions avant la recherche
 * @method void fetchSearch(ModelInterface | CollectionInterface $record) Modifie le retour d'une itération de recherche
 * @method void beforeCreate(ModelInterface | CollectionInterface $record) Effectue des opérations avant la création
 * @method void beforeUpdate(ModelInterface | CollectionInterface $record) Effectue des opérations avant la modification
 * @method array afterCreate(ModelInterface | CollectionInterface $record) Effectue des opérations après la création
 * @method array afterUpdate(ModelInterface | CollectionInterface $record) Effectue des opérations après la modification
 */
abstract class ControllerScrud extends ControllerApi implements ControllerScrudInterface
{
    /** @var ModelInterface|CollectionInterface $source */
    protected $source;

    /** @var int $defaultRowCount */
    protected $defaultRowCount = 7;

    /**
     * @inheritDoc
     */
    public function initialize(): void
    {
        if (!isset($this->source) || !class_exists($this->source)) {
            $this->response->setJsonContent(
                $this->responseBuilder->error("A manufacturing error in the API has occurred")
            );

            $this->response->send();
            exit();
        }

        if (!is_subclass_of($this->source, ModelInterface::class)
            && !is_subclass_of($this->source, CollectionInterface::class)) {
            $this->response->setJsonContent(
                $this->responseBuilder->error("A manufacturing error in the API has occurredd")
            );

            $this->response->send();
            exit();
        }

        if (method_exists($this, 'initializeScrud')) {
            $this->initializeScrud();
        }
    }

    /**
     * @inheritDoc
     */
    public function searchAction(): array
    {
        $parameters = [];
        $pageIndex = $this->request->get('pageIndex', Filter::FILTER_INT_CAST, 1);
        $rowCount = $this->request->get('rowCount', Filter::FILTER_INT_CAST, $this->defaultRowCount);

        if (method_exists($this, 'beforeSearch')) {
            $this->beforeSearch($parameters);
        }

        $total = $this->source::count((array)$parameters);

        $parameters['limit'] = $rowCount;
        $parameters['offset'] = ($pageIndex - 1) * $rowCount;

        $records = $this->source::find((array)$parameters);

        if (method_exists($this, 'fetchSearch')) {
            return $this->responseBuilder->success(
                [
                    'rows' => array_map([$this, 'fetchSearch'], $records),
                    'total' => $total
                ]
            );
        }

        return $this->responseBuilder->success(
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
        /** @var ModelInterface|CollectionInterface $record */
        $record = new $this->source;

        if (!method_exists($this, 'beforeCreate')) {
            return $this->responseBuilder->error("A manufacturing error in the API has occuzrred");
        }

        $this->beforeCreate($record);

        if ($record->save()) {
            if (method_exists($this, 'afterCreate')) {
                return $this->responseBuilder->success($this->afterCreate($record), StatusCode::CREATED);
            }

            if (method_exists($record, 'toJsonify')) {
                return $this->responseBuilder->success($this->toJsonify($record), StatusCode::CREATED);
            }

            if (method_exists($record, 'toArray')) {
                return $this->responseBuilder->success($record->toArray(), StatusCode::CREATED);
            }
        }
        return $this->responseBuilder->error($record->getMessages(), StatusCode::BAD_REQUEST);
    }

    /**
     * @inheritDoc
     */
    public function readAction(): array
    {
        $id = $this->dispatcher->getParam(0, Filter::FILTER_STRING);

        if ($record = $this->source::findById($id)) {

        }
        return $this->responseBuilder->error("No elements were found", StatusCode::NOT_FOUND);
    }

    /**
     * @inheritDoc
     */
    public function updateAction(): array
    {

    }

    /**
     * @inheritDoc
     */
    public function deleteAction(): array
    {

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
