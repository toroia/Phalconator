
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Phalconator\Cli\Exception
 *
 * Exceptions thrown in Phalcon\Cli\* classes will use this class
 *
 */
ZEPHIR_INIT_CLASS(Phalconator_Cli_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator\\Cli, Exception, phalconator, cli_exception, phalconator_exception_ce, NULL, 0);

	return SUCCESS;

}

