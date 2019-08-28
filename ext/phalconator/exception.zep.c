
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
 * This file is part of the Phalconator extension for Phalcon Framework.
 *
 * Copyright (C) Toroia Team <contact@toroia.fr>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalconator\Exception
 *
 * All librarie exceptions should use or extend this exception
 */
ZEPHIR_INIT_CLASS(Phalconator_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Phalconator, Exception, phalconator, exception, zephir_get_internal_ce(SL("phalcon\\exception")), NULL, 0);

	return SUCCESS;

}

