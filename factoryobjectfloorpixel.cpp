#include "factoryobjectfloorpixel.h"

FactoryObjectFloorPixel::FactoryObjectFloorPixel(unsigned X, unsigned Y
                                                 , unsigned height)
{
    setPos(X, Y);
    setPixmap(QPixmap(":/pic/factory/floor.png"));

    setScale((double)height / boundingRect().width());
}

