
extern zend_class_entry *phalconator_mvc_collectioninterface_ce;

ZEPHIR_INIT_CLASS(Phalconator_Mvc_CollectionInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collectioninterface_tojsonify, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collectioninterface_tojsonify, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_mvc_collectioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalconator_Mvc_CollectionInterface, toJsonify, arginfo_phalconator_mvc_collectioninterface_tojsonify)
	PHP_FE_END
};
