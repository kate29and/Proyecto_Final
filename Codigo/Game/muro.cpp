#include "muro.h"

float Muro::getPx() const
{
    return px;
}

float Muro::getPy() const
{
    return py;
}

Muro::Muro(float px, float py) : px(px), py(py)
{
    dx = 30;
    dy = 30;
    setPos(px,py);
}

Muro::Muro(float px, float py,char) : px(px), py(py)
{
    dx = 30;
    dy = 30;
    setPos(px,py);
}


QRectF Muro::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void Muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

        painter->setBrush(Qt::cyan);
        painter->drawRect(boundingRect());

}
