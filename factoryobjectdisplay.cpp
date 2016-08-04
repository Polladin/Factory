#include "factoryobjectdisplay.h"

#include "factoryobjectpixelbuilder.h"
#include "factoryobjectfloorpixel.h"
#include "factoryobjectroadpixel.h"
#include "factoryobjectwallpixel.h"

#include <QDebug>

FactoryObjectDisplay::FactoryObjectDisplay(FactoryMap *initFactoryMap
                                           , QGraphicsScene *initScene
                                           , unsigned initDispHeight
                                           , unsigned initDispWidth
                                           , unsigned initMenuXoffset   )
    : pFactoryMap {initFactoryMap}
    , displayedScene {initScene}
    , dispHeight {initDispHeight}
    , dispWidth  {initDispWidth}
{
    menuXoffset = initMenuXoffset;
    display();
}

void FactoryObjectDisplay::display()
{
    if (pFactoryMap == nullptr) return;

    for(std::size_t height = 0; height < pFactoryMap->get_height(); ++height)
    {
        for(std::size_t width = 0; width < pFactoryMap->get_width(); ++width)
        {
            QGraphicsItem *item = get_object_pixel(pFactoryMap->get_object(width, height));

            // add the Item to Scene
            displayedScene->addItem(item);
        }
    }
}

void FactoryObjectDisplay::update()
{
    // add new Items to the Scene
    while (has_add_objects())
    {
        QGraphicsItem *item = get_object_pixel (pop_add_object());

        displayedScene->addItem(item);
    }

    while (has_del_objects())
    {
        std::shared_ptr<FactoryObject> objToDel = pop_del_object();

        // if a object was displayed on the Scene
        if (mappedObjects.find(objToDel.get()) != mappedObjects.end())
        {
            displayedScene->removeItem(mappedObjects.at(objToDel.get()));
            mappedObjects.erase(mappedObjects.find(objToDel.get()));
        }
    }
}

QGraphicsItem* FactoryObjectDisplay::get_object_pixel(FactoryObject *obj)
{
    ObjectPos pos = obj->get_pos();

    unsigned X = menuXoffset + pos.X * dispHeight; //
    unsigned Y = Yoffset + pos.Y * dispWidth;

    QGraphicsItem *item = FactoryObjectPixelBuilder::build(
                                obj, X, Y, dispHeight, dispWidth);

    mappedObjects.insert(std::make_pair(obj, item));

    return item;
}

