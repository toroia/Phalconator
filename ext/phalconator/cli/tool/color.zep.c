
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
  * Phalconator\Cli\Tool\Color
  *
  * The class color cli lines
  */
ZEPHIR_INIT_CLASS(Phalconator_Cli_Tool_Color) {

	ZEPHIR_REGISTER_CLASS(Phalconator\\Cli\\Tool, Color, phalconator, cli_tool_color, phalconator_cli_tool_color_method_entry, 0);

	zend_declare_property_null(phalconator_cli_tool_color_ce, SL("_style"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalconator_cli_tool_color_ce, SL("_color"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalconator_cli_tool_color_ce, SL("_background"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zephir_declare_class_constant_string(phalconator_cli_tool_color_ce, SL("COLORIZE"), "[%sm");

	zephir_declare_class_constant_string(phalconator_cli_tool_color_ce, SL("UNCOLORIZE"), "[0m");

	return SUCCESS;

}

/**
 * Lock the constructor
 */
PHP_METHOD(Phalconator_Cli_Tool_Color, __construct) {

	zval *this_ptr = getThis();



}

/**
 * Render the string coloring
 */
PHP_METHOD(Phalconator_Cli_Tool_Color, render) {

	zend_bool _0, _1, _2;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *c = NULL, c_sub, *b = NULL, b_sub, *s = NULL, s_sub, __$null, concat, color, render, _3, _4, _5, _6, _8;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&c_sub);
	ZVAL_UNDEF(&b_sub);
	ZVAL_UNDEF(&s_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&concat);
	ZVAL_UNDEF(&color);
	ZVAL_UNDEF(&render);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &data_param, &c, &b, &s);

	zephir_get_strval(&data, data_param);
	if (!c) {
		c = &c_sub;
		c = &__$null;
	}
	if (!b) {
		b = &b_sub;
		b = &__$null;
	}
	if (!s) {
		s = &s_sub;
		s = &__$null;
	}


	if (ZEPHIR_IS_EMPTY(&data)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconator_cli_exception_ce, "Data is required", "phalconator/cli/tool/color.zep", 97);
		return;
	}
	_0 = zephir_is_true(c);
	if (_0) {
		_0 = Z_TYPE_P(c) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconator_cli_exception_ce, "Bad color type", "phalconator/cli/tool/color.zep", 101);
		return;
	}
	_1 = zephir_is_true(b);
	if (_1) {
		_1 = Z_TYPE_P(b) != IS_STRING;
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconator_cli_exception_ce, "Bad background type", "phalconator/cli/tool/color.zep", 105);
		return;
	}
	_2 = zephir_is_true(s);
	if (_2) {
		_2 = Z_TYPE_P(s) != IS_STRING;
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconator_cli_exception_ce, "Bad style type", "phalconator/cli/tool/color.zep", 109);
		return;
	}
	ZEPHIR_CALL_SELF(&_3, "clear", NULL, 0, &data);
	zephir_check_call_status();
	zephir_get_strval(&data, &_3);
	ZEPHIR_CALL_SELF(&concat, "_concat", NULL, 0, c, b, s);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "[%sm");
	ZEPHIR_CALL_FUNCTION(&color, "sprintf", NULL, 1, &_4, &concat);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 27);
	ZEPHIR_CALL_FUNCTION(&_6, "chr", &_7, 2, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 27);
	ZEPHIR_CALL_FUNCTION(&_8, "chr", &_7, 2, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&render);
	ZEPHIR_CONCAT_VVVVS(&render, &_6, &color, &data, &_8, "[0m");
	RETURN_CCTOR(&render);

}

/**
 * Clear string coloring
 */
PHP_METHOD(Phalconator_Cli_Tool_Color, clear) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, _0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(&data, data_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "#\\x1b[[][^A-Za-z]*[A-Za-z]#");
	ZVAL_NULL(&_1);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 3, &_0, &_1, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Concat color, background and style into string
 */
