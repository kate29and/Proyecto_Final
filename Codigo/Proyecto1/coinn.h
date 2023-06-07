
#ifndef COINN_H
#define COINN_H

#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>

using namespace std;
class Coinn : public QGraphicsItem
{
    int posx, posy;
    int dimx, dimy;
    int coinTipe;

public:
    Coinn(int, int);
    Coinn(int , int , int );
    virtual QRectF boundingRect() const;
    virtual void paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget = nullptr);
    int getcoin() const;
    void setcoin(int newcoinTipe);
};

#endif // COIN_H
