#include "factoryobjectfloorpixel.h"

FactoryObjectFloorPixel::FactoryObjectFloorPixel(unsigned X, unsigned Y
                                                 , unsigned height)
    : FactoryObjectPixel(QPixmap(":/pic/factory/floor5.jpg")
                         , QPointF(X, Y)
                         , height )
{
//    setPos(X, Y);
//    setPixmap(QPixmap(":/pic/factory/floor.png"));

//    setScale((double)height / boundingRect().width());
}

