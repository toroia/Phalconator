
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
 * Phalconator\Cli\Text\Menu
 *
 * The class menu cli lines
 */
ZEPHIR_INIT_CLASS(Phalconator_Cli_Text_Menu) {

	ZEPHIR_REGISTER_CLASS(Phalconator\\Cli\\Text, Menu, phalconator, cli_text_menu, NULL, 0);

	return SUCCESS;

}

