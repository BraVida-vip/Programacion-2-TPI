#include "Orco.h"
Orco::Orco() : Enemigo(0, "Orco", 0, 50, 5, 1, 1.0f, 10, 1) {}
Orco::Orco(int id) : Enemigo(id, "Orco", 0, 50, 5, 1, 1.0f, 10, 1) {}
void Orco::atacar() {}
