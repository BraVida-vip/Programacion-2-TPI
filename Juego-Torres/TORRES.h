#ifndef TORRES_H_INCLUDED
#define TORRES_H_INCLUDED
#include "Defensa.h"
class TorreArquera : public Defensa {
public:
    TorreArquera();
    explicit TorreArquera(int id);
    void atacar() override;
    std::string getTipo() const override;
    void dispararRapido();
};

class TorreFuego : public Defensa {
public:
    TorreFuego();
    explicit TorreFuego(int id);
    void atacar() override;
    std::string getTipo() const override;
    void lanzarArea();
};

class TorreHielo : public Defensa {
public:
    TorreHielo();
    explicit TorreHielo(int id);
    void atacar() override;
    std::string getTipo() const override;
    void ralentizarEnemigo();
};
#endif
