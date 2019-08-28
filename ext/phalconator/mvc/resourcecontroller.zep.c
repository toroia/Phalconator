
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalconator_Mvc_ResourceController) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator\\Mvc, ResourceController, phalconator, mvc_resourcecontroller, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalconator_mvc_resourcecontroller_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/** @var \Phalcon\Domain\Payload\PayloadFactory payload */
	zend_declare_property_null(phalconator_mvc_resourcecontroller_ce, SL("payload"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconator_mvc_resourcecontroller_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("phalcon\\mvc\\controllerinterface")));
	return SUCCESS;

}

/**
 * Phalconator\Mvc\ResourceController constructor
 */
PHP_METHOD(Phalconator_Mvc_ResourceController, __construct) {

	zval _0, _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();

	if ((zephir_method_exists_ex(this_ptr, SL("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("payload"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, zephir_get_internal_ce(SL("phalcon\\domain\\payload\\payloadfactory")));
		if (zephir_has_constructor(&_1$$4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("payload"), &_1$$4);
	}
	ZEPHIR_MM_RESTORE();

}

