<?php declare(strict_types=1);

/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator\Http\Response;

use Phalcon\Di\Injectable;
use Phalcon\Mvc\Model\MessageInterface as ModelMessageInterface;
use Phalcon\Validation\MessageInterface as ValidationMessageInterface;

/**
 * Class Builder
 *
 * @package Phalconator\Http\Response
 */
class Builder extends Injectable
{
    const SUCCESS = 'SUCCESS';
    const ERROR = 'ERROR';

    /**
     * Génère un réponse en succès
     *
     * @param mixed $content
     * @param int $statusCode
     * @return array
     */
    public function success($content = null, int $statusCode = 200)
    {
        $this->response->setStatusCode($statusCode, StatusCode::message($statusCode));
        $requestTime = $this->request->getServer('REQUEST_TIME_FLOAT') ?? STARTTIME;

        return array_merge([
            'status' => self::SUCCESS,
            'latency' => round((microtime(true) - $requestTime) * 1000),
        ], $this->getSuccessMessage($content));
    }

    /**
     * Génère une réponse en erreur
     *
     * @param mixed $content
     * @param int $statusCode
     * @return array
     */
    public function error($content = null, int $statusCode = 500)
    {
        $this->response->setStatusCode($statusCode, StatusCode::message($statusCode));
        $requestTime = $this->request->getServer('REQUEST_TIME_FLOAT') ?? STARTTIME;

        return [
            'status' => self::ERROR,
            'latency' => round((microtime(true) - $requestTime) * 1000),
            'messages' => $this->getErrorMessage($content)
        ];
    }

    /**
     * Génère un message de succès pour l'api
     *
     * @param mixed $content
     * @return array
     */
    private function getSuccessMessage($content)
    {
        if (is_array($content)) {
            return [
                'data' => $content
            ];

        } elseif (is_string($content)) {
            return [
                'message' => $content
            ];

        }

        return [];
    }

    /**
     * Génère un message d'erreur pour l'api
     *
     * @param mixed $content
     * @return array|string
     */
    private function getErrorMessage($content)
    {
        if (is_array($content)) {
            $result = [];

            foreach ($content as $key => $message) {
                switch (true) {
                    case ($message instanceof ModelMessageInterface):
                    case ($message instanceof ValidationMessageInterface):
                        $result[$message->getField()] = $message->getMessage();
                        break;

                    default:
                        $result[$key] = strval($message);
                        break;
                }
            }

            return $result;
        }

        return strval($content) ?? 'A generic error has occurred';
    }
}
