#ifndef BESTIAOSCURA_H
#define BESTIAOSCURA_H
#include "Enemigo.h"
class BestiaOscura : public Enemigo {
public:
    BestiaOscura();
    explicit BestiaOscura(int id);
    void atacar() override;
    void usarMagiaNegra();
};
#endif
