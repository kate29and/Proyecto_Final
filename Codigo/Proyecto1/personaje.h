#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class Personaje : public QObject, public QGraphicsItem
{

private:
    int posx, posy, radio, velocidad;
    int maximo, minimo;
    QTimer *timer;
    QPixmap pixmap;
    float filas, columnas;
    float ancho, alto;

    void MinMax(int num);

public:
    explicit Personaje(int x, int y, int r, QObject *parent = nullptr);

    int getPosx() const;
    void setPosx(int newPosx);

    int getPosy() const;
    void setPosy(int newPosy);

    int getVelocidad() const;
    void setVelocidad(int newVelocidad);

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

signals:

public slots:
    void Actualizar();
};

#endif  // PERSONAJE_H
