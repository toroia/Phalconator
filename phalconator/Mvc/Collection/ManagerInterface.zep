
/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalconator\Mvc\Collection;

use Phalcon\Db\AdapterInterface;
use Phalconator\Mvc\CollectionInterface;
use Phalconator\Mvc\Collection\BehaviorInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;

/**
 * Phalconator\Mvc\Collection\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\Di.
 *
 * <code>
 * $di = new \Phalcon\Di();
 *
 * $di->set(
 *     "collectionManager",
 *     function() {
 *         return new \Phalcon\Mvc\Collection\Manager();
 *     }
 * );
 *
 * $robot = new Robots(di);
 * </code>
 */
interface ManagerInterface extends \Phalcon\Mvc\Collection\ManagerInterface
{

}
