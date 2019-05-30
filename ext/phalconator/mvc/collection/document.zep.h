
extern zend_class_entry *phalconator_mvc_collection_document_ce;

ZEPHIR_INIT_CLASS(Phalconator_Mvc_Collection_Document);

PHP_METHOD(Phalconator_Mvc_Collection_Document, __construct);
PHP_METHOD(Phalconator_Mvc_Collection_Document, cloneResult);
PHP_METHOD(Phalconator_Mvc_Collection_Document, offsetExists);
PHP_METHOD(Phalconator_Mvc_Collection_Document, offsetGet);
PHP_METHOD(Phalconator_Mvc_Collection_Document, offsetSet);
PHP_METHOD(Phalconator_Mvc_Collection_Document, offsetUnset);
PHP_METHOD(Phalconator_Mvc_Collection_Document, readAttribute);
PHP_METHOD(Phalconator_Mvc_Collection_Document, writeAttribute);
PHP_METHOD(Phalconator_Mvc_Collection_Document, toArray);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_mvc_collection_document_cloneresult, 0, 1, Phalconator\\Mvc\\Collection\\DocumentInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_document_cloneresult, 0, 1, IS_OBJECT, "Phalconator\\Mvc\\Collection\\DocumentInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_document_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_document_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_document_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_document_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_document_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_document_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_document_writeattribute, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_mvc_collection_document_method_entry) {
	PHP_ME(Phalconator_Mvc_Collection_Document, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(Phalconator_Mvc_Collection_Document, cloneResult, arginfo_phalconator_mvc_collection_document_cloneresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Mvc_Collection_Document, offsetExists, arginfo_phalconator_mvc_collection_document_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection_Document, offsetGet, arginfo_phalconator_mvc_collection_document_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection_Document, offsetSet, arginfo_phalconator_mvc_collection_document_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection_Document, offsetUnset, arginfo_phalconator_mvc_collection_document_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection_Document, readAttribute, arginfo_phalconator_mvc_collection_document_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection_Document, writeAttribute, arginfo_phalconator_mvc_collection_document_writeattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection_Document, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
