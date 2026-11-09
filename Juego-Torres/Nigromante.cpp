#include "Nigromante.h"

Nigromante::Nigromante()
    : Enemigo(0, "Nigromante", 0, 7500, 250, 2, 0.75f, 10, 1) {}

Nigromante::Nigromante(int id)
    : Enemigo(id, "Nigromante", 0, 7500, 250, 2, 0.75f, 10, 1) {}

void Nigromante::atacar() {}

void Nigromante::invocarEsqueletos() {}
