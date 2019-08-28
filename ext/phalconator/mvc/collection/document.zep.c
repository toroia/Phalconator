
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
#include "ext/spl/spl_iterators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Collection\Document
 *
 * This component allows Phalcon\Mvc\Collection to return rows without an associated entity.
 * This objects implements the ArrayAccess interface to allow access the object as object->x or array[x].
 */
ZEPHIR_INIT_CLASS(Phalconator_Mvc_Collection_Document) {

	ZEPHIR_REGISTER_CLASS(Phalconator\\Mvc\\Collection, Document, phalconator, mvc_collection_document, phalconator_mvc_collection_document_method_entry, 0);

	zend_class_implements(phalconator_mvc_collection_document_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("phalcon\\mvc\\entityinterface")));
	zend_class_implements(phalconator_mvc_collection_document_ce TSRMLS_CC, 1, phalconator_mvc_collection_documentinterface_ce);
	zend_class_implements(phalconator_mvc_collection_document_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalconator_mvc_collection_document_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Collection\Document constructor
 */
PHP_METHOD(Phalconator_Mvc_Collection_Document, __construct) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, key, value, *_0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	}


	zephir_is_iterable(&data, 0, "phalconator/Mvc/Collection/Document.zep", 35);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "writeattribute", &_4, 0, &key, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "writeattribute", &_4, 0, &key, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the count of properties set in the document
 */
PHP_METHOD(Phalconator_Mvc_Collection_Document, count) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 7, this_ptr);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * Returns the value of a field using the ArrayAccess interfase
 */
PHP_METHOD(Phalconator_Mvc_Collection_Document, offsetGet) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index, index_sub, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_OBS_VAR(&value);
	if (UNEXPECTED(!(zephir_fetch_property_zval(&value, this_ptr, index, PH_SILENT_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconator_mvc_collection_exception_ce, "The index does not exist in the row", "phalconator/Mvc/Collection/Document.zep", 55);
		return;
	}
	RETURN_CCTOR(&value);

}

/**
 * Checks whether an offset exists in the document
 */
PHP_METHOD(Phalconator_Mvc_Collection_Document, offsetExists) {

	zval *index, index_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &index);



	RETURN_BOOL(zephir_isset_property_zval(this_ptr, index TSRMLS_CC));

}

/**
 * Change a value using the ArrayAccess interface
 */
PHP_METHOD(Phalconator_Mvc_Collection_Document, offsetSet) {

	zval *index, index_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&value_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &index, &value);



	zephir_update_property_zval_zval(this_ptr, index, value TSRMLS_CC);

}

/**
 * Rows cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
 */
PHP_METHOD(Phalconator_Mvc_Collection_Document, offsetUnset) {

	zval *index, index_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &index);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalconator_mvc_collection_exception_ce, "The index does not exist in the row", "phalconator/Mvc/Collection/Document.zep", 82);
	return;

}

/**
 * Reads an attribute value by its name
 *
 *```php
 *  echo $robot->readAttribute("name");
 *```
 */
PHP_METHOD(Phalconator_Mvc_Collection_Document, readAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, value;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(&attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(&attribute);
		ZVAL_EMPTY_STRING(&attribute);
	}


	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_fetch_property_zval(&value, this_ptr, &attribute, PH_SILENT_CC))) {
		RETURN_MM_NULL();
	}
	RETURN_CTOR(&value);

}

/**
 * Returns the instance as an array representation
 */
PHP_METHOD(Phalconator_Mvc_Collection_Document, toArray) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 7, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Writes an attribute value by its name
 *
 *```php
 *  $robot->writeAttribute("name", "Rosey");
 *```
 */
PHP_METHOD(Phalconator_Mvc_Collection_Document, writeAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, *value, value_sub;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(&attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(&attribute);
		ZVAL_EMPTY_STRING(&attribute);
	}


	zephir_update_property_zval_zval(this_ptr, &attribute, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

