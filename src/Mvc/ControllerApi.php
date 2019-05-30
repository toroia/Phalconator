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

use Phalcon\Dispatcher;
use Phalcon\Mvc\Controller;
use Phalconator\Http\Response\Builder;

/**
 * Class ControllerApi
 *
 * @package Phalconator\Mvc
 */
abstract class ControllerApi extends Controller
{
    /** @var Builder $responseBuilder */
    protected $responseBuilder;

    protected $charset = 'UTF-8';
    protected $contentType = 'application/json';

    /**
     * @inheritDoc
     */
    public function beforeExecuteRoute()
    {
        $this->responseBuilder = new Builder;
    }

    /**
     * @inheritdoc
     */
    public function afterExecuteRoute(Dispatcher $dispatcher)
    {
        $content = $dispatcher->getReturnedValue();
        $this->response->setContentType($this->contentType, $this->charset);

        if (is_array($content)) {
            switch ($this->contentType) {
                case 'application/json':
                    $this->response->setJsonContent($content, JSON_PRETTY_PRINT);
                    break;

                default:
                    $this->response->setJsonContent($this->responseBuilder->error("The API contentType is not supported"));
                    break;
            }
        } else {
            $this->response->setContent($content);
        }
    }
}
