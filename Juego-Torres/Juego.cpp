#include "Juego.h"
#include <iostream>
Juego::Juego() = default;
void Juego::mostrarMenu() { std::cout << "=== ELDORIA ===\\n1. Iniciar partida\\n0. Salir\\n"; }
void Juego::iniciarPartida() { partidaActual = Partida(1, jugadorActual.getIdJugador(), 1); }
void Juego::ejecutar() { mostrarMenu(); }
Jugador& Juego::getJugadorActual() { return jugadorActual; }
Partida& Juego::getPartidaActual() { return partidaActual; }
