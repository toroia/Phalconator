
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
 * Phalcon\Mvc\Collection\Behavior
 *
 * This is an optional base class for ORM behaviors
 */
abstract class Behavior implements BehaviorInterface
{
    protected options;

    /**
     * Phalcon\Mvc\Collection\Behavior
     */
    public function __construct(array options = [])
    {
        let this->options = options;
    }

    /**
     * Returns the behavior options related to an event
     *
     * @return array
     */
    protected function getOptions(string! eventName = null)
    {
        var options, eventOptions;

        let options = this->options;
        if eventName !== null {
            if fetch eventOptions, options[eventName] {
                return eventOptions;
            }
            return null;
        }
        return options;
    }

    /**
     * Acts as fallbacks when a missing method is called on the collection
     */
    public function missingMethod(<CollectionInterface> model, string method, array arguments = [])
    {
        return null;
    }

    /**
     * Checks whether the behavior must take action on certain event
     */
    protected function mustTakeAction(string! eventName) -> bool
    {
        return isset this->options[eventName];
    }

    /**
     * This method receives the notifications from the EventsManager
     */
    public function notify(string type, <CollectionInterface> model)
    {
        return null;
    }
}
