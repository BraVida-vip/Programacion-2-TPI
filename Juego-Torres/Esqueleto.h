#ifndef ESQUELETO_H
#define ESQUELETO_H
#include "Enemigo.h"
class Esqueleto : public Enemigo {
public:
    Esqueleto();
    explicit Esqueleto(int id);
    void atacar() override;

};
#endif
