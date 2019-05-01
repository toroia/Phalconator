
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PHALCONATOR_H
#define PHP_PHALCONATOR_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PHALCONATOR_NAME        "phalconator"
#define PHP_PHALCONATOR_VERSION     "0.0.2"
#define PHP_PHALCONATOR_EXTNAME     "phalconator"
#define PHP_PHALCONATOR_AUTHOR      "Toroia Team and contributors"
#define PHP_PHALCONATOR_ZEPVERSION  "0.11.12-$Id$"
#define PHP_PHALCONATOR_DESCRIPTION "Web extension for Phalcon framework delivered as C-extension"



ZEND_BEGIN_MODULE_GLOBALS(phalconator)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(phalconator)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phalconator)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(phalconator, v)
#else
	#define ZEPHIR_GLOBAL(v) (phalconator_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_phalconator_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(phalconator_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(phalconator_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def phalconator_globals
#define zend_zephir_globals_def zend_phalconator_globals

extern zend_module_entry phalconator_module_entry;
#define phpext_phalconator_ptr &phalconator_module_entry

#endif
