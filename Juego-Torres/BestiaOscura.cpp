#include "BestiaOscura.h"

BestiaOscura::BestiaOscura()
    : Enemigo(0, "BestiaOscura", 0, 5000, 100, 1, 1.0f, 10, 1) {}

BestiaOscura::BestiaOscura(int id)
    : Enemigo(id, "BestiaOscura", 0, 5000, 100, 1, 1.0f, 10, 1) {}

void BestiaOscura::atacar() {}

void BestiaOscura::usarMagiaNegra() {}

