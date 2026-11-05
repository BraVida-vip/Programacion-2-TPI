#include "Nigromante.h"
Nigromante::Nigromante() : Enemigo(0, "Nigromante", 0, 50, 5, 1, 1.0f, 10, 1) {}
Nigromante::Nigromante(int id) : Enemigo(id, "Nigromante", 0, 50, 5, 1, 1.0f, 10, 1) {}
void Nigromante::atacar() {}
void Nigromante::invocarEsqueletos() {}
