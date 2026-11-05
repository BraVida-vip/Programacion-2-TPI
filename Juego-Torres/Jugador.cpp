#include "Jugador.h"
Jugador::Jugador() : idJugador(0), puntajeMaximo(0), nivelMaximo(1), partidasJugadas(0), habilitado(true) {}
Jugador::Jugador(int id, const std::string& n) : idJugador(id), puntajeMaximo(0), nivelMaximo(1), partidasJugadas(0), nombre(n), habilitado(true) {}
void Jugador::actualizarEstadisticas(int p) { if (p > puntajeMaximo) puntajeMaximo = p; ++partidasJugadas; }
int Jugador::getIdJugador() const { return idJugador; }
std::string Jugador::getNombre() const { return nombre; }
int Jugador::getPuntajeMaximo() const { return puntajeMaximo; }
int Jugador::getPartidasJugadas() const { return partidasJugadas; }
bool Jugador::estaHabilitado() const { return habilitado; }
void Jugador::setHabilitado(bool v) { habilitado = v; }
