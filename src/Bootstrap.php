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
use Exception;
use Phalcon\Application;
use Phalcon\Config;
use Phalcon\Config\Adapter\Php as PhpConfig;
use Phalcon\Config\Exception as ExceptionConfig;
use Phalcon\Di;
use Phalcon\DiInterface;
use Phalconator\Config\Adapter\Env as EnvConfig;
use function implode;

/**
 * Class Bootstrap
 *
 * @package Phalconator
 */
final class Bootstrap
{
    /** @var DiInterface $di */
    protected $di;

    /** @var string $basePath */
    protected $basePath;

    /** @var Application $app */
    protected $app;

    /** @var Config $services */
    protected $services;

    /** @var array $options */
    protected $options = [];

    const ENV_PREFIX = 'TWA_';
    const ENV_DELIMITER = '_';
    const ENV_FILE_PATH = '/.env';
    const API_MODULE_PREFIX = 'ApiModule';
    const MODULES_DEFAULT_PATH = '/src/modules/';
    const ENV_DEFAULT_PATH = '/src/config/env_default.php';
    const SERVICES_DEFAULT_FILE = '/src/config/services_default.php';

    /**
     * Bootstrap constructor.
     *
     * @param string $basePath
     * @param Application $app
     * @param Config $services
     * @param array $options
     */
    public function __construct(string $basePath, Application $app, ?Config $services, array $options = [])
    {
        defined('STARTTIME') OR define('STARTTIME', microtime(true));

        $this->di = new Di;

        $this->basePath = $basePath;
        $this->app = $app;
        $this->services = $services;

        $this->options = array_merge([
            'envPrefix' => self::ENV_PREFIX,
            'envDelimiter' => self::ENV_DELIMITER,
            'envFilePath' => self::ENV_FILE_PATH,
            'envDefaultPath' => self::ENV_DEFAULT_PATH,
            'apiModulePrefix' => self::API_MODULE_PREFIX,
            'modulesDefaultPath' => self::MODULES_DEFAULT_PATH,
            'servicesDefaultFile' => self::SERVICES_DEFAULT_FILE
        ], $options);
    }

    /**
     * Démarre l'application
     *
     * @return Application
     */
    public function run(): Application
    {
        $this->configureApplication();
        $this->importProviders();

        if (!is_null($this->services)) {
            $this->registerModules();
        }

        $this->app->setDI($this->di);
        return $this->app;
    }

    /**
     * Configure l'application
     *
     * @return self
     */
    protected function configureApplication(): self
    {
        $basePath = $this->basePath;
        $options = $this->options;

        $this->di->setShared('config', function () use ($basePath, $options) {
            $configPath = implode(DIRECTORY_SEPARATOR, [$basePath, $options['envDefaultPath']]);

            $config = new PhpConfig($configPath);

            try {
                $envPath = implode(DIRECTORY_SEPARATOR, [$basePath, $options['envFilePath']]);

                if (file_exists($envPath)) {
                    $envConfig = new EnvConfig($envPath, $options['envPrefix'], $options['envDelimiter']);
                    $config->merge($envConfig);
                }

                // TODO: Gérer un warning log pour prévenir que l'application n'utilise pas de fichier de configuration

            } catch (ExceptionConfig $e) {
                //TODO: Gérer l'exception de configuration
            }

            return $config;
        });

        return $this;
    }

    /**
     * Importe les providers
     *
     * @return self
     */
    protected function importProviders(): self
    {
        $providerPath = implode(DIRECTORY_SEPARATOR, [$this->basePath, $this->options['servicesDefaultFile']]);

        $providerServices = new PhpConfig($providerPath);
        $providerServices->merge($this->services);

        // TODO: Gérer un warning pour prévenir que l'application n'implémente pas de service personalisés

        try {
            (new Provider($this->di))
                ->load($providerServices->toArray())
                ->register();

        } catch (Exception $e) {
            //TODO: Gérer l'exception de génération du provider
        }

        return $this;
    }

    /**
     * Enregistre les modules au sein de l'application
     *
     * @return self
     */
    protected function registerModules(): self
    {
        $registeredModules = [];
        $modulesPath = implode(DIRECTORY_SEPARATOR, [$this->basePath, $this->options['modulesDefaultPath']]);

        foreach (new DirectoryIterator($modulesPath) as $module) {
            if ($module->isDot()) continue;
            if (!$module->isDir()) continue;

            if (($strpos = strpos($module->getBasename(), $this->options['apiModulePrefix'])) !== false) {
                $moduleName = substr($module->getBasename(), $strpos + strlen($this->options['apiModulePrefix']));

                $registeredModules[strtolower($moduleName)] = [
                    'className' => 'Toroia\Modules\\' . ucfirst($moduleName) . '\Module',
                    'path' => implode(DIRECTORY_SEPARATOR, [$module->getRealPath(), 'Module.php'])
                ];
            }

            // TODO: Gérer un warning quand un dossier ne contient pas le préfix
        }
        $this->app->registerModules($registeredModules);

        return $this;
    }
}
