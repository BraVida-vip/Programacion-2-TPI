#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <string>

class Enemigo {
protected:
    int idEnemigo;
    std::string nombre;
    int vida;
    int danio;
    int recompensa;

public:
    Enemigo(int id, std::string nom, int v, int d, int r);

    void recibirDanio(int cantidad);

    bool estaVivo();

    int getVida();
    int getDanio();
    int getRecompensa();
    std::string getNombre();
};

#endif
