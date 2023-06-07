#ifndef OBJETOS_H
#define OBJETOS_H

#include "fisicas.h"

#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QPixmap>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>
#include <QDebug>
#include <math.h>
using namespace std;

#define MK 0.5
#define tiempo 0.01
class Objetos : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    char Direction;
    float angulo= (86*3.14159)/180;
    float velocidad=40;
    float velx=10;
    float vely=10;

public:
    explicit Objetos(QObject *parent = nullptr);

    QTimer* timer;
    QPixmap * pixmap;
    float posx=175
        ,posy=547.841;
    float filas, columnas;
    float alto, ancho;
    int minimo=60,
        maximo=180;
    //orientacion del pacman
    void orientacion(int);
    float velpos_in_y=4;
    float velneg_in_y=4;
    float velpos_in_x=20;
    float velneg_in_x=20;
    float mov_dir_x=0;
    float mov_dir_y=0;
    //posicion del pacman
    void setPosx(float newPosx);
    void setPosy(float newPosy);
    float getPosx() const;
    float getPosy() const;
    //movimientos
    void up();
    void down();
    void left();
    void right();

    void CalcularVelocidad();
    void CalcularPosicion();
    void ActualizarVelocidad();

    QRectF boundingRect() const;
    void paint(QPainter*painter, const QStyleOptionGraphicsItem *option, QWidget* widget);
    char getDirection() const;
    void setDirection(char newDirection);

signals:

public slots:
    void Actualizacion();
};


/*class Objetos:public QGraphicsItem
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

};*/

#endif // OBJETOS_H
