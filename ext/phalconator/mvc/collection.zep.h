
extern zend_class_entry *phalconator_mvc_collection_ce;

ZEPHIR_INIT_CLASS(Phalconator_Mvc_Collection);

PHP_METHOD(Phalconator_Mvc_Collection, __construct);
PHP_METHOD(Phalconator_Mvc_Collection, setId);
PHP_METHOD(Phalconator_Mvc_Collection, getId);
PHP_METHOD(Phalconator_Mvc_Collection, setDI);
PHP_METHOD(Phalconator_Mvc_Collection, getDI);
PHP_METHOD(Phalconator_Mvc_Collection, setEventsManager);
PHP_METHOD(Phalconator_Mvc_Collection, getEventsManager);
PHP_METHOD(Phalconator_Mvc_Collection, getCollectionManager);
PHP_METHOD(Phalconator_Mvc_Collection, getReservedAttributes);
PHP_METHOD(Phalconator_Mvc_Collection, useImplicitObjectIds);
PHP_METHOD(Phalconator_Mvc_Collection, setSource);
PHP_METHOD(Phalconator_Mvc_Collection, getSource);
PHP_METHOD(Phalconator_Mvc_Collection, setConnectionService);
PHP_METHOD(Phalconator_Mvc_Collection, getConnectionService);
PHP_METHOD(Phalconator_Mvc_Collection, getConnection);
PHP_METHOD(Phalconator_Mvc_Collection, readAttribute);
PHP_METHOD(Phalconator_Mvc_Collection, writeAttribute);
PHP_METHOD(Phalconator_Mvc_Collection, cloneResult);
PHP_METHOD(Phalconator_Mvc_Collection, _getResultset);
PHP_METHOD(Phalconator_Mvc_Collection, _getGroupResultset);
PHP_METHOD(Phalconator_Mvc_Collection, _preSave);
PHP_METHOD(Phalconator_Mvc_Collection, _postSave);
PHP_METHOD(Phalconator_Mvc_Collection, validate);
PHP_METHOD(Phalconator_Mvc_Collection, validationHasFailed);
PHP_METHOD(Phalconator_Mvc_Collection, fireEvent);
PHP_METHOD(Phalconator_Mvc_Collection, fireEventCancel);
PHP_METHOD(Phalconator_Mvc_Collection, _cancelOperation);
PHP_METHOD(Phalconator_Mvc_Collection, _exists);
PHP_METHOD(Phalconator_Mvc_Collection, getMessages);
PHP_METHOD(Phalconator_Mvc_Collection, appendMessage);
PHP_METHOD(Phalconator_Mvc_Collection, prepareCU);
PHP_METHOD(Phalconator_Mvc_Collection, save);
PHP_METHOD(Phalconator_Mvc_Collection, create);
PHP_METHOD(Phalconator_Mvc_Collection, createIfNotExist);
PHP_METHOD(Phalconator_Mvc_Collection, update);
PHP_METHOD(Phalconator_Mvc_Collection, findById);
PHP_METHOD(Phalconator_Mvc_Collection, findFirst);
PHP_METHOD(Phalconator_Mvc_Collection, find);
PHP_METHOD(Phalconator_Mvc_Collection, count);
PHP_METHOD(Phalconator_Mvc_Collection, aggregate);
PHP_METHOD(Phalconator_Mvc_Collection, summatory);
PHP_METHOD(Phalconator_Mvc_Collection, delete);
PHP_METHOD(Phalconator_Mvc_Collection, setDirtyState);
PHP_METHOD(Phalconator_Mvc_Collection, getDirtyState);
PHP_METHOD(Phalconator_Mvc_Collection, addBehavior);
PHP_METHOD(Phalconator_Mvc_Collection, skipOperation);
PHP_METHOD(Phalconator_Mvc_Collection, toArray);
PHP_METHOD(Phalconator_Mvc_Collection, serialize);
PHP_METHOD(Phalconator_Mvc_Collection, bsonUnserialize);
PHP_METHOD(Phalconator_Mvc_Collection, unserialize);
zend_object *zephir_init_properties_Phalconator_Mvc_Collection(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
	ZEND_ARG_OBJ_INFO(0, modelsManager, Phalconator\\Mvc\\Collection\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_mvc_collection_getdi, 0, 0, Phalcon\\DiInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getdi, 0, 0, IS_OBJECT, "Phalcon\\DiInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalconator\\Mvc\\Collection\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_mvc_collection_geteventsmanager, 0, 0, Phalconator\\Mvc\\Collection\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_geteventsmanager, 0, 0, IS_OBJECT, "Phalconator\\Mvc\\Collection\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_mvc_collection_getcollectionmanager, 0, 0, Phalconator\\Mvc\\Collection\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getcollectionmanager, 0, 0, IS_OBJECT, "Phalconator\\Mvc\\Collection\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getreservedattributes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getreservedattributes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_useimplicitobjectids, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, useImplicitObjectIds, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, useImplicitObjectIds)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_mvc_collection_setsource, 0, 1, Phalconator\\Mvc\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_setsource, 0, 1, IS_OBJECT, "Phalconator\\Mvc\\Collection", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, source)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getsource, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getsource, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_mvc_collection_setconnectionservice, 0, 1, Phalconator\\Mvc\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_setconnectionservice, 0, 1, IS_OBJECT, "Phalconator\\Mvc\\Collection", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, connectionService, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, connectionService)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getconnectionservice, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getconnectionservice, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_readattribute, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_writeattribute, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_mvc_collection_cloneresult, 0, 2, Phalconator\\Mvc\\CollectionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_cloneresult, 0, 2, IS_OBJECT, "Phalconator\\Mvc\\CollectionInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, collection, Phalconator\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, document, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection__getresultset, 0, 0, 4)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_OBJ_INFO(0, collection, Phalconator\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, connection)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, unique, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, unique)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection__getgroupresultset, 0, 3, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection__getgroupresultset, 0, 3, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_OBJ_INFO(0, collection, Phalconator\\Mvc\\Collection, 0)
	ZEND_ARG_INFO(0, connection)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection__presave, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection__presave, 0, 3, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, disableEvents, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, disableEvents)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, exists, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, exists)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection__postsave, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection__postsave, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, disableEvents, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, disableEvents)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, success, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, success)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, exists, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, exists)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_validate, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_validate, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\ValidationInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_validationhasfailed, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_validationhasfailed, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_fireevent, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_fireevent, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, eventName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_fireeventcancel, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_fireeventcancel, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, eventName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection__canceloperation, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection__canceloperation, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, disableEvents, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, disableEvents)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection__exists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection__exists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getmessages, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getmessages, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Mvc\\Model\\MessageInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_save, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_save, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_create, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_create, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_createifnotexist, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_createifnotexist, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, criteria, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_update, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_update, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_mvc_collection_findbyid, 0, 1, Phalconator\\Mvc\\CollectionInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_findbyid, 0, 1, IS_OBJECT, "Phalconator\\Mvc\\CollectionInterface", 1)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_findfirst, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_findfirst, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_find, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_find, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_count, 0, 0, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_aggregate, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_aggregate, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_summatory, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_summatory, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, finalize)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_delete, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_delete, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconator_mvc_collection_setdirtystate, 0, 1, Phalconator\\Mvc\\CollectionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_setdirtystate, 0, 1, IS_OBJECT, "Phalconator\\Mvc\\CollectionInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dirtyState, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, dirtyState)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getdirtystate, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_getdirtystate, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_addbehavior, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Collection\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_skipoperation, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, skip, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, skip)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_serialize, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconator_mvc_collection_serialize, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_bsonunserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconator_mvc_collection_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconator_mvc_collection_method_entry) {
	PHP_ME(Phalconator_Mvc_Collection, __construct, arginfo_phalconator_mvc_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(Phalconator_Mvc_Collection, setId, arginfo_phalconator_mvc_collection_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, setDI, arginfo_phalconator_mvc_collection_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, getDI, arginfo_phalconator_mvc_collection_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, setEventsManager, arginfo_phalconator_mvc_collection_seteventsmanager, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconator_Mvc_Collection, getEventsManager, arginfo_phalconator_mvc_collection_geteventsmanager, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconator_Mvc_Collection, getCollectionManager, arginfo_phalconator_mvc_collection_getcollectionmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, getReservedAttributes, arginfo_phalconator_mvc_collection_getreservedattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, useImplicitObjectIds, arginfo_phalconator_mvc_collection_useimplicitobjectids, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconator_Mvc_Collection, setSource, arginfo_phalconator_mvc_collection_setsource, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconator_Mvc_Collection, getSource, arginfo_phalconator_mvc_collection_getsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, setConnectionService, arginfo_phalconator_mvc_collection_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, getConnectionService, arginfo_phalconator_mvc_collection_getconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, readAttribute, arginfo_phalconator_mvc_collection_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, writeAttribute, arginfo_phalconator_mvc_collection_writeattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, cloneResult, arginfo_phalconator_mvc_collection_cloneresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Mvc_Collection, _getResultset, arginfo_phalconator_mvc_collection__getresultset, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Mvc_Collection, _getGroupResultset, arginfo_phalconator_mvc_collection__getgroupresultset, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Mvc_Collection, _preSave, arginfo_phalconator_mvc_collection__presave, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalconator_Mvc_Collection, _postSave, arginfo_phalconator_mvc_collection__postsave, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalconator_Mvc_Collection, validate, arginfo_phalconator_mvc_collection_validate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconator_Mvc_Collection, validationHasFailed, arginfo_phalconator_mvc_collection_validationhasfailed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, fireEvent, arginfo_phalconator_mvc_collection_fireevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, fireEventCancel, arginfo_phalconator_mvc_collection_fireeventcancel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, _cancelOperation, arginfo_phalconator_mvc_collection__canceloperation, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconator_Mvc_Collection, _exists, arginfo_phalconator_mvc_collection__exists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconator_Mvc_Collection, getMessages, arginfo_phalconator_mvc_collection_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, appendMessage, arginfo_phalconator_mvc_collection_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, prepareCU, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconator_Mvc_Collection, save, arginfo_phalconator_mvc_collection_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, create, arginfo_phalconator_mvc_collection_create, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, createIfNotExist, arginfo_phalconator_mvc_collection_createifnotexist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, update, arginfo_phalconator_mvc_collection_update, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, findById, arginfo_phalconator_mvc_collection_findbyid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Mvc_Collection, findFirst, arginfo_phalconator_mvc_collection_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Mvc_Collection, find, arginfo_phalconator_mvc_collection_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Mvc_Collection, count, arginfo_phalconator_mvc_collection_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Mvc_Collection, aggregate, arginfo_phalconator_mvc_collection_aggregate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Mvc_Collection, summatory, arginfo_phalconator_mvc_collection_summatory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalconator_Mvc_Collection, delete, arginfo_phalconator_mvc_collection_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, setDirtyState, arginfo_phalconator_mvc_collection_setdirtystate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, getDirtyState, arginfo_phalconator_mvc_collection_getdirtystate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, addBehavior, arginfo_phalconator_mvc_collection_addbehavior, ZEND_ACC_PROTECTED)
	PHP_ME(Phalconator_Mvc_Collection, skipOperation, arginfo_phalconator_mvc_collection_skipoperation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, toArray, arginfo_phalconator_mvc_collection_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, serialize, arginfo_phalconator_mvc_collection_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, bsonUnserialize, arginfo_phalconator_mvc_collection_bsonunserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalconator_Mvc_Collection, unserialize, arginfo_phalconator_mvc_collection_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
