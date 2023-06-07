#include "sprite.h"
#include <QPainter>
char Sprite::getDirection() const
{
    return Direction;
}

void Sprite::setDirection(char newDirection)
{
    Direction = newDirection;
}
Sprite::Sprite(QObject *parent) : QObject(parent)
{
   timer =new QTimer();
   filas=0;
   columnas=0;

  // pixmap =new QPixmap(":/move.png");
   //dimenciones de cada una de las imagenes
   alto=30;
   ancho=30;
   //velosidad de iteraciones
   timer->start(150);
   connect(timer,&QTimer::timeout,this,&Sprite::Actualizacion);
   setPos(posx,posy);


}

void Sprite::orientacion(int num)
{
    switch (num) {
    case 0:
//        minimo=60;
//        maximo=90;
//        columnas=minimo;
    break;
    case 1:
//        minimo=90;
//        maximo=180;
//        columnas=minimo;
    break;
    case 2:
        minimo=420;
        maximo=720;
        columnas=minimo;
    break;
    case 3:
        minimo=60;
        maximo=300;
        columnas=minimo;
    break;

    }
}


float Sprite::getPosx() const
{
    return posx;
}
float Sprite::getPosy() const
{
    return posy;
}
void Sprite::setPosx(float newPosX)
{
    posx = newPosX;
}
void Sprite::setPosy(float newPosY)
{
    posy = newPosY;
}


void Sprite::up()
{
    posy-=velpos_in_y;
    mov_dir_y=posy;
    qDebug()<<"negativo en y "<<velpos_in_y;
    setPos(posx,posy);//dan la nueva posicion
    Direction='U';
    //qDebug()<<"pos in y "<<posy<<endl;
//    qDebug()<<"pos in x "<<posx<<endl;
    if(!scene()->views().isEmpty()){
    scene()->views().first()->centerOn(this);
    }
}

void Sprite::down()
{
    posy+=velneg_in_y;
    mov_dir_y=posy;
    qDebug()<<"positivo en y "<<velneg_in_y;
    setPos(posx,posy);
    Direction='D';
    //qDebug()<<"pos in y "<<posy<<endl;
//    qDebug()<<"pos in x "<<posx<<endl;
    if(!scene()->views().isEmpty()){
    scene()->views().first()->centerOn(this);
    }
}

void Sprite::left()
{
    posx-=velpos_in_x;
    mov_dir_x=posx;
    qDebug()<<"negativo en x "<<velpos_in_x;
    setPos(posx,posy);
    Direction='L';
//    qDebug()<<"pos in y "<<posy<<endl;
   // qDebug()<<"pos in x "<<posx<<endl;
    if(!scene()->views().isEmpty()){
    scene()->views().first()->centerOn(this);
    }
}

void Sprite::right()
{
    posx+=velneg_in_x;
    mov_dir_x=posx;
    qDebug()<<"positivo en x "<<velneg_in_x;
    setPos(posx,posy);
    Direction='R';
//    qDebug()<<"pos in y "<<posy<<endl;
    //qDebug()<<"pos in x "<<posx<<endl;
    if(!scene()->views().isEmpty()){
    scene()->views().first()->centerOn(this);
    }
}

void Sprite::Actualizacion()
{
    columnas +=60;
    if(columnas>=maximo){
        columnas=minimo;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}

QRectF Sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);

}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkMagenta);
    painter->drawEllipse(boundingRect());
}

void Sprite::CalcularVelocidad()
{
    velx= velocidad*cos(angulo);
    vely=velocidad*sin(angulo)-9.8*tiempo;
}

void Sprite::CalcularPosicion()
{
    posx+=velx*tiempo;
    posy-=vely*tiempo-0.5*9.8*pow(tiempo,2);
    setPos(posx,posy);
}

void Sprite::ActualizarVelocidad()
{
    velocidad=sqrt(pow(velx,2)+pow(vely,2));
    angulo=atan2(vely,velx);
}
// ...

bool Sprite::collidesWithWall(const QRectF& rect)
{
    QList<QGraphicsItem*> collisions = collidingItems();
    foreach (QGraphicsItem* item, collisions) {
        if (dynamic_cast<Muro*>(item)) {
            if (rect.intersects(item->boundingRect())) {
                return true; // Hay colisión con el muro
            }
        }
    }
    return false; // No hay colisión con el muro
}

// ...
