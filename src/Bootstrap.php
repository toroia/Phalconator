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

use DirectoryIterator;
use Phalcon\Application;
use Phalcon\Config;
use Phalcon\Config\Adapter\Json;
use Phalcon\Di\ServiceProviderInterface;
use Phalcon\DiInterface;
use Phalconator\Bootstrap\Exception;
use Phalconator\Bootstrap\Provider;

/**
 * Class Bootstrap
 *
 * @package Phalconator
 */
final class Bootstrap
{
    /** @var string $basePath */
    protected $basePath;

    /** @var DiInterface $di */
    protected $di;

    /** @var Application $app */
    protected $app;

    /** @var Config $config */
    protected $config;

    /** @var array $services */
    protected $services;

    /** @var array $options */
    protected $options = [];

    const ENV_PREFIX = 'TWA_';
    const ENV_DELIMITER = '_';
    const ENV_FILE_PATH = '/.env';
    const API_MODULE_PREFIX = 'Module';
    const MODULES_DEFAULT_PATH = '/src/modules/';
    const ENV_DEFAULT_PATH = '/src/config/env_default.php';
    const SERVICES_DEFAULT_FILE = '/src/config/services_default.php';

    /**
     * Bootstrap constructor.
     *
     * @param string $basePath
     */
    public function __construct(string $basePath)
    {
        $this->basePath = $basePath;

        $this->options = array_merge([
            'envPrefix' => self::ENV_PREFIX,
            'envDelimiter' => self::ENV_DELIMITER,
            'envFilePath' => self::ENV_FILE_PATH,
            'envDefaultPath' => self::ENV_DEFAULT_PATH,
            'apiModulePrefix' => self::API_MODULE_PREFIX,
            'modulesDefaultPath' => self::MODULES_DEFAULT_PATH,
            'servicesDefaultFile' => self::SERVICES_DEFAULT_FILE
        ], []);
    }

    /**
     * Définit le di du bootstrap
     *
     * @param DiInterface $di
     */
    public function setDI(DiInterface $di): void
    {
        $this->di = $di;
    }

    /**
     * Définit l'application du bootstrap
     *
     * @param Application $app
     */
    public function setApp(Application $app): void
    {
        $this->app = $app;
    }

    /**
     * Définit les services de l'application
     *
     * @param ServiceProviderInterface[] $services
     */
    public function setServices($services): void
    {
        $this->services = [];

        if ($services instanceof Config) {
            $services = $services->toArray();
        }

        foreach ($services as $service) {
            if (is_subclass_of($service, ServiceProviderInterface::class)) {
                $this->services[] = $service;
            }
        }
    }

    /**
     * Définit la configuration de l'application
     *
     * @param Config $config
     */
    public function setConfig(Config $config)
    {
        $this->config = $config;
    }

    /**
     * Démarre l'application
     *
     * @return Application
     * @throws Exception
     */
    public function run(): Application
    {
        if (!$this->di instanceof DiInterface) {
            throw new Exception("Bootstrap does not implement DI");
        }

        if (!$this->app instanceof Application) {
            throw new Exception("Bootstrap does not implement Application");
        }

        if (empty($this->services)) {
            throw new Exception("Bootstrap has no configured services");
        }

        $this->di->setShared('config', $this->config);

        (new Provider($this->di))
            ->load($this->services)
            ->register();

        $this->app->setDI($this->di);
        return $this->app;
    }

    /**
     * Enregistre les modules au sein de l'application
     *
     * @param string|null $path
     * @throws Exception
     */
    public function registerModules(?string $path = null): void
    {
        $registeredModules = [];
        $modulesPath = $this->basePath . DIRECTORY_SEPARATOR . $path;
        $modules = new DirectoryIterator($modulesPath);

        if (!$this->app instanceof Application) {
            throw new Exception("Bootstrap does not implement Application");
        }

        if (!$modules->isDir()) {
            throw new Exception("Bootstrap cannot access to modules");
        }

        foreach ($modules as $module) {
            if ($module->isDot()) continue;
            if (!$module->isDir()) continue;

            $moduleName = $module->getFilename();
            $composerModulePath = $module->getRealPath() . DIRECTORY_SEPARATOR . 'composer.json';

            if (file_exists($composerModulePath)) {
                $composerObject = new Json($composerModulePath);

                if ($composerObject->offsetExists('extra')
                    && $composerObject->get('extra')->offsetExists('phalconator')
                    && $composerObject->get('extra')->get('phalconator')->offsetExists('module')) {
                    $moduleName = $composerObject->get('extra')->get('phalconator')->get('module');
                }
            }

            $registeredModules[strtolower($moduleName)] = [
                'className' => 'Toroia\Modules\\' . ucfirst($moduleName) . '\Module',
                'path' => implode(DIRECTORY_SEPARATOR, [$module->getRealPath(), 'Module.php'])
            ];
        }

        $this->app->registerModules($registeredModules);
    }
}
