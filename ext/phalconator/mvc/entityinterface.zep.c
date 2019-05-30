
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
 * Phalconator\Mvc\EntityInterface
 *
 * Interface for Phalcon\Mvc\Collection and Phalcon\Mvc\Model
 */
ZEPHIR_INIT_CLASS(Phalconator_Mvc_EntityInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconator\\Mvc, EntityInterface, phalconator, mvc_entityinterface, NULL);

	zend_class_implements(phalconator_mvc_entityinterface_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("phalcon\\mvc\\entityinterface")));
	return SUCCESS;

}

