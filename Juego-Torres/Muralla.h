#ifndef MURALLA_H
#define MURALLA_H

#include "Defensa.h"

class Fortaleza;

class Muralla : public Defensa {

public:
    Muralla();
    explicit Muralla(int id);

    void atacar() override;
    std::string getTipo() const override;

    void aumentarResistencia(Fortaleza& fortaleza);
};

#endif
