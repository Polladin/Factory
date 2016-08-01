#include "factoryobjectdisplay.h"

#include "factoryobjectfloorpixel.h"
#include "factoryobjectroadpixel.h"
#include "factoryobjectwallpixel.h"

FactoryObjectDisplay::FactoryObjectDisplay(FactoryMap *initFactoryMap,
                                           unsigned initDispHeight = 10, unsigned initDispWidth = 10)
    : pFactoryMap( initFactoryMap )
    , dispHeight ( initDispHeight )
    , dispWidth  ( initDispWidth  )
{

}

void FactoryObjectDisplay::display(QGraphicsScene *pScene)
{
    for(std::size_t height = 0; height < pFactoryMap->get_height(); ++height)
    {
        for(std::size_t width = 0; width < pFactoryMap->get_width(); ++width)
        {
            // create QGraphicsItem
//            QGraphicsItem *item = new FactoryObjectFloorPixel(Xoffset+ height * dispHeight, Yoffset + width * dispWidth
//                                                              , dispHeight);
//            auto item = new QGraphicsRectItem(Xoffset + height * dispHeight, Yoffset + width * dispWidth
//                                              , dispHeight, dispWidth);
//            item->setBrush(QBrush(get_color(pFactoryMap->get_object(height, width))));

            QGraphicsItem *item = get_object_pixel(pFactoryMap->get_object(width, height), height, width);
            // add the Item to Scene
            pScene->addItem(item);
        }
    }
}

QGraphicsItem* FactoryObjectDisplay::get_object_pixel(FactoryObject *obj
                                                      , unsigned height, unsigned width)
{
    switch(obj->get_type())
    {
    case FactoryTypes::FLOOR:
        return new FactoryObjectFloorPixel(Xoffset+ height * dispHeight, Yoffset + width * dispWidth, dispHeight);

    case FactoryTypes::WALL:
        return new FactoryObjectWallPixel(Xoffset+ height * dispHeight, Yoffset + width * dispWidth, dispHeight);

    case FactoryTypes::ROAD:
        return new FactoryObjectRoadPixel(Xoffset+ height * dispHeight, Yoffset + width * dispWidth, dispHeight);

    default:
        return new QGraphicsRectItem(Xoffset+ height * dispHeight, Yoffset + width * dispWidth
                                     , dispHeight, dispWidth);

    }
}

