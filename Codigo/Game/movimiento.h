#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <math.h>

#define tiempo 0.01

class Movimiento
{

    float posx,posy,velocidad, angulo,velx,vely;

public:
    Movimiento();
    Movimiento(double x, double y,double v, double a);
    void CalcularVelocidad();
    void CalcularPosicion();
    void ActualizarVelocidad();
    float getPosy() const;
    float getPosx() const;
};

#endif // MOVIMIENTO_H
