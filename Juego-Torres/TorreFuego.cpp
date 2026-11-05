#include "TorreFuego.h"
TorreFuego::TorreFuego() : Defensa(0, "TorreFuego", 0, 10, 2, 1.0f, 50, 1) {}
TorreFuego::TorreFuego(int id) : Defensa(id, "TorreFuego", 0, 10, 2, 1.0f, 50, 1) {}
void TorreFuego::atacar() {}
std::string TorreFuego::getTipo() const { return "TorreFuego"; }
void TorreFuego::lanzarArea() { atacar(); }
