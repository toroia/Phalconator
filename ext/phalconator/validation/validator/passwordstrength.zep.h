
extern zend_class_entry *phalconator_validation_validator_passwordstrength_ce;

ZEPHIR_INIT_CLASS(Phalconator_Validation_Validator_PasswordStrength);

PHP_METHOD(Phalconator_Validation_Validator_PasswordStrength, validate);
PHP_METHOD(Phalconator_Validation_Validator_PasswordStrength, scoreCalculator);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_validation_validator_passwordstrength_validate, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_validation_validator_passwordstrength_validate, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_validation_validator_passwordstrength_scorecalculator, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_validation_validator_passwordstrength_scorecalculator, 0, 1, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_validation_validator_passwordstrength_method_entry) {
	PHP_ME(Phalconator_Validation_Validator_PasswordStrength, validate, arginfo_phalconator_validation_validator_passwordstrength_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Validation_Validator_PasswordStrength, scoreCalculator, arginfo_phalconator_validation_validator_passwordstrength_scorecalculator, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
