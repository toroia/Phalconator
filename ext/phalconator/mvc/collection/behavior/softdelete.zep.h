
extern zend_class_entry *phalconator_mvc_collection_behavior_softdelete_ce;

ZEPHIR_INIT_CLASS(Phalconator_Mvc_Collection_Behavior_SoftDelete);

PHP_METHOD(Phalconator_Mvc_Collection_Behavior_SoftDelete, notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_behavior_softdelete_notify, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalconator\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_mvc_collection_behavior_softdelete_method_entry) {
	PHP_ME(Phalconator_Mvc_Collection_Behavior_SoftDelete, notify, arginfo_phalconator_mvc_collection_behavior_softdelete_notify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
