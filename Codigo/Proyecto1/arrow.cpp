// arrow.cpp
#include "arrow.h"

Arrow::Arrow(int x, int y)
{
    dimx = 13;
    dimy = 13;
    setPos(x, y);


    time = new QTimer(this);

    connect(time, SIGNAL(timeout()), this, SLOT(movimiento1()));
    time->start(33);  // Iniciar el temporizador con un intervalo de 33 milisegundos

}

QRectF Arrow::boundingRect() const
{
    return QRectF(0, 0, dimx, dimy);
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::magenta);
    painter->drawEllipse(boundingRect());

}



void Arrow::movimiento1()
{

    // Calcular el desplazamiento usando la fórmula del movimiento rectilíneo acelerado
    float displacement = u * t + (0.5 * a * t * t);

    // Actualizar la posición de la flecha sumando el desplazamiento al componente horizontal
    setPos(x() + displacement, y());

    // Actualizar la velocidad con la aceleración
    u += a;
}
