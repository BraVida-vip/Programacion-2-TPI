#ifndef GOBLIN_H
#define GOBLIN_H
#include "Enemigo.h"
class Goblin : public Enemigo {
public:
    Goblin();
    explicit Goblin(int id);
    void atacar() override;

};
#endif
