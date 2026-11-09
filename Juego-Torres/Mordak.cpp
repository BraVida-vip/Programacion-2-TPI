#include "Mordak.h"

Mordak::Mordak()
    : Enemigo(0, "Mordak", 0, 10000, 500, 2, 0.8f, 10, 1) {}

Mordak::Mordak(int id)
    : Enemigo(id, "Mordak", 0, 10000, 500, 2, 0.8f, 10, 1) {}

void Mordak::atacar() {}

void Mordak::usarMagiaNegra() {}

void Mordak::lanzarHechizo() {}

