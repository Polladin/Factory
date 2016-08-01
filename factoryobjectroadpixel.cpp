#include "factoryobjectroadpixel.h"

FactoryObjectRoadPixel::FactoryObjectRoadPixel(unsigned X, unsigned Y
                                               , unsigned height       )
{
    setPos(X, Y);
    setPixmap(QPixmap(":/pic/factory/road.jpg"));

    setScale((double)height / boundingRect().width());
}

