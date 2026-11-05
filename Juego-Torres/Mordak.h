#ifndef MORDAK_H
#define MORDAK_H
#include "Enemigo.h"
class Mordak : public Enemigo {
public:
    Mordak();
    explicit Mordak(int id);
    void atacar() override;
    void usarMagiaNegra();
    void lanzarHechizo();
};
#endif
