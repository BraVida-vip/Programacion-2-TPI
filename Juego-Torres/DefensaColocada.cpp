#include "DefensaColocada.h"
DefensaColocada::DefensaColocada() : idColocacion(0), idPartida(0), idTorre(0), posicion(0), nivelActual(1), mejorada(false), defensa(nullptr) {}
DefensaColocada::DefensaColocada(int ic, int ip, int it, int p, Defensa* d)
    : idColocacion(ic), idPartida(ip), idTorre(it), posicion(p), nivelActual(1), mejorada(false), defensa(d) {}
void DefensaColocada::mejorarNivel() { ++nivelActual; mejorada = true; if (defensa) defensa->mejorar(); }
void DefensaColocada::eliminar() { if (defensa) defensa->setEliminada(true); }
Defensa* DefensaColocada::getDefensa() const { return defensa; }
int DefensaColocada::getPosicion() const { return posicion; }
bool DefensaColocada::estaMejorada() const { return mejorada; }
