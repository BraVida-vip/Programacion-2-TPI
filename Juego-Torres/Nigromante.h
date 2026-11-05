#ifndef NIGROMANTE_H
#define NIGROMANTE_H
#include "Enemigo.h"
class Nigromante : public Enemigo {
public:
    Nigromante();
    explicit Nigromante(int id);
    void atacar() override;
    void invocarEsqueletos();
};
#endif
