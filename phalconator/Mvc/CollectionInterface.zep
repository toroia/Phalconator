
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
 * Phalcon\Mvc\CollectionInterface
 *
 * Interface for Phalconator\Mvc\Collection
 */
interface CollectionInterface extends \Phalcon\Mvc\CollectionInterface
{
	public function toJsonify(var callback) -> array;
}