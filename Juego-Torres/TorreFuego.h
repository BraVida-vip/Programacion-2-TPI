#ifndef TORREFUEGO_H
#define TORREFUEGO_H
#include "Defensa.h"
class TorreFuego : public Defensa {
public:
    TorreFuego();
    explicit TorreFuego(int id);
    void atacar() override;
    std::string getTipo() const override;
    void lanzarArea();
};
#endif
