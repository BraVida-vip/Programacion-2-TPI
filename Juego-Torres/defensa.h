#ifndef DEFENSA_H
#define DEFENSA_H

#include <string>

class Defensa {
protected:
    int id;
    std::string nombre;
    int danio;
    int costo;
    int nivel;

public:
    Defensa(int i, std::string n, int d, int c);

    int atacar();

    void mejorar();

    int getDanio();
    int getNivel();
    int getCosto();
    std::string getNombre();
};

#endif
