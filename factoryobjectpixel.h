#pragma once

#include <QGraphicsPixmapItem>

class FactoryObjectPixel : public QGraphicsPixmapItem
{
public:
    FactoryObjectPixel(const QPixmap &_pixmap, const QPointF &_pos, qreal _scale);

};

