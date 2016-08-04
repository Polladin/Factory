#include "factoryobjectpixel.h"



FactoryObjectPixel::FactoryObjectPixel(const QPixmap &_pixmap, const QPointF &_pos, qreal _scale)
{
    setPos(_pos);
    setPixmap(_pixmap);

    setScale(_scale / boundingRect().width());
}
