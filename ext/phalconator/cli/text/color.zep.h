
extern zend_class_entry *phalconator_cli_text_color_ce;

ZEPHIR_INIT_CLASS(Phalconator_Cli_Text_Color);

PHP_METHOD(Phalconator_Cli_Text_Color, __construct);
PHP_METHOD(Phalconator_Cli_Text_Color, render);
PHP_METHOD(Phalconator_Cli_Text_Color, clear);
PHP_METHOD(Phalconator_Cli_Text_Color, _concat);
void zephir_init_static_properties_Phalconator_Cli_Text_Color(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_cli_text_color_render, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, background)
	ZEND_ARG_INFO(0, style)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_cli_text_color_clear, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_cli_text_color__concat, 0, 0, 0)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, background)
	ZEND_ARG_INFO(0, style)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_cli_text_color_method_entry) {
	PHP_ME(Phalconator_Cli_Text_Color, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Phalconator_Cli_Text_Color, render, arginfo_phalconator_cli_text_color_render, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Cli_Text_Color, clear, arginfo_phalconator_cli_text_color_clear, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Cli_Text_Color, _concat, arginfo_phalconator_cli_text_color__concat, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
