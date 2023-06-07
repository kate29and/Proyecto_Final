#include "objetos.h"
#include <QPainter>

char Objetos::getDirection() const
{
    return Direction;
}

void Objetos::setDirection(char newDirection)
{
    Direction = newDirection;
}
Objetos::Objetos(QObject *parent) : QObject(parent)
{
    timer =new QTimer();
    filas=0;
    columnas=0;

    //dimenciones de cada una de las imagenes
    alto=30;
    ancho=30;
    //velosidad de iteraciones
    timer->start(150);
    connect(timer,&QTimer::timeout,this,&Objetos::Actualizacion);
    setPos(posx,posy);


}

void Objetos::orientacion(int num)
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


float Objetos::getPosx() const
{
    return posx;
}
float Objetos::getPosy() const
{
    return posy;
}
void Objetos::setPosx(float newPosX)
{
    posx = newPosX;
}
void Objetos::setPosy(float newPosY)
{
    posy = newPosY;
}


void Objetos::up()
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

void Objetos::down()
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

void Objetos::left()
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

void Objetos::right()
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

void Objetos::Actualizacion()
{
    columnas +=60;
    if(columnas>=maximo){
        columnas=minimo;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);

}

QRectF Objetos::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);

}

void Objetos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkMagenta);
    painter->drawEllipse(boundingRect());
}

void Objetos::CalcularVelocidad()
{
    velx= velocidad*cos(angulo);
    vely=velocidad*sin(angulo)-9.8*tiempo;
}

void Objetos::CalcularPosicion()
{
    posx+=velx*tiempo;
    posy-=vely*tiempo-0.5*9.8*pow(tiempo,2);
    setPos(posx,posy);
}

void Objetos::ActualizarVelocidad()
{
    velocidad=sqrt(pow(velx,2)+pow(vely,2));
    angulo=atan2(vely,velx);
}

/*Objetos::Objetos(int x, int y)
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
}*/
