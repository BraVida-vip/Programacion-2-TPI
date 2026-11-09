#include "Goblin.h"

Goblin::Goblin()
    : Enemigo(0, "Goblin", 0, 2000, 10, 1, 1.5f, 10, 1) {}

Goblin::Goblin(int id)
    : Enemigo(id, "Goblin", 0, 2000, 10, 1, 1.5f, 10, 1) {}

void Goblin::atacar() {}
