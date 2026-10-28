#include "Defensa.h"

Defensa::Defensa(int i, std::string n, int d, int c)
{
    id = i;
    nombre = n;
    danio = d;
    costo = c;
    nivel = 1;
}

int Defensa::atacar()
{
    return danio;
}

void Defensa::mejorar()
{
    nivel++;
    danio += 20;
}

int Defensa::getDanio()
{
    return danio;
}

int Defensa::getNivel()
{
    return nivel;
}

int Defensa::getCosto()
{
    return costo;
}

std::string Defensa::getNombre()
{
    return nombre;
}
