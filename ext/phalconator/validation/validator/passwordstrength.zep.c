
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
#include "kernel/object.h"
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
ZEPHIR_INIT_CLASS(Phalconator_Validation_Validator_PasswordStrength) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator\\Validation\\Validator, PasswordStrength, phalconator, validation_validator_passwordstrength, zephir_get_internal_ce(SL("phalcon\\validation\\abstractvalidator")), phalconator_validation_validator_passwordstrength_method_entry, 0);

	zend_declare_property_string(phalconator_validation_validator_passwordstrength_ce, SL("template"), "Field :field does not have a high enough score", ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_long(phalconator_validation_validator_passwordstrength_ce, SL("MIN_VALID_SCORE"), 2);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalconator_Validation_Validator_PasswordStrength, validate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, password, allowEmpty, minScore, passwordScore, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&allowEmpty);
	ZVAL_UNDEF(&minScore);
	ZVAL_UNDEF(&passwordScore);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&password, validation, "getvalue", NULL, 0, field);
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
	ZEPHIR_CALL_METHOD(&passwordScore, this_ptr, "scorecalculator", NULL, 11, &password);
	zephir_check_call_status();
	if ((Z_TYPE_P(&password) == IS_STRING & ZEPHIR_GE(&passwordScore, &minScore))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "messagefactory", NULL, 0, validation, field);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(0);

}

/**
 * Function used to calculate the score of a provided password
 * The higher the score, the stronger the password and vice versa
 * @param  string password
 * @return int
 */
PHP_METHOD(Phalconator_Validation_Validator_PasswordStrength, scoreCalculator) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEPHIR_CALL_FUNCTION(&passwordLength, "mb_strlen", NULL, 12, password);
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

