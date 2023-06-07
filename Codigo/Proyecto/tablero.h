#ifndef TABLERO_H
#define TABLERO_H


#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>

using namespace std;

class Tablero : public QGraphicsItem
{
    int posx, posy;
    int dimx, dimy;
    int MuroTipe;

public:
    Tablero(int, int );
    Tablero(int , int , int );

    virtual QRectF boundingRect() const;
    virtual void paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget = nullptr);
    int getMuroTipe() const;
    void setMuroTipe(int newMuroTipe);
};

#endif // MUROS_H



