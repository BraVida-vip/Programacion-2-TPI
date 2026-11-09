#include "Defensa.h"

Defensa::Defensa()
    : idTorre(0),
      tipo(0),
      dano(0),
      alcance(0),
      velocidadAtaque(0),
      costo(0),
      nivel(1),
      eliminado(false),
      ultimoAtaque(std::chrono::steady_clock::now()),
      desactivada(false) {
}

Defensa::Defensa(int id, const std::string& n, int t, int d,
                 int a, float v, int c, int ni)
    : idTorre(id),
      nombre(n),
      tipo(t),
      dano(d),
      alcance(a),
      velocidadAtaque(v),
      costo(c),
      nivel(ni),
      eliminado(false),
      ultimoAtaque(std::chrono::steady_clock::now()),
      desactivada(false) {
}

void Defensa::mejorar() {
    ++nivel;
    dano += 5;
}

int Defensa::getIdTorre() const {
    return idTorre;
}

std::string Defensa::getNombre() const {
    return nombre;
}

int Defensa::getDano() const {
    return dano;
}

int Defensa::getAlcance() const {
    return alcance;
}

int Defensa::getCosto() const {
    return costo;
}

int Defensa::getNivel() const {
    return nivel;
}

float Defensa::getVelocidadAtaque() const {
    return velocidadAtaque;
}

bool Defensa::estaEliminada() const {
    return eliminado;
}

bool Defensa::estaDesactivada() const {
    return desactivada;
}

void Defensa::setEliminada(bool v) {
    eliminado = v;
}

void Defensa::setDesactivada(bool v) {
    desactivada = v;
}

bool Defensa::puedeAtacar() const {

    if (eliminado || desactivada || velocidadAtaque <= 0) {
        return false;
    }

    auto ahora = std::chrono::steady_clock::now();

    float tiempoTranscurrido =
        std::chrono::duration<float>(ahora - ultimoAtaque).count();

    float intervalo = 1.0f / velocidadAtaque;

    return tiempoTranscurrido >= intervalo;
}

void Defensa::registrarAtaque() {
    ultimoAtaque = std::chrono::steady_clock::now();
}
