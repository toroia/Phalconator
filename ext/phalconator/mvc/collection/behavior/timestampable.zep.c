
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "Zend/zend_closures.h"
#include "kernel/object.h"
#include "kernel/time.h"
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
 * Phalcon\Mvc\Collection\Behavior\Timestampable
 *
 * Allows to automatically update a model’s attribute saving the
 * datetime when a record is created or updated
 */
ZEPHIR_INIT_CLASS(Phalconator_Mvc_Collection_Behavior_Timestampable) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator\\Mvc\\Collection\\Behavior, Timestampable, phalconator, mvc_collection_behavior_timestampable, phalconator_mvc_collection_behavior_ce, phalconator_mvc_collection_behavior_timestampable_method_entry, 0);

	return SUCCESS;

}

/**
 * Listens for notifications from the models manager
 */
PHP_METHOD(Phalconator_Mvc_Collection_Behavior_Timestampable, notify) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *model, model_sub, options, timestamp, singleField, field, generator, format, _0, *_1$$12, _2$$12;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&timestamp);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&generator);
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$12);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "musttakeaction", NULL, 0, &type);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&options, this_ptr, "getoptions", NULL, 0, &type);
	zephir_check_call_status();
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&field);
		if (UNEXPECTED(!(zephir_array_isset_string_fetch(&field, &options, SL("field"), 0)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconator_mvc_collection_exception_ce, "The option 'field' is required", "phalconator/Mvc/Collection/Behavior/Timestampable.zep", 47);
			return;
		}
		ZEPHIR_INIT_VAR(&timestamp);
		ZVAL_NULL(&timestamp);
		ZEPHIR_OBS_VAR(&format);
		if (zephir_array_isset_string_fetch(&format, &options, SL("format"), 0)) {
			ZEPHIR_CALL_FUNCTION(&timestamp, "date", NULL, 9, &format);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_VAR(&generator);
			if (zephir_array_isset_string_fetch(&generator, &options, SL("generator"), 0)) {
				if (Z_TYPE_P(&generator) == IS_OBJECT) {
					if (zephir_instance_of_ev(&generator, zend_ce_closure TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(&timestamp);
						ZEPHIR_CALL_USER_FUNC(&timestamp, &generator);
						zephir_check_call_status();
					}
				}
			}
		}
		if (Z_TYPE_P(&timestamp) == IS_NULL) {
			ZEPHIR_INIT_NVAR(&timestamp);
			zephir_time(&timestamp);
		}
		if (Z_TYPE_P(&field) == IS_ARRAY) {
			zephir_is_iterable(&field, 0, "phalconator/Mvc/Collection/Behavior/Timestampable.zep", 85);
			if (Z_TYPE_P(&field) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&field), _1$$12)
				{
					ZEPHIR_INIT_NVAR(&singleField);
					ZVAL_COPY(&singleField, _1$$12);
					ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", &_3, 0, &singleField, &timestamp);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &field, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$12, &field, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$12)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&singleField, &field, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", &_4, 0, &singleField, &timestamp);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &field, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&singleField);
		} else {
			ZEPHIR_CALL_METHOD(NULL, model, "writeattribute", NULL, 0, &field, &timestamp);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}
