#include <QDebug>

#include "factoryview.h"
#include "menuironbuyerpixel.h"
#include <typeinfo>

FactoryView::FactoryView(QGraphicsScene *scene, QWidget *parent)
    : QGraphicsView(scene, parent)
{
    setMouseTracking(true);
}

void FactoryView::mousePressEvent(QMouseEvent *eventPress)
{
    qDebug() << "Mouse Pressed : " << eventPress->pos();

    for (auto *item : items(eventPress->pos()))
    {
        qDebug() << "Item is clicked";
        if (typeid(*item) == typeid(MenuIronBuyerPixel))
        {
            showObjToBuild = static_cast<MenuIronBuyerPixel*>(item)->on_left_click(eventPress, showObjToBuild, scene());
            qDebug() << "Create Item with Click";
        }
    }
}

void FactoryView::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Mouse is moved : " << event->pos();
    if (nullptr != showObjToBuild)
    {
        qDebug() << "Move Object to build";
        showObjToBuild->setPos(event->pos().x()-10, event->pos().y()-10);
    }
}

