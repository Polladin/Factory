#pragma once

#include <QGraphicsItem>

#include "factoryobject.h"
#include "factoryobjectpixel.h"

class FactoryObjectPixelBuilder
{
public:
    static QGraphicsItem* build(FactoryObject *obj
                                , unsigned X, unsigned Y
                                , unsigned height, unsigned width);
};

