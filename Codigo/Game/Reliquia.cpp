#include "Reliquia.h"
#include <QPainter>


// ...
Reliquia::Reliquia()
{
    dx = 15;
    dy = 15;
}

Reliquia::Reliquia(float px, float py) : px(px), py(py)
{
    dx = 16;
    dy = 16;
    setPos(px, py);
}

QRectF Reliquia::boundingRect() const
{
    return QRectF(0, 0, dx, dy);
}

void Reliquia::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
}

/*void Reliquia::AplicarFisica()
{
    // Implement the logic for applying physics to the relic, such as gravity and vertical movement.
    // ...
}
void Reliquia::saltar1()
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
}
void Reliquia::Saltar()
{
    if (!isJumping) {
        isJumping = true;
        currentHeight = 0;
        // Adjust the jump speed to achieve the desired height
        jumpSpeed = sqrt(2 * jumpHeight * Gravedad);
    }
}

bool Reliquia::collidesWithWall(const QRectF& rect)
{
    QList<QGraphicsItem*> collisions = collidingItems();
    foreach (QGraphicsItem* item, collisions) {
        if (dynamic_cast<Muro*>(item)) {
            if (rect.intersects(item->boundingRect())) {
                return true; // There is a collision with the wall
            }
        }
    }
    return false; // No collision with the wall
}
float Reliquia::getPosy() const
{
    return py;
}

void Reliquia::advance(int phase)
{

        // Update game logic in advance phase 0

        // ...

        // Check if a jump is being performed and update the vertical position
        if (isJumping) {
            currentHeight += jumpSpeed;

            // Calculate the new vertical position based on the current jump height
            float newPosY = posicionY - velocidadY + (0.5f * Gravedad);

            // Check if the new position causes a collision with a wall
            QRectF newRect = QRectF(px, newPosY, dx, dy);
            if (!collidesWithWall(newRect)) {
                // If no collision, update the position and velocity
                posicionY = newPosY;
                velocidadY -= Gravedad;
            } else {
                // If collision, stop the jump and adjust the final position of the sprite
                isJumping = false;
                posicionY = py;
            }

            setPos(px, posicionY);

            // Check if the maximum jump height has been reached or if the character has landed on the ground
            if (currentHeight >= jumpHeight || posicionY == py) {
                isJumping = false;
                // Adjust the final position of the sprite to ground level
                setPos(px, py);
            }
        }
    }

}*/
/*char Reliquia::getDirection() const
{
    return Direction;
}

void Reliquia::setDirection(char newDirection)
{
    Direction = newDirection;
}
Reliquia::Reliquia(QObject *parent) : QObject(parent)
{
    timer =new QTimer();
    filas=0;
    columnas=0;

    // pixmap =new QPixmap(":/move.png");
    //dimenciones de cada una de las imagenes
    alto=30;
    ancho=30;
    //velosidad de iteraciones
    setPos(posx,posy);


}

void Reliquia::orientacion(int num)
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


float Reliquia::getPosx() const
{
    return posx;
}
float Reliquia::getPosy() const
{
    return posy;
}
void Reliquia::setPosx(float newPosX)
{
    posx = newPosX;
}
void Reliquia::setPosy(float newPosY)
{
    posy = newPosY;
}

*/
/*void Reliquia::up()
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

void Reliquia::down()
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
}*/

/*void Reliquia::left()
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

void Reliquia::right()
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

void Reliquia::Actualizacion()
{
    columnas +=60;
    if(columnas>=maximo){
        columnas=minimo;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}

QRectF Reliquia::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);

}

void Reliquia::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkMagenta);
    painter->drawEllipse(boundingRect());
}


*/

