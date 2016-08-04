#pragma once

#include <vector>
#include <memory>
#include <list>
#include <algorithm>

#include "factoryobject.h"
#include "factorymapobserver.h"

using up_FactoryObject = std::unique_ptr<FactoryObject>;
using Map = std::vector<std::vector<up_FactoryObject>>;

class FactoryMap
{

public:
    FactoryMap(std::size_t mapWidth, std::size_t mapHeight);

    std::size_t get_height() { return map.size(); }
    std::size_t get_width()  { return map.size() > 0 ? map[0].size() : 0; }

    FactoryObject* get_object(std::size_t height, std::size_t width)
        { return map[width][height].get();}

    void set_object(std::unique_ptr<FactoryObject> && obj);

    void add_observer(FactoryMapObserver *obs) { observers.push_back(obs); }
    void del_observer(FactoryMapObserver *obs)
    {
        auto pos = std::find(observers.begin(), observers.end(), obs);
        if (pos != observers.end()) observers.erase(pos);
    }

private:
    void to_observers_add_object(FactoryObject* obj);
    void to_observers_del_object(std::unique_ptr<FactoryObject> &&obj);

private:
    Map map;

    std::list<FactoryMapObserver*> observers;

};

