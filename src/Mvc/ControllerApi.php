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
use Phalconator\Exception;
use Phalconator\Http\Response\StatusCode;

/**
 * Class ControllerApi
 *
 * @package Phalconator\Mvc
 */
abstract class ControllerApi extends Controller
{
    const OK = 'OK';
    const ERROR = 'ERROR';

    protected $charset = 'UTF-8';
    protected $contentType = 'application/json';

    /**
     * Génère un réponse en succès
     *
     * @param array $data
     * @param int $statusCode
     * @return array
     */
    protected function responseOk(array $data, $statusCode = 200)
    {
        $this->response->setStatusCode($statusCode, StatusCode::message($statusCode));
        $requestTime = $this->request->getServer('REQUEST_TIME_FLOAT') ?? STARTTIME;

        return [
            'status' => self::OK,
            'latency' => round((microtime(true) - $requestTime) * 1000),
            'data' => $data
        ];
    }

    /**
     * Génère une réponse en erreur
     *
     * @param string|array $data
     * @param int $statusCode
     * @return array
     */
    protected function responseError($data, int $statusCode = 500)
    {
        $this->response->setStatusCode($statusCode, StatusCode::message($statusCode));
        $requestTime = $this->request->getServer('REQUEST_TIME_FLOAT') ?? STARTTIME;

        return [
            'status' => self::ERROR,
            'latency' => round((microtime(true) - $requestTime) * 1000),
            'messages' => function () use ($data) {
                if (is_array($data)) {
                    $messages = [];

                    foreach ($data as $key => $message) {
                        switch (true) {
                            case $message instanceof \Phalcon\Mvc\Model\MessageInterface:
                            case $message instanceof \Phalcon\Validation\MessageInterface:
                                $messages[$message->getField()] = $message->getMessage();
                                break;

                            default:
                                $messages[$key] = strval($message);
                                break;
                        }
                    }

                    return $messages;

                } else {
                    return strval($data);
                }
            }
        ];
    }

    /**
     * @inheritdoc
     *
     * @throws Exception
     */
    public function afterExecuteRoute(Dispatcher $dispatcher)
    {
        $content = $dispatcher->getReturnedValue();
        $this->response->setContentType($this->contentType, $this->charset);

        if (is_array($content)) {

            switch ($this->contentType) {
                case 'application/json':
                    $this->response->setJsonContent($content);
                    break;

                default:
                    throw new Exception("Le type de contenu retourné n'est pas compatible avec l'api");
                    break;
            }

        } else {
            $this->response->setContent($content);
        }
    }
}
