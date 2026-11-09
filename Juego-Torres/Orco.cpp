#include "Orco.h"

Orco::Orco()
    : Enemigo(0, "Orco", 0, 3000, 50, 1, 0.7f, 10, 1) {}

Orco::Orco(int id)
    : Enemigo(id, "Orco", 0, 3000, 50, 1, 0.7f, 10, 1) {}

void Orco::atacar() {}
