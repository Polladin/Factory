#include "factorymap.h"

#include "factoryobjectfloor.h"

FactoryMap::FactoryMap(std::size_t mapHeight, std::size_t mapWidth)
{
    map.resize(mapHeight);
    for (auto& mapRow : map)
    {
        mapRow.resize(mapWidth);

        for (auto& cell : mapRow)
        {
            cell = std::unique_ptr<FactoryObject>(new FactoryObjectFloor());
        }
    }

}


