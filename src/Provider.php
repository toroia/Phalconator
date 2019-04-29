<?php declare(strict_types=1);

/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator;

use Exception;
use Phalcon\Di\ServiceProviderInterface;
use Phalcon\DiInterface;
use ReflectionClass;
use ReflectionException;

/**
 * Class Provider
 *
 * @package Phalconator
 */
class Provider
{
    /** @var \Phalcon\Di $di */
    protected $di;

    /** @var array $services */
    protected $services = [];

    /**
     * Provider constructor.
     *
     * @param DiInterface $di
     */
    public function __construct(DiInterface $di)
    {
        $this->di = $di;
    }

    /**
     * Charge les services afin de les préparer à l'enregistrement
     *
     * @param array $services
     * @return Provider
     * @throws Exception
     */
    public function load(array $services): self
    {
        foreach ($services as $service) {
            try {
                $class = new ReflectionClass($service);

                if ($class->implementsInterface(ServiceProviderInterface::class)) {
                    $this->services[] = $service;
                }

                // TODO: Gérer le fait que le service soit mal construit et n'"implémente pas l'interface

            } catch (ReflectionException $e) {

                throw new Exception("L'application na pas pu démarrer, le service <$service> est mal implémenté.");
            }
        }

        return $this;
    }

    /**
     * Enregistre les services dans l'injecteur de dépendances (Di)
     */
    public function register(): void
    {
        foreach ($this->services as $service) {

            $this->di->register(new $service);
        }
    }
}
