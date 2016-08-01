#pragma once

#include <QGraphicsScene>

#include "buildmenu.h"

class MenuDisplay
{
public:
    MenuDisplay(const BuildMenu &initBuildMenu);

    void display(QGraphicsScene *pScene) const;

    void set_border(unsigned heigth, unsigned width)
        { Xborder = heigth; Yborder = width; }

private:
    const BuildMenu &buildMenu;

    unsigned  Xborder
            , Yborder;
};

