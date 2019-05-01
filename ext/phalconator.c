
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "phalconator.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *phalconator_mvc_collectioninterface_ce;
zend_class_entry *phalconator_mvc_entityinterface_ce;
zend_class_entry *phalconator_mvc_collection_managerinterface_ce;
zend_class_entry *phalconator_exception_ce;
zend_class_entry *phalconator_cli_exception_ce;
zend_class_entry *phalconator_cli_text_ce;
zend_class_entry *phalconator_cli_text_color_ce;
zend_class_entry *phalconator_cli_text_menu_ce;
zend_class_entry *phalconator_mvc_collection_ce;
zend_class_entry *phalconator_mvc_collection_exception_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalconator)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(phalconator)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Phalconator_Mvc_CollectionInterface);
	ZEPHIR_INIT(Phalconator_Mvc_EntityInterface);
	ZEPHIR_INIT(Phalconator_Mvc_Collection_ManagerInterface);
	ZEPHIR_INIT(Phalconator_Exception);
	ZEPHIR_INIT(Phalconator_Cli_Exception);
	ZEPHIR_INIT(Phalconator_Cli_Text);
	ZEPHIR_INIT(Phalconator_Cli_Text_Color);
	ZEPHIR_INIT(Phalconator_Cli_Text_Menu);
	ZEPHIR_INIT(Phalconator_Mvc_Collection);
	ZEPHIR_INIT(Phalconator_Mvc_Collection_Exception);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phalconator)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_phalconator_globals *phalconator_globals TSRMLS_DC)
{
	phalconator_globals->initialized = 0;

	/* Memory options */
	phalconator_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	phalconator_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	phalconator_globals->cache_enabled = 1;

	/* Recursive Lock */
	phalconator_globals->recursive_lock = 0;

	/* Static cache */
	memset(phalconator_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_phalconator_globals *phalconator_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(phalconator)
{
	zend_phalconator_globals *phalconator_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	phalconator_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(phalconator_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(phalconator_globals_ptr TSRMLS_CC);

		zephir_init_static_properties_Phalconator_Cli_Text_Color(TSRMLS_C);
	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phalconator)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(phalconator)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PHALCONATOR_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PHALCONATOR_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PHALCONATOR_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PHALCONATOR_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PHALCONATOR_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(phalconator)
{
	php_zephir_init_globals(phalconator_globals TSRMLS_CC);
	php_zephir_init_module_globals(phalconator_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(phalconator)
{
	
}


zend_function_entry php_phalconator_functions[] = {
	ZEND_FE_END

};

zend_module_entry phalconator_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_PHALCONATOR_EXTNAME,
	php_phalconator_functions,
	PHP_MINIT(phalconator),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(phalconator),
#else
	NULL,
#endif
	PHP_RINIT(phalconator),
	PHP_RSHUTDOWN(phalconator),
	PHP_MINFO(phalconator),
	PHP_PHALCONATOR_VERSION,
	ZEND_MODULE_GLOBALS(phalconator),
	PHP_GINIT(phalconator),
	PHP_GSHUTDOWN(phalconator),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(phalconator),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PHALCONATOR
ZEND_GET_MODULE(phalconator)
#endif
