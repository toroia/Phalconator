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

/**
 * Class ControllerApi
 *
 * @package Phalconator\Mvc
 */
abstract class ControllerApi extends Controller
{
    /**
     * @inheritdoc
     */
    public function afterExecuteRoute(Dispatcher $dispatcher)
    {
        $this->response->setContentType('application/json', 'UTF-8');

        if (is_array($response = $dispatcher->getReturnedValue())) {
            $requestTime = $this->request->getServer('REQUEST_TIME_FLOAT') ?? STARTTIME;

            $response += [
                'latency' => round((microtime(true) - $requestTime) * 1000)
            ];

            $this->response->setJsonContent($response);
        }
    }
}
