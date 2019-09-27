
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalconator_Mvc_ResourceController) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator\\Mvc, ResourceController, phalconator, mvc_resourcecontroller, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalconator_mvc_resourcecontroller_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("phalcon\\mvc\\controllerinterface")));
	return SUCCESS;

}

