
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Collection\Behavior\SoftDelete
 *
 * Instead of permanently delete a record it marks the record as
 * deleted changing the value of a flag column
 */
ZEPHIR_INIT_CLASS(Phalconator_Mvc_Collection_Behavior_SoftDelete) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator\\Mvc\\Collection\\Behavior, SoftDelete, phalconator, mvc_collection_behavior_softdelete, phalconator_mvc_collection_behavior_ce, phalconator_mvc_collection_behavior_softdelete_method_entry, 0);

	return SUCCESS;

}

/**
 * Listens for notifications from the models manager
 */
PHP_METHOD(Phalconator_Mvc_Collection_Behavior_SoftDelete, notify) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *model, model_sub, options, value, field, updateModel, message, _0, _1, _2, _3$$7, *_4$$7, _5$$7;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&updateModel);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_5$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &model);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	if (!ZEPHIR_IS_STRING_IDENTICAL(&type, "beforeDelete")) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&options, this_ptr, "getoptions", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&value);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&value, &options, SL("value"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconator_mvc_collection_exception_ce, "The option 'value' is required", "phalconator/Mvc/Collection/Behavior/SoftDelete.zep", 42);
		return;
	}
	ZEPHIR_OBS_VAR(&field);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&field, &options, SL("field"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconator_mvc_collection_exception_ce, "The option 'field' is required", "phalconator/Mvc/Collection/Behavior/SoftDelete.zep", 49);
		return;
	}
	ZVAL_BOOL(&_0, 1);
	ZEPHIR_CALL_METHOD(NULL, model, "skipoperation", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, model, "readattribute", NULL, 0, &field);
	zephir_check_call_status();
	if (ZEPHIR_IS_EQUAL(&_1, &value)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&updateModel);
	if (zephir_clone(&updateModel, model TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &updateModel, "writeattribute", NULL, 0, &field, &value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &updateModel, "save", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_CALL_METHOD(&_3$$7, &updateModel, "getmessages", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_3$$7, 0, "phalconator/Mvc/Collection/Behavior/SoftDelete.zep", 82);
		if (Z_TYPE_P(&_3$$7) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3$$7), _4$$7)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _4$$7);
				ZEPHIR_CALL_METHOD(NULL, model, "appendmessage", &_6, 0, &message);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_3$$7, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$7, &_3$$7, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$7)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, &_3$$7, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, model, "appendmessage", &_7, 0, &message);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_3$$7, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", NULL, 0, &field, &value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}
