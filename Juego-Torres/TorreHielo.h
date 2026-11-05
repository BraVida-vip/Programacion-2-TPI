#ifndef TORREHIELO_H
#define TORREHIELO_H
#include "Defensa.h"
class TorreHielo : public Defensa {
public:
    TorreHielo();
    explicit TorreHielo(int id);
    void atacar() override;
    std::string getTipo() const override;
    void ralentizarEnemigo();
};
#endif
