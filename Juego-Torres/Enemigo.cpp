#include "Enemigo.h"

Enemigo::Enemigo()
    : idEnemigo(0),
      tipo(0),
      vida(0),
      dano(0),
      alcance(0),
      velocidad(0),
      recompensa(0),
      duracion(0),
      eliminado(false),
      posicion(0),
      factorRalentizacion(1.0f),
      finRalentizacion(std::chrono::steady_clock::now()) {
}

Enemigo::Enemigo(int id, const std::string& n, int t, int v, int d,
                 int a, float vel, int r, int du)
    : idEnemigo(id),
      nombre(n),
      tipo(t),
      vida(v),
      dano(d),
      alcance(a),
      velocidad(vel),
      recompensa(r),
      duracion(du),
      eliminado(false),
      posicion(0),
      factorRalentizacion(1.0f),
      finRalentizacion(std::chrono::steady_clock::now()) {
}

void Enemigo::recibirDano(int c) {

    if (c > 0 && !eliminado) {
        vida -= c;
    }

    if (vida <= 0) {
        vida = 0;
        eliminado = true;
    }
}

std::string Enemigo::estaVivo() const {
    return vida > 0 ? "Si" : "No";
}

int Enemigo::getIdEnemigo() const {
    return idEnemigo;
}

int Enemigo::getVida() const {
    return vida;
}

int Enemigo::getDano() const {
    return dano;
}

int Enemigo::getRecompensa() const {
    return recompensa;
}

float Enemigo::getPosicion() const {
    return posicion;
}

float Enemigo::getVelocidad() const {
    return velocidad * factorRalentizacion;
}

bool Enemigo::fueEliminado() const {
    return eliminado;
}

// MOVIMIENTO

void Enemigo::avanzar(float tiempoTranscurrido) {

    if (eliminado || tiempoTranscurrido <= 0) {
        return;
    }

    // Comprobar si terminó la ralentización
    if (std::chrono::steady_clock::now() >= finRalentizacion) {
        factorRalentizacion = 1.0f;
    }

    posicion += getVelocidad() * tiempoTranscurrido;
}

// RALENTIZACION

void Enemigo::ralentizar(float factor, float segundos) {

    if (eliminado || factor <= 0 || factor >= 1 || segundos <= 0) {
        return;
    }

    factorRalentizacion = factor;

    finRalentizacion =
        std::chrono::steady_clock::now() +
        std::chrono::milliseconds(
            static_cast<int>(segundos * 1000)
        );
}
