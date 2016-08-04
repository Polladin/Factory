#include "factoryobjectbuilder.h"

#include "factoryobjectfloor.h"
#include "factoryobjectroad.h"
#include "factoryobjectwall.h"
#include "factoryobjectgrass.h"

FactoryObject *FactoryObjectBuilder::build(FactoryTypes type, std::size_t X, std::size_t Y)
{
    switch(type)
    {
    case FactoryTypes::FLOOR:
        return new FactoryObjectFloor(X,Y);

    case FactoryTypes::ROAD:
        return new FactoryObjectRoad(X,Y);

    case FactoryTypes::WALL:
        return new FactoryObjectWall(X,Y);

    case FactoryTypes::GRASS:
        return new FactoryObjectGrass(X,Y);

    default:
        throw UndefinedTypeOfObject("Undefined Type", type);
    }
}
