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
    protected $stateError = 'ERROR';
    protected $stateSuccess = 'SUCCESS';

    /**
     * Génère une réponse en erreur
     *
     * @param mixed $content
     * @param int $statusCode
     * @return array
     */
    public function error($content = null, int $statusCode = 500): array
    {
        $this->getDI()->get('response')->setStatusCode($statusCode, StatusCode::message($statusCode));

        return array_merge([
            'status' => $this->getStateError(),
            'latency' => round((microtime(true) - $_SERVER['REQUEST_TIME_FLOAT']) * 1000)
        ], $this->getErrorMessage($content));
    }

    /**
     * Génère un réponse en succès
     *
     * @param mixed $content
     * @param int $statusCode
     * @return array
     */
    public function success($content = null, int $statusCode = 200): array
    {
        $this->getDI()->get('response')->setStatusCode($statusCode, StatusCode::message($statusCode));

        return array_merge([
            'status' => $this->getStateSuccess(),
            'latency' => round((microtime(true) - $_SERVER['REQUEST_TIME_FLOAT']) * 1000)
        ], $this->getSuccessMessage($content));
    }

    /**
     * @return string
     */
    public function getStateError(): string
    {
        return $this->stateError;
    }

    /**
     * @param string $stateError
     */
    public function setStateError(string $stateError): void
    {
        $this->stateError = $stateError;
    }

    /**
     * @return string
     */
    public function getStateSuccess(): string
    {
        return $this->stateSuccess;
    }

    /**
     * @param string $stateSuccess
     */
    public function setStateSuccess(string $stateSuccess): void
    {
        $this->stateSuccess = $stateSuccess;
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

            return [
                'messages' => $result
            ];
        }

        return [
            'message' => strval($content) ?? 'A generic error has occurred'
        ];
    }
}
