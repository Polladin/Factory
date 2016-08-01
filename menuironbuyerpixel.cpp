#include <QBrush>

#include "menuironbuyerpixel.h"

MenuIronBuyerPixel::MenuIronBuyerPixel(unsigned X, unsigned Y
                                       , unsigned height)
{
    setRect(X, Y, height, height);
    setBrush(QBrush(Qt::green));
}

QGraphicsItem* MenuIronBuyerPixel::on_left_click(QMouseEvent *eventPress, QGraphicsItem *showObjToBuild
                                       , QGraphicsScene *scene)
{
    QGraphicsRectItem *item = new QGraphicsRectItem(0, 0, 20, 20);
    item->setPos(eventPress->pos().x(), eventPress->pos().y());
    item->setBrush(QBrush(Qt::red));

    showObjToBuild = item;
    scene->addItem(item);

    return item;
}


