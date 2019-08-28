
/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator\Mvc\Collection;

use Phalconator\Mvc\CollectionInterface;

/**
 * Phalcon\Mvc\Collection\BehaviorInterface
 *
 * Interface for Phalcon\Mvc\Collection\Behavior
 */
interface BehaviorInterface
{
    /**
     * Calls a method when it's missing in the collection
     */
    public function missingMethod(<CollectionInterface> collection, string !method, array arguments = []);

    /**
     * This method receives the notifications from the EventsManager
     */
    public function notify(string! type, <CollectionInterface> collection);
}
