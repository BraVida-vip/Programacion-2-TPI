#ifndef JUEGO_H
#define JUEGO_H
#include "Jugador.h"
#include "Partida.h"
class Juego {
private:
    Jugador jugadorActual;
    Partida partidaActual;
public:
    Juego();
    void mostrarMenu();
    void iniciarPartida();
    void ejecutar();
    Jugador& getJugadorActual();
    Partida& getPartidaActual();
};
#endif
