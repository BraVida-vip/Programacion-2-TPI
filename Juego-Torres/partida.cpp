#include "Partida.h"

Partida::Partida()
{
    diaActual = 1;
    oro = 500;
    resistenciaCastillo = 1000;
}

void Partida::avanzarDia()
{
    if (diaActual < 7)
    {
        diaActual++;
    }
}

void Partida::sumarOro(int cantidad)
{
    oro += cantidad;
}

bool Partida::gastarOro(int cantidad)
{
    if (oro >= cantidad)
    {
        oro -= cantidad;
        return true;
    }

    return false;
}

void Partida::recibirDanio(int cantidad)
{
    resistenciaCastillo -= cantidad;

    if (resistenciaCastillo < 0)
    {
        resistenciaCastillo = 0;
    }
}

bool Partida::juegoTerminado()
{
    return resistenciaCastillo <= 0 || diaActual >= 7;
}

bool Partida::victoria()
{
    return diaActual >= 7 && resistenciaCastillo > 0;
}

int Partida::getDia()
{
    return diaActual;
}

int Partida::getOro()
{
    return oro;
}

int Partida::getResistencia()
{
    return resistenciaCastillo;
}
