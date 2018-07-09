
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
 * Phalconator\Cli\Text\Menu
 *
 * The class menu cli lines
 */
ZEPHIR_INIT_CLASS(Phalconator_Cli_Text_Menu) {

	ZEPHIR_REGISTER_CLASS(Phalconator\\Cli\\Text, Menu, phalconator, cli_text_menu, NULL, 0);

	return SUCCESS;

}

