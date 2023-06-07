#ifndef OBJETOS_H
#define OBJETOS_H

#include "fisicas.h"


#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>

class Objetos:public QGraphicsItem
{
public:
    int posx, posy;
    int dimx, dimy;
    int velocityY,accelerationY,posX,posY,limiteInferior;
    int vidas();
    Objetos(int,int);
    void caidaLibre();
    virtual QRectF boundingRect() const;
    virtual void paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget = nullptr);
    void mover(); // Método para actualizar la posición del objeto en función de las físicas
private:

    void piedra(); //rotacion
    void pino();//caida
    Fisicas fisicas; // Instancia de la clase Fisicas

};

#endif // OBJETOS_H
