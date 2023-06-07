#ifndef RELIQUIA_H
#define RELIQUIA_H
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
class Reliquia : public QGraphicsItem
{
private:
    float px, py;
    float dx, dy;

    void setPosx(float newPosx);
    void setPosy(float newPosy);
    float getPosx() const;
    float getPosy() const;
    const float Gravedad = 0.5f;
    const float VelocidadSalto = 10.0f;

    // Variables de estado de la reliquia
    float posicionY = 0.0f;
    float velocidadY = 0.0f;
    bool enElAire = false;
    float jumpHeight;     // Altura máxima del salto
    float jumpSpeed;      // Velocidad de ascenso del salto
    float currentHeight;  // Altura actual durante el salto
    bool isJumping;       // Indicador de salto en curso

    // Función de actualización principal
    void Actualizar();

public:
    Reliquia();
    Reliquia(float px, float py);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    // Función para aplicar la gravedad y el salto
    //void AplicarFisica();

    // Función para hacer que la reliquia realice un salto
    //void Saltar();

    // Función para verificar colisiones con muros
    bool collidesWithWall(const QRectF& rect);

protected:
   // void advance(int phase) override;
};
/*#include <QObject>
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

class Reliquia : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    char Direction;

    bool jmp;
    bool rot;
    bool cai;

public:
    explicit Reliquia(QObject *parent = nullptr);

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


    void Actualizacion();

    QRectF boundingRect() const;
    void paint(QPainter*painter, const QStyleOptionGraphicsItem *option, QWidget* widget);
    char getDirection() const;
    void setDirection(char newDirection);



};*/
#endif // RELIQUIA_H




