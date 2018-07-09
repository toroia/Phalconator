
extern zend_class_entry *phalconator_cli_tool_ce;

ZEPHIR_INIT_CLASS(Phalconator_Cli_Tool);

PHP_METHOD(Phalconator_Cli_Tool, __construct);
PHP_METHOD(Phalconator_Cli_Tool, __toString);
PHP_METHOD(Phalconator_Cli_Tool, clear);
PHP_METHOD(Phalconator_Cli_Tool, line);
PHP_METHOD(Phalconator_Cli_Tool, colorize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_cli_tool___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, d)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_cli_tool_colorize, 0, 0, 0)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, background)
	ZEND_ARG_INFO(0, style)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_cli_tool_method_entry) {
	PHP_ME(Phalconator_Cli_Tool, __construct, arginfo_phalconator_cli_tool___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalconator_Cli_Tool, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Cli_Tool, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Cli_Tool, line, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Cli_Tool, colorize, arginfo_phalconator_cli_tool_colorize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
