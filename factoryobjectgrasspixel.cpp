#include "factoryobjectgrasspixel.h"

FactoryObjectGrassPixel::FactoryObjectGrassPixel(unsigned X, unsigned Y
                                                 , unsigned height       )
{
    setPos(X, Y);
    setPixmap(QPixmap(":/pic/factory/grass.png"));

    setScale((double)height / boundingRect().width());
}

