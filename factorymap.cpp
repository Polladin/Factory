#include "factorymap.h"

#include "factoryobjectbuilder.h"
#include "factoryobjectfloor.h"

FactoryMap::FactoryMap(std::size_t mapWidth, std::size_t mapHeight)
{
    map.resize(mapHeight);
    for (std::size_t height = 0; height < mapHeight; ++height)
    {
        map[height].resize(mapWidth);

        for (std::size_t width = 0; width < mapWidth; ++width)
        {
            map[height][width] = std::unique_ptr<FactoryObject>(
                        FactoryObjectBuilder::build(FactoryTypes::FLOOR, height, width));
        }
    }

}

void FactoryMap::set_object(std::unique_ptr<FactoryObject> &&obj)
{
    ObjectPos pos = obj->get_pos();

    map[pos.X][pos.Y].swap(obj);

//    map[pos.X][pos.Y] = std::move(obj);

    // notify observers
    to_observers_add_object(map[pos.X][pos.Y].get());

    //del old object from scene
    to_observers_del_object(std::move(obj));
}

void FactoryMap::to_observers_add_object(FactoryObject *obj)
{
    for (auto *obs : observers)
    {
        obs->push_add_object(obj);
        obs->update();
    }
}

void FactoryMap::to_observers_del_object(std::unique_ptr<FactoryObject> &&obj)
{
    std::shared_ptr<FactoryObject> sh_obj(std::move(obj));

    for (auto *obs : observers)
    {
        obs->push_del_object(sh_obj);
        obs->update();
    }
}


