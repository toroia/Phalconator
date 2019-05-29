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

use Phalcon\Filter;
use Phalcon\Mvc\ModelInterface;
use stdClass;

/**
 * Class ControllerScrud
 *
 * @package Phalconator\Mvc
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
    public final function initialize(): void
    {
        if (!isset($this->source) || !class_exists($this->source)) {
            $this->response->setJsonContent(
                $this->responseBuilder->error("A manufacturing error in the API has occurred", 500)
            );

            $this->response->send();
            exit();
        }

        if (!is_subclass_of($this->source, ModelInterface::class)
            && !is_subclass_of($this->source, CollectionInterface::class)) {
            $this->response->setJsonContent(
                $this->responseBuilder->error("A manufacturing error in the API has occurredd", 500)
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
    public final function searchAction(): array
    {
        $pageIndex = $this->request->get('pageIndex', Filter::FILTER_INT_CAST, 1);
        $rowCount = $this->request->get('rowCount', Filter::FILTER_INT_CAST, $this->defaultRowCount);

        $parameters = new stdClass;

        if (method_exists($this, 'beforeSearch')) {
            $this->beforeSearch($parameters);
        }

        $total = $this->source::count((array)$parameters);

        $parameters->limit = $rowCount;
        $parameters->offset = ($pageIndex - 1) * $rowCount;

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
    public final function createAction(): array
    {

    }

    /**
     * @inheritDoc
     */
    public final function readAction(): array
    {

    }

    /**
     * @inheritDoc
     */
    public final function updateAction(): array
    {

    }

    /**
     * @inheritDoc
     */
    public final function deleteAction(): array
    {

    }
}