PHP_METHOD(Phalconator_Cli_Tool_Color, _concat) {

	zval concat;
	zval *c = NULL, c_sub, *b = NULL, b_sub, *s = NULL, s_sub, __$null, co, bg, st, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&c_sub);
	ZVAL_UNDEF(&b_sub);
	ZVAL_UNDEF(&s_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&co);
	ZVAL_UNDEF(&bg);
	ZVAL_UNDEF(&st);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&concat);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &c, &b, &s);

	if (!c) {
		c = &c_sub;
		c = &__$null;
	}
	if (!b) {
		b = &b_sub;
		b = &__$null;
	}
	if (!s) {
		s = &s_sub;
		s = &__$null;
	}


	ZEPHIR_INIT_VAR(&concat);
	array_init(&concat);
	ZEPHIR_OBS_VAR(&co);
	zephir_read_static_property_ce(&_0, phalconator_cli_tool_color_ce, SL("_color"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&co, &_0, c, 0 TSRMLS_CC)) {
		zephir_array_append(&concat, &co, PH_SEPARATE, "phalconator/cli/tool/color.zep", 142);
	}
	ZEPHIR_OBS_VAR(&st);
	zephir_read_static_property_ce(&_1, phalconator_cli_tool_color_ce, SL("_style"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&st, &_1, s, 0 TSRMLS_CC)) {
		zephir_array_append(&concat, &st, PH_SEPARATE, "phalconator/cli/tool/color.zep", 146);
	}
	ZEPHIR_OBS_VAR(&bg);
	zephir_read_static_property_ce(&_2, phalconator_cli_tool_color_ce, SL("_background"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&bg, &_2, b, 0 TSRMLS_CC)) {
		zephir_array_append(&concat, &bg, PH_SEPARATE, "phalconator/cli/tool/color.zep", 150);
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_join_str(&_3, SL(";"), &concat TSRMLS_CC);
	RETURN_CCTOR(&_3);

}

void zephir_init_static_properties_Phalconator_Cli_Tool_Color(TSRMLS_D) {

	zval _0, _1, _2;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 16, 0 TSRMLS_CC);
	add_assoc_long_ex(&_0, SL("black"), 40);
	add_assoc_long_ex(&_0, SL("red"), 41);
	add_assoc_long_ex(&_0, SL("green"), 42);
	add_assoc_long_ex(&_0, SL("yellow"), 43);
	add_assoc_long_ex(&_0, SL("blue"), 44);
	add_assoc_long_ex(&_0, SL("magenta"), 45);
	add_assoc_long_ex(&_0, SL("cyan"), 46);
	add_assoc_long_ex(&_0, SL("light_gray"), 47);
	add_assoc_long_ex(&_0, SL("dark_gray"), 100);
	add_assoc_long_ex(&_0, SL("light_red"), 101);
	add_assoc_long_ex(&_0, SL("light_green"), 102);
	add_assoc_long_ex(&_0, SL("light_yellow"), 103);
	add_assoc_long_ex(&_0, SL("light_blue"), 104);
	add_assoc_long_ex(&_0, SL("light_magenta"), 105);
	add_assoc_long_ex(&_0, SL("light_cyan"), 106);
	add_assoc_long_ex(&_0, SL("white"), 107);
	zend_update_static_property(phalconator_cli_tool_color_ce, ZEND_STRL("_background"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 16, 0 TSRMLS_CC);
	add_assoc_long_ex(&_1, SL("black"), 30);
	add_assoc_long_ex(&_1, SL("red"), 31);
	add_assoc_long_ex(&_1, SL("green"), 32);
	add_assoc_long_ex(&_1, SL("yellow"), 33);
	add_assoc_long_ex(&_1, SL("blue"), 34);
	add_assoc_long_ex(&_1, SL("magenta"), 35);
	add_assoc_long_ex(&_1, SL("cyan"), 36);
	add_assoc_long_ex(&_1, SL("light_gray"), 37);
	add_assoc_long_ex(&_1, SL("dark_gray"), 90);
	add_assoc_long_ex(&_1, SL("light_red"), 91);
	add_assoc_long_ex(&_1, SL("light_green"), 92);
	add_assoc_long_ex(&_1, SL("light_yellow"), 93);
	add_assoc_long_ex(&_1, SL("light_blue"), 94);
	add_assoc_long_ex(&_1, SL("light_magenta"), 95);
	add_assoc_long_ex(&_1, SL("light_cyan"), 96);
	add_assoc_long_ex(&_1, SL("white"), 97);
	zend_update_static_property(phalconator_cli_tool_color_ce, ZEND_STRL("_color"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 8, 0 TSRMLS_CC);
	add_assoc_long_ex(&_2, SL("reset"), 0);
	add_assoc_long_ex(&_2, SL("bold"), 1);
	add_assoc_long_ex(&_2, SL("dark"), 2);
	add_assoc_long_ex(&_2, SL("italic"), 3);
	add_assoc_long_ex(&_2, SL("underline"), 4);
	add_assoc_long_ex(&_2, SL("blink"), 5);
	add_assoc_long_ex(&_2, SL("reverse"), 7);
	add_assoc_long_ex(&_2, SL("concealed"), 8);
	zend_update_static_property(phalconator_cli_tool_color_ce, ZEND_STRL("_style"), &_2);
	ZEPHIR_MM_RESTORE();

}

