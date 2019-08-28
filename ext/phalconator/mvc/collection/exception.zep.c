
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
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Collection\Exception
 *
 * Exceptions thrown in Phalcon\Mvc\Collection\* classes will use this class
 *
 */
ZEPHIR_INIT_CLASS(Phalconator_Mvc_Collection_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator\\Mvc\\Collection, Exception, phalconator, mvc_collection_exception, phalconator_exception_ce, NULL, 0);

	return SUCCESS;

}

