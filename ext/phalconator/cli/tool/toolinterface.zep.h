
extern zend_class_entry *phalconator_cli_tool_toolinterface_ce;

ZEPHIR_INIT_CLASS(Phalconator_Cli_Tool_ToolInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_cli_tool_toolinterface_render, 0, 0, 1)
	ZEND_ARG_INFO(0, d)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_cli_tool_toolinterface_method_entry) {
	ZEND_FENTRY(render, NULL, arginfo_phalconator_cli_tool_toolinterface_render, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
