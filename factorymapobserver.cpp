#include "factorymapobserver.h"

FactoryMapObserver::FactoryMapObserver()
{

}

FactoryObject* FactoryMapObserver::pop_add_object()
{
    FactoryObject* obj = addObjects.back();
    addObjects.pop_back();

    return obj;
}

std::shared_ptr<FactoryObject> FactoryMapObserver::pop_del_object()
{
    std::shared_ptr<FactoryObject> obj = std::move(delObjects.back());
    delObjects.pop_back();

    return obj;
}


