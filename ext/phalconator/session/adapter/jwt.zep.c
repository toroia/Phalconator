
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class Jwt
 *
 * @package Phalconator\Session\Adapter
 * @doc https://github.com/byjg/jwt-session/blob/master/src/JwtSession.php
 */
ZEPHIR_INIT_CLASS(Phalconator_Session_Adapter_Jwt) {

	ZEPHIR_REGISTER_CLASS(Phalconator\\Session\\Adapter, Jwt, phalconator, session_adapter_jwt, phalconator_session_adapter_jwt_method_entry, 0);

	zend_class_implements(phalconator_session_adapter_jwt_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	return SUCCESS;

}

PHP_METHOD(Phalconator_Session_Adapter_Jwt, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

PHP_METHOD(Phalconator_Session_Adapter_Jwt, destroy) {

	zval *id, id_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &id);



	RETURN_BOOL(1);

}

PHP_METHOD(Phalconator_Session_Adapter_Jwt, gc) {

	zval *maxlifetime, maxlifetime_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &maxlifetime);



	RETURN_BOOL(1);

}

PHP_METHOD(Phalconator_Session_Adapter_Jwt, read) {

	zval *id, id_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &id);



	RETURN_STRING("");

}

PHP_METHOD(Phalconator_Session_Adapter_Jwt, open) {

	zval *savePath, savePath_sub, *sessionName, sessionName_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &savePath, &sessionName);



	RETURN_BOOL(1);

}

PHP_METHOD(Phalconator_Session_Adapter_Jwt, write) {

	zval *id, id_sub, *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &id, &data);



	RETURN_BOOL(1);

}

