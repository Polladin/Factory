#pragma once

#include <QGraphicsScene>
#include <QGraphicsItem>

#include "factorymap.h"


static const unsigned DISPLAY_HEIGHT = 50;
static const unsigned DISPLAY_WIDTH  = 50;

class FactoryObjectDisplay
{
public:
    FactoryObjectDisplay(FactoryMap *initFactoryMap
                         , unsigned initDispHeight //DISPLAY_HEIGHT
                         , unsigned initDispWidth ); //DISPLAY_WIDTH);

    void display(QGraphicsScene *pScene);

    void set_Xoffset(unsigned offs) { Xoffset = offs; }
    void set_Yoffset(unsigned offs) { Yoffset = offs; }

private:
    QGraphicsItem* get_object_pixel(FactoryObject *obj
                                    , unsigned height, unsigned width);

private:
    FactoryMap *pFactoryMap;

    unsigned  dispHeight
            , dispWidth;

    unsigned  Xoffset { 0 }
            , Yoffset { 0 };
};


