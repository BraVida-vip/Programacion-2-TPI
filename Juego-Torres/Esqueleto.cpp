#include "Esqueleto.h"
Esqueleto::Esqueleto() : Enemigo(0, "Esqueleto", 0, 50, 5, 1, 1.0f, 10, 1) {}
Esqueleto::Esqueleto(int id) : Enemigo(id, "Esqueleto", 0, 50, 5, 1, 1.0f, 10, 1) {}
void Esqueleto::atacar() {}
