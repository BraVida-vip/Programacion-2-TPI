#include "Fortaleza.h"
Fortaleza::Fortaleza() : resistencia(1000), resistenciaMaxima(1000) {}
Fortaleza::Fortaleza(int max) : resistencia(max), resistenciaMaxima(max) {}
void Fortaleza::recibirDano(int c) { if (c > 0) { resistencia -= c; if (resistencia < 0) resistencia = 0; } }
void Fortaleza::reparar() { resistencia = resistenciaMaxima; }
int Fortaleza::getResistencia() const { return resistencia; }
int Fortaleza::getResistenciaMaxima() const { return resistenciaMaxima; }
bool Fortaleza::estaDestruida() const { return resistencia <= 0; }
void Fortaleza::aumentarResistencia(int cantidad) {

    if (cantidad > 0) {
        resistenciaMaxima += cantidad;
        resistencia += cantidad;
    }
}
///Este método nos permite recuperar la resistencia exacta que tenía la fortaleza cuando guardamos la partida.
void Fortaleza::restaurar(int actual, int maximo) {
    resistenciaMaxima = maximo;

    if (resistenciaMaxima < 0) {
        resistenciaMaxima = 0;
    }

    resistencia = actual;

    if (resistencia < 0) {
        resistencia = 0;
    }

    if (resistencia > resistenciaMaxima) {
        resistencia = resistenciaMaxima;
    }
}
