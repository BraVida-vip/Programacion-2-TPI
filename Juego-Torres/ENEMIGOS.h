#ifndef ENEMIGOS_H_INCLUDED
#define ENEMIGOS_H_INCLUDED

#include "Enemigo.h"
class BestiaOscura : public Enemigo {
public:
    BestiaOscura();
    explicit BestiaOscura(int id);
    void atacar() override;
    void usarMagiaNegra();
};

class Esqueleto : public Enemigo {
public:
    Esqueleto();
    explicit Esqueleto(int id);
    void atacar() override;

};

class Goblin : public Enemigo {
public:
    Goblin();
    explicit Goblin(int id);
    void atacar() override;

};

class Mordak : public Enemigo {
public:
    Mordak();
    explicit Mordak(int id);
    void atacar() override;
    void usarMagiaNegra();
    void lanzarHechizo();
};

class Nigromante : public Enemigo {
public:
    Nigromante();
    explicit Nigromante(int id);
    void atacar() override;
    void invocarEsqueletos();
};
class Orco : public Enemigo {
public:
    Orco();
    explicit Orco(int id);
    void atacar() override;

};


#endif // ENEMIGOS_H_INCLUDED
