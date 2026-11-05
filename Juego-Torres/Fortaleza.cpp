#include "Fortaleza.h"
Fortaleza::Fortaleza() : resistencia(100), resistenciaMaxima(100) {}
Fortaleza::Fortaleza(int max) : resistencia(max), resistenciaMaxima(max) {}
void Fortaleza::recibirDano(int c) { if (c > 0) { resistencia -= c; if (resistencia < 0) resistencia = 0; } }
void Fortaleza::reparar() { resistencia = resistenciaMaxima; }
int Fortaleza::getResistencia() const { return resistencia; }
int Fortaleza::getResistenciaMaxima() const { return resistenciaMaxima; }
bool Fortaleza::estaDestruida() const { return resistencia <= 0; }
