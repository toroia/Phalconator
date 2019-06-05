
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalconator\Validation\Validator\Password
 *
 * Checks if the provided password is strong enough
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalconator\Validation\Validator\Password as PasswordValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "password",
 *     new PasswordValidator(
 *         [
 *             "message" => "The password is not strong enought",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "password",
 *         "anotherPassword",
 *     ],
 *     new PasswordValidator(
 *         [
 *             "message" => [
 *                 "password"        => "The password is not strong enought",
 *                 "anotherPassword" => "The another password is not strong enought",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalconator_Validation_Validator_Password) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator\\Validation\\Validator, Password, phalconator, validation_validator_password, zephir_get_internal_ce(SL("phalcon\\validation\\validator")), phalconator_validation_validator_password_method_entry, 0);

	zephir_declare_class_constant_long(phalconator_validation_validator_password_ce, SL("MIN_VALID_SCORE"), 2);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalconator_Validation_Validator_Password, validate) {

	zend_class_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, password, allowEmpty, minScore, passwordScore, label, message, code, replacePairs, _0, _1, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&allowEmpty);
	ZVAL_UNDEF(&minScore);
	ZVAL_UNDEF(&passwordScore);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&field);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}


	ZEPHIR_CALL_METHOD(&password, validation, "getvalue", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "allowEmpty");
	ZEPHIR_CALL_METHOD(&allowEmpty, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (((int) (zephir_get_numberval(&allowEmpty)) & ((((zephir_is_scalar(&password) & ZEPHIR_IS_STRING_IDENTICAL(&password, ""))) | Z_TYPE_P(&password) == IS_NULL)))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "minScore");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "minScore");
		ZEPHIR_CALL_METHOD(&minScore, this_ptr, "getoption", NULL, 0, &_0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&minScore);
		ZVAL_LONG(&minScore, 2);
	}
	ZEPHIR_CALL_METHOD(&passwordScore, this_ptr, "scorecalculator", NULL, 15, &password);
	zephir_check_call_status();
	if ((Z_TYPE_P(&password) == IS_STRING & ZEPHIR_GE(&passwordScore, &minScore))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Password");
	ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, &field, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&replacePairs);
	zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	if (!_2) {
	_2 = zephir_fetch_class_str_ex(SL("Phalcon\\Validation\\Message"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_0, _2);
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 16, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "Password");
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_3, &field, &_4, &code);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(0);

}

/**
 * Function used to calculate the score of a provided password
 * The higher the score, the stronger the password and vice versa
 * @param  string password
 * @return int
 */
PHP_METHOD(Phalconator_Validation_Validator_Password, scoreCalculator) {

	zend_long ZEPHIR_LAST_CALL_STATUS, score = 0;
	zval *password, password_sub, hasLower, hasUpper, hasNumber, passwordLength, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password_sub);
	ZVAL_UNDEF(&hasLower);
	ZVAL_UNDEF(&hasUpper);
	ZVAL_UNDEF(&hasNumber);
	ZVAL_UNDEF(&passwordLength);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &password);



	score = 0;
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "![a-z]!");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "![a-z]!");
	ZEPHIR_INIT_VAR(&hasLower);
	zephir_preg_match(&hasLower, &_2, password, &_0, 0, 0 , 0  TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "![A-Z]!");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "![A-Z]!");
	ZEPHIR_INIT_VAR(&hasUpper);
	zephir_preg_match(&hasUpper, &_5, password, &_3, 0, 0 , 0  TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "![0-9]!");
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "![0-9]!");
	ZEPHIR_INIT_VAR(&hasNumber);
	zephir_preg_match(&hasNumber, &_8, password, &_6, 0, 0 , 0  TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_9);
	zephir_bitwise_and_function(&_9, &hasLower, &hasUpper TSRMLS_CC);
	if (zephir_is_true(&_9)) {
		score++;
	}
	ZEPHIR_INIT_VAR(&_10);
	zephir_bitwise_and_function(&_10, &hasNumber, &hasLower TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_11);
	zephir_bitwise_and_function(&_11, &hasNumber, &hasUpper TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_12);
	zephir_bitwise_or_function(&_12, &_10, &_11 TSRMLS_CC);
	if (zephir_is_true(&_12)) {
		score++;
	}
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "![^0-9a-zA-Z]!");
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_INIT_VAR(&_16);
	ZVAL_STRING(&_16, "![^0-9a-zA-Z]!");
	zephir_preg_match(&_15, &_16, password, &_13, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_15)) {
		score++;
	}
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_INIT_VAR(&_18);
	ZVAL_STRING(&_18, "![^\\w\\s]!");
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_STRING(&_20, "![^\\w\\s]!");
	zephir_preg_match(&_19, &_20, password, &_17, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_19)) {
		score++;
	}
	ZEPHIR_CALL_FUNCTION(&passwordLength, "mb_strlen", NULL, 17, password);
	zephir_check_call_status();
	if (ZEPHIR_GE_LONG(&passwordLength, 16)) {
		score += 2;
	} else if (ZEPHIR_GE_LONG(&passwordLength, 8)) {
		score++;
	} else if (ZEPHIR_LE_LONG(&passwordLength, (4 & score > 1))) {
		score--;
	} else if (ZEPHIR_GT_LONG(&passwordLength, (0 & score == 0))) {
		score++;
	}
	RETURN_MM_LONG(score);

}

