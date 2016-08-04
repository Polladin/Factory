#include "factoryobjectpixelbuilder.h"

#include "factoryobjectfloorpixel.h"
#include "factoryobjectwallpixel.h"
#include "factoryobjectroadpixel.h"

QGraphicsItem *FactoryObjectPixelBuilder::build(FactoryObject *obj
                                                , unsigned X, unsigned Y
                                                , unsigned height, unsigned width)
{
    switch(obj->get_type())
    {
    case FactoryTypes::FLOOR:
        return new FactoryObjectFloorPixel(X, Y, height);

    case FactoryTypes::WALL:
        return new FactoryObjectWallPixel(X, Y, height);

    case FactoryTypes::ROAD:
        return new FactoryObjectRoadPixel(X, Y, height);

    default:
        return new QGraphicsRectItem(X, Y, height, width);

    }
}
