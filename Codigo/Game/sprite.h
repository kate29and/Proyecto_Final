#ifndef SPRITE_H
#define SPRITE_H

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

#include "Muro.h"

using namespace std;

#define MK 0.5
#define tiempo 0.01
class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    char Direction;
    float angulo= (86*3.14159)/180;
    float velocidad=40;
    float velx=10;
    float vely=10;

public:
    explicit Sprite(QObject *parent = nullptr);

    QTimer* timer;
    QPixmap * pixmap;
    float posx=175
         ,posy=547.841;
    float filas, columnas;
    float alto, ancho;
    int minimo=60,
        maximo=180;
    //orientacion
    void orientacion(int);
    float velpos_in_y=4;
    float velneg_in_y=4;
    float velpos_in_x=20;
    float velneg_in_x=20;
    float mov_dir_x=0;
    float mov_dir_y=0;
    //posicion del
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

    bool collidesWithWall(const QRectF& rect);
signals:

public slots:
    void Actualizacion();
};

#endif // SPRITE_H
