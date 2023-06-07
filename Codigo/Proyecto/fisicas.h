#ifndef FISICAS_H
#define FISICAS_H

//#define G 6.67384 * pow(10,-11)


#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>

class Fisicas: public QGraphicsItem
{

public:
    Fisicas();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void post();
    void vel();
    void vel2();
    void get();
    float getX()const;
    float getY() const;
    float px=0.0,py=0.0,vx=0.0,vy=0.0,v=0.0;
    // Configurar variables de movimiento rectilíneo acelerado
    void inicializar();
    void  movimiento();




   /* void rotacion();
    void caida();*/
    //void saltar(QGraphicsRectItem* personaje);

private:
    QTimer* time ;
    float u; // Velocidad inicial
    float a; // Aceleración
    float t; // Intervalo de tiempo
    QTimer* tim;  // Temporizador para actualizar la animación
    qreal tiempo;
    QTimer *timer1;
    int tipo=0,ang=0;
    bool jmp;
    bool rot;
    bool cai;
};

#endif // FISICAS_H
