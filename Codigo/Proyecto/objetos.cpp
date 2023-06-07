#include "objetos.h"

Objetos::Objetos(int x, int y)
{
    dimx=15;
    dimy=15;
    setPos(x, y);

}

QRectF Objetos::boundingRect() const
{
    return QRectF(0,0,dimx,dimy);
}


void Objetos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}
void Objetos::mover()
{
    fisicas.get(); // Llama al método get() de la clase Fisicas para actualizar las físicas
    setPos(fisicas.getX(), fisicas.getY()); // Actualiza la posición del objeto en función de las físicas
}

void Objetos::caidaLibre()
{
    // Aplicar la aceleración a la velocidad
    velocityY += accelerationY;

    // Actualizar la posición con la velocidad
    posY += velocityY;

    // Aplicar restricciones de límites si es necesario
    // Por ejemplo, si quieres que el objeto no caiga más allá de cierto punto:
    if (posY > limiteInferior) {
        posY = limiteInferior;
        velocityY = 0.0; // Detener el movimiento vertical
    }

    // Actualizar la posición del objeto en la escena
    setPos(posX, posY);
}
