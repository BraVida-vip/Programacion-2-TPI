#include "TorreArquera.h"
TorreArquera::TorreArquera() : Defensa(0, "TorreArquera", 0, 10, 2, 1.0f, 50, 1) {}
TorreArquera::TorreArquera(int id) : Defensa(id, "TorreArquera", 0, 10, 2, 1.0f, 50, 1) {}
void TorreArquera::atacar() {}
std::string TorreArquera::getTipo() const { return "TorreArquera"; }
void TorreArquera::dispararRapido() { atacar(); }
