#ifndef ORCO_H
#define ORCO_H
#include "Enemigo.h"
class Orco : public Enemigo {
public:
    Orco();
    explicit Orco(int id);
    void atacar() override;

};
#endif
