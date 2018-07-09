
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * Phalconator\Exception
 *
 * All librarie exceptions should use or extend this exception
 */
ZEPHIR_INIT_CLASS(Phalconator_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator, Exception, phalconator, exception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	return SUCCESS;

}

