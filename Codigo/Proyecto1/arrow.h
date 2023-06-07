// arrow.h
#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QPainter>


class Arrow : public QObject, public QGraphicsItem
{


public:
    Arrow(int x, int y);
    QRectF boundingRect() const;//forma de rectangulo con el que puedo referenciar cualquier obj
    void paint(QPainter *painter, //pintar objeto
               const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void inicializar();
    void movimiento1();

private:
    QTimer *time;
    float dimx;
    float dimy;
    float u=10.0;
    float a= 2.0;
    float t= 0.033;

};

#endif // ARROW_H
