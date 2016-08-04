#pragma once

#include <list>
#include <memory>

#include "factoryobject.h"

class FactoryMapObserver
{
public:
    FactoryMapObserver();

    virtual ~FactoryMapObserver() {}

    virtual void update() = 0;

    bool has_add_objects() const { return addObjects.size() != 0; }
    bool has_del_objects() const { return delObjects.size() != 0; }

    void push_add_object(FactoryObject *obj) { addObjects.push_back(obj); }
    void push_del_object(std::shared_ptr<FactoryObject> obj) { delObjects.push_back(std::move(obj)); }

    FactoryObject* pop_add_object();
    std::shared_ptr<FactoryObject> pop_del_object();

private:
    std::list<FactoryObject*> addObjects;
    std::list<std::shared_ptr<FactoryObject>> delObjects;
};

