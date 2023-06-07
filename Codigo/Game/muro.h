#ifndef MURO_H
#define MURO_H
#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>
#include <iostream>
#include <QDebug>

using namespace std;


class Muro : public QGraphicsItem
{
private:
    float px, py;
    float dx, dy;


public:
    Muro(float px, float py);
    Muro(float px, float py,char);
    virtual QRectF boundingRect() const;
    virtual void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
        QWidget *widget = nullptr);
    float getPx() const;
    float getPy() const;
    void setPy(float newPy);
};

#endif // MURO_H
