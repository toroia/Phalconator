
extern zend_class_entry *phalconator_validation_validator_password_ce;

ZEPHIR_INIT_CLASS(Phalconator_Validation_Validator_Password);

PHP_METHOD(Phalconator_Validation_Validator_Password, validate);
PHP_METHOD(Phalconator_Validation_Validator_Password, scoreCalculator);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_validation_validator_password_validate, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_validation_validator_password_validate, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_validation_validator_password_scorecalculator, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_validation_validator_password_scorecalculator, 0, 1, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_validation_validator_password_method_entry) {
	PHP_ME(Phalconator_Validation_Validator_Password, validate, arginfo_phalconator_validation_validator_password_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Validation_Validator_Password, scoreCalculator, arginfo_phalconator_validation_validator_password_scorecalculator, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
