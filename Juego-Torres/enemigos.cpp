#include "Enemigos.h"

Enemigo::Enemigo(int id, std::string nom, int v, int d, int r)
{
    idEnemigo = id;
    nombre = nom;
    vida = v;
    danio = d;
    recompensa = r;
}

void Enemigo::recibirDanio(int cantidad)
{
    vida -= cantidad;

    if (vida < 0)
        vida = 0;
}

bool Enemigo::estaVivo()
{
    return vida > 0;
}

int Enemigo::getVida()
{
    return vida;
}

int Enemigo::getDanio()
{
    return danio;
}

int Enemigo::getRecompensa()
{
    return recompensa;
}

std::string Enemigo::getNombre()
{
    return nombre;
}
