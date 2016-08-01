#pragma once

#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

class MenuIronBuyerPixel : public QGraphicsRectItem
{
public:
    MenuIronBuyerPixel(unsigned X, unsigned Y
                       , unsigned height);

    QGraphicsItem* on_left_click(QMouseEvent *eventPress, QGraphicsItem *showObjToBuild
                       , QGraphicsScene *scene);
};

