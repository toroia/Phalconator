
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


ZEPHIR_INIT_CLASS(Phalconator_Mvc_Collection) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator\\Mvc, Collection, phalconator, mvc_collection, zephir_get_internal_ce(SL("phalcon\\mvc\\collection")), NULL, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

