#ifndef DEFENSACOLOCADA_H
#define DEFENSACOLOCADA_H
#include "Defensa.h"
class DefensaColocada {
private:
    int idColocacion, idPartida, idTorre, posicion, nivelActual;
    bool mejorada;
    Defensa* defensa;
public:
    DefensaColocada();
    DefensaColocada(int idColocacion, int idPartida, int idTorre, int posicion, Defensa* defensa);
    void mejorarNivel();
    void eliminar();
    Defensa* getDefensa() const;
    int getPosicion() const;
    bool estaMejorada() const;
};
#endif
