
extern zend_class_entry *phalconator_cli_text_ce;

ZEPHIR_INIT_CLASS(Phalconator_Cli_Text);

PHP_METHOD(Phalconator_Cli_Text, __construct);
PHP_METHOD(Phalconator_Cli_Text, __toString);
PHP_METHOD(Phalconator_Cli_Text, clear);
PHP_METHOD(Phalconator_Cli_Text, line);
PHP_METHOD(Phalconator_Cli_Text, colorize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_cli_text___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, data)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_cli_text_clear, 0, 0, Phalconator\\Cli\\Tool, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_cli_text_clear, 0, 0, IS_OBJECT, "Phalconator\\Cli\\Tool", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_cli_text_line, 0, 0, Phalconator\\Cli\\Tool, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_cli_text_line, 0, 0, IS_OBJECT, "Phalconator\\Cli\\Tool", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_cli_text_colorize, 0, 0, Phalconator\\Cli\\Tool, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_cli_text_colorize, 0, 0, IS_OBJECT, "Phalconator\\Cli\\Tool", 0)
#endif
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, background)
	ZEND_ARG_INFO(0, style)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_cli_text_method_entry) {
	PHP_ME(Phalconator_Cli_Text, __construct, arginfo_phalconator_cli_text___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconator_Cli_Text, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Cli_Text, clear, arginfo_phalconator_cli_text_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Cli_Text, line, arginfo_phalconator_cli_text_line, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Cli_Text, colorize, arginfo_phalconator_cli_text_colorize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
