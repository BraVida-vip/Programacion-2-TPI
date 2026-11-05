#ifndef MURALLA_H
#define MURALLA_H
#include "Defensa.h"
class Muralla : public Defensa {
public:
    Muralla();
    explicit Muralla(int id);
    void atacar() override;
    std::string getTipo() const override;
    void aumentarResistencia();
};
#endif
