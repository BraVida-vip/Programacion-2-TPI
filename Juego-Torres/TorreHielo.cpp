#include "TorreHielo.h"
TorreHielo::TorreHielo() : Defensa(0, "TorreHielo", 0, 10, 2, 1.0f, 50, 1) {}
TorreHielo::TorreHielo(int id) : Defensa(id, "TorreHielo", 0, 10, 2, 1.0f, 50, 1) {}
void TorreHielo::atacar() {}
std::string TorreHielo::getTipo() const { return "TorreHielo"; }
void TorreHielo::ralentizarEnemigo() { atacar(); }
