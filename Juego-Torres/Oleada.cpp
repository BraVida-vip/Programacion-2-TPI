#include "Oleada.h"
#include "Enemigo.h"
Oleada::Oleada() : idOleada(0), dia(0), cantidadEnemigos(0), idEnemigo(0), cantidadActivos(0) {}
Oleada::Oleada(int id, int d, int c, int ie) : idOleada(id), dia(d), cantidadEnemigos(c), idEnemigo(ie), cantidadActivos(0) {}
void Oleada::generarEnemigos() {}
bool Oleada::estaCompleta() const { for (auto e : enemigos) if (e && !e->fueEliminado()) return false; return true; }
void Oleada::agregarEnemigo(Enemigo* e) { if (e) enemigos.push_back(e); }
const std::vector<Enemigo*>& Oleada::getEnemigos() const { return enemigos; }
void Oleada::actualizarApariciones() { if (cantidadActivos < (int)enemigos.size()) cantidadActivos++; }
int Oleada::getCantidadActivos() const { return cantidadActivos; }
