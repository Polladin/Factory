#include "testmap1.h"

#include <vector>
#include <string>
#include <memory>

#include "factoryobjectbuilder.h"

#include <QDebug>

void TestMap1::show(FactoryMap *map)
{
    qDebug() << "Start to build map for height : " << mapPattern1.size() << " width : " << mapPattern1[0].length();
    unsigned count = 0;

    for (std::size_t height = 0; height < mapPattern1.size(); ++height)
    {
        for (std::size_t width = 0; width < mapPattern1[height].length(); ++width)
        {
            FactoryObject *item;

            // build needed object
            switch(mapPattern1[height][width])
            {
            case 'G':
                qDebug() << "build GRASS : " << count++ << " height : " << height << "  width : " << width;
                item = FactoryObjectBuilder::build(FactoryTypes::GRASS, width, height);
                break;

            case 'W':
                qDebug() << "build WALL : " << count++ << " height : " << height << "  width : " << width;
                item = FactoryObjectBuilder::build(FactoryTypes::WALL, width, height);
                break;

            case 'F':
                qDebug() << "build FLOOR : " << count++ << " height : " << height << "  width : " << width;
                item = FactoryObjectBuilder::build(FactoryTypes::FLOOR, width, height);
                break;
            }

            // insert object to the Map
            map->set_object(std::unique_ptr<FactoryObject>(item));
        }
    }
}





