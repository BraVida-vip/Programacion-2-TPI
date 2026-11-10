#include "ENEMIGOS.h"

BestiaOscura::BestiaOscura()
    : Enemigo(0, "BestiaOscura", 0, 5000, 100, 1, 1.0f, 10, 1) {}

BestiaOscura::BestiaOscura(int id)
    : Enemigo(id, "BestiaOscura", 0, 5000, 100, 1, 1.0f, 10, 1) {}

void BestiaOscura::atacar() {}

void BestiaOscura::usarMagiaNegra() {}


Esqueleto::Esqueleto()
    : Enemigo(0, "Esqueleto", 0, 1000, 5, 1, 1.0f, 10, 1) {}

Esqueleto::Esqueleto(int id)
    : Enemigo(id, "Esqueleto", 0, 1000, 5, 1, 1.0f, 10, 1) {}

void Esqueleto::atacar() {}


Goblin::Goblin()
    : Enemigo(0, "Goblin", 0, 2000, 10, 1, 1.5f, 10, 1) {}

Goblin::Goblin(int id)
    : Enemigo(id, "Goblin", 0, 2000, 10, 1, 1.5f, 10, 1) {}

void Goblin::atacar() {}


Mordak::Mordak()
    : Enemigo(0, "Mordak", 0, 10000, 500, 2, 0.8f, 10, 1) {}

Mordak::Mordak(int id)
    : Enemigo(id, "Mordak", 0, 10000, 500, 2, 0.8f, 10, 1) {}

void Mordak::atacar() {}

void Mordak::usarMagiaNegra() {}

void Mordak::lanzarHechizo() {}


Nigromante::Nigromante()
    : Enemigo(0, "Nigromante", 0, 7500, 250, 2, 0.75f, 10, 1) {}

Nigromante::Nigromante(int id)
    : Enemigo(id, "Nigromante", 0, 7500, 250, 2, 0.75f, 10, 1) {}

void Nigromante::atacar() {}

void Nigromante::invocarEsqueletos() {}


Orco::Orco()
    : Enemigo(0, "Orco", 0, 3000, 50, 1, 0.7f, 10, 1) {}

Orco::Orco(int id)
    : Enemigo(id, "Orco", 0, 3000, 50, 1, 0.7f, 10, 1) {}

void Orco::atacar() {}

