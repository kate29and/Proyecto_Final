#include "fisicas.h"

Fisicas::Fisicas()
{

}
/*void Fisicas::saltar(QGraphicsRectItem* personaje)
{
    if (!jmp) {
        jmp = true;
        cai = false;
        personaje->setPos(personaje->x()+7, personaje->y() - 65); // Mover el objeto hacia arriba
        QTimer::singleShot(250, [this, personaje]() {
            personaje->setPos(personaje->x()+7, personaje->y() + 65); // Mover el objeto hacia abajo después de un tiempo
            jmp = false;
            cai = true;
        });
    }
}*/
void Fisicas:: inicializar()
{
    u = 10.0; // Velocidad inicial hacia la derecha
    a = 2.0; // Aceleración hacia la derecha
    t = 0.33; // Intervalo de tiempo (33 milisegundos)

    time->start(33);
}
void Fisicas:: movimiento()
{
    // Calcular el desplazamiento usando la fórmula del movimiento rectilíneo acelerado
    float displacement = u * t + (0.5 * a * t * t);

    // Actualizar la posición de la flecha sumando el desplazamiento al componente horizontal
    setPos(x() + displacement, y());

    // Actualizar la velocidad con la aceleración
    u += a;
}

QRectF Fisicas::boundingRect() const {
    // Return the bounding rectangle of your custom item
    return QRectF(-20, -20, 40, 40);
}

void Fisicas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    // Draw your custom item using the provided painter object
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(QBrush(Qt::yellow));
    painter->drawEllipse(-20, -20, 40, 40);
}

void Fisicas::get()
{
    vel2();
    vel();
    post();
}
void Fisicas::post()
{
    if (tipo == -1) {
        px -= vx * tiempo;
        py -= (vy * tiempo) + (0.5 * 9.8) * pow(tiempo, 2);
    }
    else if (tipo == 1) {
        px += vx * tiempo;
        py -= (vy * tiempo) + (0.5 * 9.8) * pow(tiempo, 2);
    }
    setPos(px, py);
}

void Fisicas::vel()
{
    vy = v * sin(ang) - 9.8 * tiempo;
}

void Fisicas::vel2()
{
    v = sqrt(pow(vx, 2) + pow(vy, 2));
    ang = atan2(vy, vx);
}
float Fisicas::getX() const {
    return px; // Devuelve la coordenada x
}

float Fisicas::getY() const {
    return py; // Devuelve la coordenada y
}
