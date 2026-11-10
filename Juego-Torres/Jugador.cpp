#include "Jugador.h"
#include <iostream>

Jugador::Jugador() : idJugador(0), puntajeMaximo(0), nivelMaximo(1),
                     partidasJugadas(0), eliminado(false) {
    nombre[0] = '\0';
}

Jugador::Jugador(int id, const char* n) : idJugador(id), puntajeMaximo(0),
                                          nivelMaximo(1), partidasJugadas(0),
                                          eliminado(false) {
    setNombre(n);
}

void Jugador::actualizarEstadisticas(int puntaje, int nivel) {
    if (puntaje > puntajeMaximo) puntajeMaximo = puntaje;
    if (nivel > nivelMaximo) nivelMaximo = nivel;
    partidasJugadas++;
}

void Jugador::mostrar() const {
    std::cout << "ID: " << idJugador << "  Nombre: " << nombre << std::endl;
    std::cout << "Puntaje maximo: " << puntajeMaximo
              << "  Nivel maximo: " << nivelMaximo
              << "  Partidas jugadas: " << partidasJugadas << std::endl;
}

int  Jugador::getIdJugador() const { return idJugador; }
const char* Jugador::getNombre() const { return nombre; }
int  Jugador::getPuntajeMaximo() const { return puntajeMaximo; }
int  Jugador::getNivelMaximo() const { return nivelMaximo; }
int  Jugador::getPartidasJugadas() const { return partidasJugadas; }
bool Jugador::getEliminado() const { return eliminado; }

void Jugador::setNombre(const char* n) {
    strncpy(nombre, n, sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0';
}
void Jugador::setEliminado(bool valor) { eliminado = valor; }
