#include "Partida.h"
Partida::Partida() : idPartida(0), idJugador(0), diaActual(1), dificultad(1), dinero(100), vidas(3), puntaje(0), estado("En curso"), indiceOleada(0) {}
Partida::Partida(int id, int jugador, int dif) : idPartida(id), idJugador(jugador), diaActual(1), dificultad(dif), dinero(100), vidas(3), puntaje(0), estado("En curso"), indiceOleada(0) {}
void Partida::iniciarOleada() { if (indiceOleada < (int)oleadas.size()) oleadas[indiceOleada].generarEnemigos(); }
void Partida::construirDefensa(Defensa* d, int p) { if (d && dinero >= d->getCosto()) { dinero -= d->getCosto(); defensas.emplace_back((int)defensas.size()+1, idPartida, d->getIdTorre(), p, d); } }
void Partida::mejorarDefensa(int i) { if (i >= 0 && i < (int)defensas.size()) defensas[i].mejorarNivel(); }
void Partida::verRecursos() const {}
void Partida::repararFortaleza() { if (dinero >= 25) { dinero -= 25; fortaleza.reparar(); } }
void Partida::guardarPartida() const {}
void Partida::agregarOleada(const Oleada& o) { oleadas.push_back(o); }
void Partida::agregarDinero(int c) { dinero += c; }
int Partida::getPuntaje() const { return puntaje; }
int Partida::getDinero() const { return dinero; }
int Partida::getVidas() const { return vidas; }
std::string Partida::getEstado() const { return estado; }
void Partida::setEstado(const std::string& e) { estado = e; }
