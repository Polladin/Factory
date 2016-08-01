#pragma once

#include <vector>
#include <memory>

#include "factoryobject.h"

using up_FactoryObject = std::unique_ptr<FactoryObject>;
using Map = std::vector<std::vector<up_FactoryObject>>;

class FactoryMap
{

public:
    FactoryMap(std::size_t mapHeight, std::size_t mapWidth);

    std::size_t get_height() { return map.size(); }
    std::size_t get_width()  { return map.size() > 0 ? map[0].size() : 0; }

    FactoryObject* get_object(std::size_t height, std::size_t width)
        { return map[height][width].get();}

    void set_object(std::size_t height, std::size_t width
                    , std::unique_ptr<FactoryObject> && obj)
        { map[height][width] = std::move(obj); }

private:
    Map map;

};

