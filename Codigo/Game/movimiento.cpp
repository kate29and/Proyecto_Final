#include "movimiento.h"

float Movimiento::getPosy() const
{
    return posy;
}

float Movimiento::getPosx() const
{
    return posx;
}

Movimiento::Movimiento(double x, double y, double v, double a)
{
    this->posx=x;
    this->posy=y;
    this->angulo=a;
    this->velocidad=v;
}

void Movimiento::CalcularVelocidad()
{
    velx= velocidad*cos(angulo);
    vely=velocidad*sin(angulo)-9.8*tiempo;
}

void Movimiento::CalcularPosicion()
{
    posx+=velx*tiempo;
    posy+=vely*tiempo-0.5*9.8*pow(tiempo,2);
}

void Movimiento::ActualizarVelocidad()
{
    velocidad=sqrt(pow(velx,2)+pow(vely,2));
    angulo=atan2(vely,velx);
}
