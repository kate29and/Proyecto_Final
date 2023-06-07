#include "tablero.h"

int Tablero::getMuroTipe() const
{
    return MuroTipe;
}

void Tablero::setMuroTipe(int newMuroTipe)
{
    MuroTipe = newMuroTipe;
}

Tablero::Tablero(int x, int y)
{
    dimx=25;
    dimy=25;
    setPos(x, y);
}

Tablero::Tablero(int posx, int posy, int muroT)
{
    dimx=25;
    dimy=25;
    MuroTipe=muroT;
    setPos(posx, posy);
}

QRectF Tablero::boundingRect() const
{
    return QRectF(0,0,dimx,dimy);
}

void Tablero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(MuroTipe==1){

        painter->setBrush(Qt::darkGray);
        painter->drawRect(boundingRect());
    }

}


