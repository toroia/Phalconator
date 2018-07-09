
extern zend_class_entry *phalconator_cli_text_ce;

ZEPHIR_INIT_CLASS(Phalconator_Cli_Text);

PHP_METHOD(Phalconator_Cli_Text, __construct);
PHP_METHOD(Phalconator_Cli_Text, __toString);
PHP_METHOD(Phalconator_Cli_Text, clear);
PHP_METHOD(Phalconator_Cli_Text, line);
PHP_METHOD(Phalconator_Cli_Text, colorize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_cli_text___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_cli_text_colorize, 0, 0, 0)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, background)
	ZEND_ARG_INFO(0, style)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_cli_text_method_entry) {
	PHP_ME(Phalconator_Cli_Text, __construct, arginfo_phalconator_cli_text___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconator_Cli_Text, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Cli_Text, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Cli_Text, line, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Cli_Text, colorize, arginfo_phalconator_cli_text_colorize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
