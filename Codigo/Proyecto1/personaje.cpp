#include "personaje.h"

Personaje::Personaje(int x, int y, int r, QObject *parent)
    : QObject(parent), QGraphicsItem(), posx(x), posy(y), radio(r), velocidad(2), filas(0), columnas(0), ancho(20), alto(20)
{
    setPos(posx, posy);

    timer = new QTimer(this);
    timer->start(150);
   // connect(timer, &QTimer::timeout, this, &Personaje::Actualizar);
}

int Personaje::getPosx() const
{
    return posx;
}

void Personaje::setPosx(int newPosx)
{
    posx = newPosx;
}

int Personaje::getPosy() const
{
    return posy;
}

void Personaje::setPosy(int newPosy)
{
    posy = newPosy;
}

int Personaje::getVelocidad() const
{
    return velocidad;
}

void Personaje::setVelocidad(int newVelocidad)
{
    velocidad = newVelocidad;
}

/*void Personaje::MinMax(int num)
{
    switch (num) {
    case 1:
        minimo = 0;
        maximo = 90;
        columnas = minimo;
        break;
    case 2:
        minimo = 120;
        maximo = 180;
        columnas = minimo;
        break;
    case 3:
        minimo = 210;
        maximo = 270;
        columnas = minimo;
        break;
    case 4:
        minimo = 300;
        maximo = 360;
        columnas = minimo;
        break;
    }
}*/

QRectF Personaje::boundingRect() const
{
    return QRectF(-ancho / 2, -alto / 2, ancho, alto);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());
    // painter->drawPixmap(-ancho / 2, -alto / 2, pixmap, columnas, 0, ancho, alto);
}

/*void Personaje::Actualizar()
{
    columnas += 30;
    if (columnas == maximo)
        columnas = minimo;

    update(-ancho / 2, -alto / 2, ancho, alto);
}*/
