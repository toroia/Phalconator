
extern zend_class_entry *phalconator_mvc_resourcecontroller_ce;

ZEPHIR_INIT_CLASS(Phalconator_Mvc_ResourceController);

PHP_METHOD(Phalconator_Mvc_ResourceController, __construct);

ZEPHIR_INIT_FUNCS(phalconator_mvc_resourcecontroller_method_entry) {
	PHP_ME(Phalconator_Mvc_ResourceController, __construct, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
