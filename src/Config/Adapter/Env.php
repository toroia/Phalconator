<?php declare(strict_types=1);

/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator\Config\Adapter;

use Phalcon\Config;
use Phalcon\Config\Exception;

/**
 * Class Env
 *
 * @package Phalconator\Config\Adapter
 */
class Env extends Config
{
    const DEFAULT_DELIMITER = '_';

    /**
     * Env constructor.
     *
     * @param string|null $filePath
     * @param string|null $prefix
     * @param string|null $delimiter
     * @throws Exception
     */
    public function __construct(?string $filePath, ?string $prefix, ?string $delimiter)
    {
        if (empty($delimiter)) {
            $delimiter = self::DEFAULT_DELIMITER;
        }

        $envConfig = $this->parseEnvConfig($prefix, $delimiter);

        if (!is_null($filePath)) {
            $envFile = $this->parseEnvFile($filePath, $prefix, $delimiter);

            if ($envFile === false) {
                throw new Exception("Configuration file " . basename($filePath) . " can't be loaded");
            }
        }

        $config = array_merge($envConfig, $envFile ?? []);

        parent::__construct($config);
    }

    private function parseEnvConfig($prefix, $delimiter)
    {
        $config = [];

        foreach (getenv() as $key => $value) {
            if (strpos($key, $prefix) !== false) {
                $key = str_replace($prefix, '', $key);
                $keys = explode($delimiter, $key);

                $value = $this->assignValueType($value);

                $this->assignArrayKeys($config, $keys, $value);
            }
        }

        return $config;
    }

    /**
     * Envfile parser
     *
     * @param string $filePath
     * @param string $prefix
     * @param null|string $delimiter
     * @return array|bool
     */
    private function parseEnvFile(string $filePath, string $prefix, ?string $delimiter)
    {
        if ($content = file_get_contents($filePath)) {
            $config = [];
            $lines = explode(PHP_EOL, $content);
            $re = '/^(?:' . $prefix . ')\s*([\w\.\-]+)\s*=\s*(.*)?\s*$/';

            foreach ($lines as $line) {
                if (preg_match($re, $line, $keysValue)) {
                    $keys = explode($delimiter, $keysValue[1]);
                    $value = $keysValue[2] ?? null;
                    $length = strlen($value) ?? 0;

                    if ($length > 0 && strpos($value, '"') === 0 && substr($value, -1) === '"') {
                        $value = preg_replace('/\\n/gm', "\n", $value);
                    }

                    $value = trim(preg_replace('/(^[\'"]|[\'"]$)/', '', $value));

                    $value = $this->assignValueType($value);

                    $this->assignArrayKeys($config, $keys, $value);
                }
            }

            return $config;
        }

        return false;
    }

    /**
     * Assigne une chaine à son type respectif
     *
     * @param string|null $value
     * @return mixed
     */
    private function assignValueType(?string $value)
    {
        switch (true) {
            // Integer
            case ctype_digit($value):
                return intval($value);

            // Float
            case !ctype_digit($value) && is_numeric($value):
                return floatval($value);

            // Boolean
            case $value == "true":
                return true;
            case $value == "false":
                return false;

            // Null
            case $value == "null":
            case empty($value):
                return null;

            // String
            default:
                return $value;
        }
    }

    /**
     * Assigne en cascade un tableau clé/valeurs
     *
     * @param array $arr
     * @param array $keys
     * @param mixed $value
     */
    private function assignArrayKeys(array &$arr, array $keys, $value)
    {
        foreach ($keys as $key) {
            $arr = &$arr[strtolower($key)];
        }

        $arr = $value;
    }
}
