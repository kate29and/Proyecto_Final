#include "fantasma.h"

#include <QPainter>
char Fantasma::getDirection() const
{
    return Direction;
}

void Fantasma::setDirection(char newDirection)
{
    Direction = newDirection;
}
Fantasma::Fantasma(QObject *parent) : QObject(parent)
{
   timer_f =new QTimer();
   filas=1;
   columnas=0;

   //dimenciones de cada una de las imagenes
   alto=30;
   ancho=30;
   //velosidad de iteraciones
   timer_f->start(250);
   connect(timer_f,&QTimer::timeout,this,&Fantasma::Actualizacion);
   setPos(posxf,posyf);

}

void Fantasma::orientacion(int num)
{
    switch (num) {
    case 0:
        minimo=0;
        maximo=30;
        columnas=minimo;
    break;
    case 1:
        minimo=30;
        maximo=60;
        columnas=minimo;
    break;
    case 2:
        minimo=60;
        maximo=90;
        columnas=minimo;
    break;
    case 3:
        minimo=90;
        maximo=120;
        columnas=minimo;
    break;

    }
}


float Fantasma::getPosxf() const
{
    return posxf;
}
float Fantasma::getPosyf() const
{
    return posyf;
}
void Fantasma::setPosxf(float newPosX)
{
    posxf = newPosX;
}
void Fantasma::setPosyf(float newPosY)
{
    posyf = newPosY;
}


void Fantasma::up()
{
    posyf-=velpos_in_y;
    mov_dir_y=posyf;
    qDebug()<<"negativo en y "<<velpos_in_y;
    setPos(posxf,posyf);//dan la nueva posicion
    Direction='U';
    //qDebug()<<"pos in y "<<posyf<<endl;
//    qDebug()<<"pos in x "<<posx<<endl;
}

void Fantasma::down()
{
    posyf+=velneg_in_y;
    mov_dir_y=posyf;
    qDebug()<<"positivo en y "<<velneg_in_y;
    setPos(posxf,posyf);
    Direction='D';
    //qDebug()<<"pos in y "<<posyf<<endl;
//    qDebug()<<"pos in x "<<posx<<endl;
}

void Fantasma::left()
{
    posxf-=velpos_in_x;
    mov_dir_x=posxf;
    qDebug()<<"negativo en x "<<velpos_in_x;
    setPos(posxf,posyf);
    Direction='L';
//    qDebug()<<"pos in y "<<posy<<endl;
    //qDebug()<<"pos in x "<<posxf<<endl;
}

void Fantasma::right()
{
    posxf+=velneg_in_x;
    mov_dir_x=posxf;
    qDebug()<<"positivo en x "<<velneg_in_x;
    setPos(posxf,posyf);
    Direction='R';
//    qDebug()<<"pos in y "<<posy<<endl;
    //qDebug()<<"pos in x "<<posxf<<endl;
}

void Fantasma::Actualizacion()
{
    columnas +=30;
    if(columnas>=maximo){
        columnas=minimo;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF Fantasma::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Fantasma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap_f,columnas,30,ancho,alto);
}

