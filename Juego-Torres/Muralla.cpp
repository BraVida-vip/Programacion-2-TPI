#include "Muralla.h"
#include "Fortaleza.h"

Muralla::Muralla()
    : Defensa(0, "Muralla", 3, 0, 0, 0.0f, 75, 1) {}

Muralla::Muralla(int id)
    : Defensa(id, "Muralla", 3, 0, 0, 0.0f, 75, 1) {}

void Muralla::atacar() {}

std::string Muralla::getTipo() const {
    return "Muralla";
}

void Muralla::aumentarResistencia(Fortaleza& fortaleza) {
    fortaleza.aumentarResistencia(50);
}
