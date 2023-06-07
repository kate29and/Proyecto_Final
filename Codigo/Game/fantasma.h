#ifndef FANTASMA_H
#define FANTASMA_H
#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QPixmap>
#include <iostream>
#include <QDebug>
using namespace std;

class Fantasma:public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    char Direction;

public:
    explicit Fantasma(QObject *parent = nullptr);

    QTimer* timer_f;
    QPixmap * pixmap_f;
    float posxf=282
         ,posyf=300;
    float filas, columnas;
    float alto, ancho;
    int minimo=0,
        maximo=90;
    //orientacion del pacman
    void orientacion(int);
    float velpos_in_y=4;
    float velneg_in_y=4;
    float velpos_in_x=4;
    float velneg_in_x=4;
    float mov_dir_x=0;
    float mov_dir_y=0;
    //posicion del pacman
    void setPosxf(float newPosx);
    void setPosyf(float newPosy);
    float getPosxf() const;
    float getPosyf() const;
    //movimientos
    void up();
    void down();
    void left();
    void right();

    QRectF boundingRect() const;
    void paint(QPainter*painter, const QStyleOptionGraphicsItem *option, QWidget* widget);
    char getDirection() const;
    void setDirection(char newDirection);

signals:

public slots:
    void Actualizacion();
};
#endif // FANTASMA_H
