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

/**
 * Phalconator\Mvc\ControllerScrudInterface
 *
 * Interface for controller scrud handlers
 */
interface ControllerScrudInterface
{
    /**
     * @return array
     */
    public function searchAction(): array;

    /**
     * @return array
     */
    public function createAction(): array;

    /**
     * @return array
     */
    public function readAction(): array;

    /**
     * @return array
     */
    public function updateAction(): array;

    /**
     * @return array
     */
    public function deleteAction(): array;
}
