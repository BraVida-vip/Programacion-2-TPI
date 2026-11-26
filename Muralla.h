#ifndef MURALLA_H
#define MURALLA_H
#include "Defensa.h"
using namespace std;
class Fortaleza;

class Muralla : public Defensa {

public:
    Muralla();
    explicit Muralla(int id);
    void atacar() override;
    string getTipo() const override;

    void aumentarResistencia(Fortaleza& fortaleza);
};

#endif
