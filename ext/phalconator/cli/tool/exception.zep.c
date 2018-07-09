
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


/**
 * Phalconator\Cli\Tool\Exception
 *
 * Exceptions thrown in Phalcon\Cli\Tool\* classes will use this class
 *
 */
ZEPHIR_INIT_CLASS(Phalconator_Cli_Tool_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator\\Cli\\Tool, Exception, phalconator, cli_tool_exception, phalconator_exception_ce, NULL, 0);

	return SUCCESS;

}

