#include "Muralla.h"
Muralla::Muralla() : Defensa(0, "Muralla", 0, 10, 2, 1.0f, 50, 1) {}
Muralla::Muralla(int id) : Defensa(id, "Muralla", 0, 10, 2, 1.0f, 50, 1) {}
void Muralla::atacar() {}
std::string Muralla::getTipo() const { return "Muralla"; }
void Muralla::aumentarResistencia() { mejorar(); }
