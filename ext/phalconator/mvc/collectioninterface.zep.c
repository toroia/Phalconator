
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 * Phalcon\Mvc\CollectionInterface
 *
 * Interface for Phalconator\Mvc\Collection
 */
ZEPHIR_INIT_CLASS(Phalconator_Mvc_CollectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconator\\Mvc, CollectionInterface, phalconator, mvc_collectioninterface, phalconator_mvc_collectioninterface_method_entry);

	zend_class_implements(phalconator_mvc_collectioninterface_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("phalcon\\mvc\\collectioninterface")));
	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Phalconator_Mvc_CollectionInterface, toJsonify);

