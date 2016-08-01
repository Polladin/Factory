#include "factoryobjectwallpixel.h"

FactoryObjectWallPixel::FactoryObjectWallPixel(unsigned X, unsigned Y
                                             , unsigned height       )
{
    setPos(X, Y);
    setPixmap(QPixmap(":/pic/factory/wall.png"));

    setScale((double)height / boundingRect().width());
}

