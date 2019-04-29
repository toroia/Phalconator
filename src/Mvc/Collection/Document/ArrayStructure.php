<?php declare(strict_types=1);

/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator\Mvc\Collection\Document;

use ArrayAccess;
use Countable;
use function strval;

/**
 * Class ArrayStructure
 *
 * @package Phalconator\Mvc\Collection\Document
 */
abstract class ArrayStructure implements ArrayAccess, Countable
{
    /**
     * ArrayStructure constructor.
     *
     * @param array|null $array
     */
    public function __construct(?array $array = null)
    {
        foreach ($array as $key => $value) {
            $this->offsetSet($key, $value);
        }
    }

    /**
     * Restore l'état d'une structure de tableau pour un document
     *
     * @param array|null $array
     * @return ArrayStructure
     */
    public static function __set_state(?array $array): ArrayStructure
    {
        $calledClass = get_called_class();

        return new $calledClass($array);
    }

    /**
     * Recherche et retourne le contenu d'un enregistrement, si celui-ci existe pas, renvoie null
     * Si la valeur n'est pas définie, la valeur par défaut sera retournée
     *
     * @param string|int $index
     * @param mixed|null $defaultValue
     * @return mixed|null
     */
    public function get($index, $defaultValue = null)
    {
        $index = strval($index);

        if (isset($this->$index)) {
            return $this->$index;
        }

        return $defaultValue;
    }

    /**
     * Convertit récursivement les structures de tableaux en tableaux
     *
     * @return array
     */
    public function toArray(): array
    {
        $array = [];
        foreach (get_object_vars($this) as $key => $value) {
            if (is_object($value)) {
                if (method_exists($value, "toArray")) {
                    $array[$key] = $value->toArray();
                } else {
                    $array[$key] = $value;
                }
            } else {
                $array[$key] = $value;
            }
        }

        return $array;
    }

    /**
     * Vérifie si un enregistrement existe
     *
     * @param string|int $index
     * @return bool
     */
    public function offsetExists($index): bool
    {
        $index = strval($index);

        return isset($this->$index);
    }

    /**
     * Récupère et retourne la valeur d'un enregistrement
     *
     * @param string|int $index
     * @return mixed
     */
    public function offsetGet($index)
    {
        $index = strval($index);

        return $this->$index;
    }

    /**
     * Créée un nouvel enregistrement dans la structure
     *
     * @param string|int $index
     * @param mixed $value
     */
    public function offsetSet($index, $value): void
    {
        $index = strval($index);
        $calledClass = get_called_class();

        if (is_array($value)) {
            $this->$index = new $calledClass($value);
        } else {
            $this->$index = $value;
        }
    }

    /**
     * Vide le contenu d'un enregistrement
     *
     * @param string|int $index
     */
    public function offsetUnset($index): void
    {
        $index = strval($index);

        $this->$index = null;
    }

    /**
     * Compte et retourne le nombre d'enregistrements
     *
     * @return int
     */
    public function count(): int
    {
        return count(get_object_vars($this));
    }
}
