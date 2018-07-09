PHP_ARG_ENABLE(phalconator, whether to enable phalconator, [ --enable-phalconator   Enable Phalconator])

if test "$PHP_PHALCONATOR" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PHALCONATOR_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PHALCONATOR, 1, [Whether you have Phalconator])
	phalconator_sources="phalconator.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c phalconator/exception.zep.c
	phalconator/cli/exception.zep.c
	phalconator/cli/text.zep.c
	phalconator/cli/text/color.zep.c
	phalconator/cli/text/menu.zep.c
	phalconator/mvc/collection.zep.c "
	PHP_NEW_EXTENSION(phalconator, $phalconator_sources, $ext_shared,, )
	PHP_SUBST(PHALCONATOR_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalconator], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phalconator], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/phalconator], [php_PHALCONATOR.h])

fi
