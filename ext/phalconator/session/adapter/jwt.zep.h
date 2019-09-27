
extern zend_class_entry *phalconator_session_adapter_jwt_ce;

ZEPHIR_INIT_CLASS(Phalconator_Session_Adapter_Jwt);

PHP_METHOD(Phalconator_Session_Adapter_Jwt, close);
PHP_METHOD(Phalconator_Session_Adapter_Jwt, destroy);
PHP_METHOD(Phalconator_Session_Adapter_Jwt, gc);
PHP_METHOD(Phalconator_Session_Adapter_Jwt, read);
PHP_METHOD(Phalconator_Session_Adapter_Jwt, open);
PHP_METHOD(Phalconator_Session_Adapter_Jwt, write);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_close, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_close, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_destroy, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_destroy, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_gc, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_gc, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_read, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_read, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_open, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_open, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, savePath)
	ZEND_ARG_INFO(0, sessionName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_write, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_session_adapter_jwt_write, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_session_adapter_jwt_method_entry) {
	PHP_ME(Phalconator_Session_Adapter_Jwt, close, arginfo_phalconator_session_adapter_jwt_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Session_Adapter_Jwt, destroy, arginfo_phalconator_session_adapter_jwt_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Session_Adapter_Jwt, gc, arginfo_phalconator_session_adapter_jwt_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Session_Adapter_Jwt, read, arginfo_phalconator_session_adapter_jwt_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Session_Adapter_Jwt, open, arginfo_phalconator_session_adapter_jwt_open, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Session_Adapter_Jwt, write, arginfo_phalconator_session_adapter_jwt_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
