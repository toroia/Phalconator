
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of collections, keeping record of relations
 * between the different collections of the application.
 *
 * A CollectionManager is injected to a collection via a Dependency Injector Container such as Phalcon\Di.
 *
 * ```php
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
 * ```
 */
ZEPHIR_INIT_CLASS(Phalconator_Mvc_Collection_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconator\\Mvc\\Collection, ManagerInterface, phalconator, mvc_collection_managerinterface, phalconator_mvc_collection_managerinterface_method_entry);

	return SUCCESS;

}

/**
 * Binds a behavior to a collection
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, addBehavior);

/**
 * Returns the connection related to a collection
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, getConnection);

/**
 * Returns a custom events manager related to a collection
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, getCustomEventsManager);

/**
 * Get the latest initialized collection
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, getLastInitialized);

/**
 * Initializes a collection in the collections manager
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, initialize);

/**
 * Check whether a collection is already initialized
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, isInitialized);

/**
 * Checks if a collection is using implicit object ids
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, isUsingImplicitObjectIds);

/**
 * Receives events generated in the collections and dispatches them to an events-manager if available
 * Notify the behaviors that are listening in the collection
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, notifyEvent);

/**
 * Sets a custom events manager for a specific collection
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, setCustomEventsManager);

/**
 * Sets a connection service for a specific collection
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, setConnectionService);

/**
 * Sets if a collection must use implicit objects ids
 */
ZEPHIR_DOC_METHOD(Phalconator_Mvc_Collection_ManagerInterface, useImplicitObjectIds);

