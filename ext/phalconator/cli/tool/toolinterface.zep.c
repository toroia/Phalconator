
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalconator\Cli\Tool\ToolInterface
 */
ZEPHIR_INIT_CLASS(Phalconator_Cli_Tool_ToolInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalconator\\Cli\\Tool, ToolInterface, phalconator, cli_tool_toolinterface, phalconator_cli_tool_toolinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Phalconator_Cli_Tool_ToolInterface, render);

