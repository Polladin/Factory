#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsItem>

class FactoryView : public QGraphicsView
{
public:
    FactoryView(QGraphicsScene *scene, QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *eventPress);

    void mouseMoveEvent(QMouseEvent *event);

private:

    QGraphicsItem * showObjToBuild {nullptr};
};

