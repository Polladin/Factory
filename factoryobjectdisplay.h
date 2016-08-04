#pragma once

#include <map>

#include <QGraphicsScene>
#include <QGraphicsItem>

#include "factorymap.h"
#include "factorymapobserver.h"

static const unsigned DISPLAY_HEIGHT = 50;
static const unsigned DISPLAY_WIDTH  = 50;

class FactoryObjectDisplay : public FactoryMapObserver
{
public:
    FactoryObjectDisplay(FactoryMap *initFactoryMap
                         , QGraphicsScene *initScene
                         , unsigned initDispHeight //DISPLAY_HEIGHT
                         , unsigned initDispWidth //DISPLAY_WIDTH
                         , unsigned initMenuXoffset);

    // display all elements on the map
    void display();

    /* display only changed elements (deleted or added)
       To get changes this object should be added as observer
       in FactoryMap object (FactoryMap::add_observer(FactoryMapObserver*)); */
    virtual void update() override;

    void set_Xoffset(unsigned offs) { Xoffset = offs; }
    void set_Yoffset(unsigned offs) { Yoffset = offs; }

private:
    QGraphicsItem* get_object_pixel(FactoryObject *obj);

private:
    FactoryMap *pFactoryMap;

    QGraphicsScene *displayedScene;

    unsigned  dispHeight
            , dispWidth;

    unsigned  Xoffset { 0 }
            , Yoffset { 0 }
            , menuXoffset { 0 };

    std::map<FactoryObject*, QGraphicsItem*> mappedObjects;
};


