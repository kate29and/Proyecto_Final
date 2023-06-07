#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
class Personaje : public QObject, public QGraphicsItem {
private:
    int posx;
    int posy;
    int velocidad;
    QColor color;

public:
    Personaje(int x, int y, int width, int height);    int getPosx() const;
    void setPosx(int newPosx);
    int getPosy() const;
    void setPosy(int newPosy);
    int getVelocidad() const;
    QColor getColor() const;
    void setColor(const QColor& newColor);



    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
};

#endif  // PERSONAJE_H
