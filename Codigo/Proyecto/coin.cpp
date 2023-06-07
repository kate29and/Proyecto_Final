
#include "coin.h"



int Coin::getMuroTipe() const
{
    return MuroTipe;
}

void Coin::setMuroTipe(int newMuroTipe)
{
    MuroTipe = newMuroTipe;
}

Coin::Coin(int x, int y)
{
    dimx=25;
    dimy=25;
    setPos(x, y);
}

Coin::Coin(int posx, int posy, int muroT)
{
    dimx=25;
    dimy=25;
    MuroTipe=muroT;
    setPos(posx, posy);
}

QRectF Coin::boundingRect() const
{
    return QRectF(0,0,dimx,dimy);
}

void Coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(MuroTipe==1){

        painter->setBrush(Qt::transparent);
        painter->drawRect(boundingRect());
    }

}


