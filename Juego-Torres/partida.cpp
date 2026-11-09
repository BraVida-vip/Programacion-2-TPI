#include "Partida.h"
#include "Defensa.h"
#include "Enemigo.h"
#include "Muralla.h"

#include "TorreArquera.h"
#include "TorreFuego.h"
#include "TorreHielo.h"

#include <iostream>
#include <cmath>

// CONSTRUCTORES

Partida::Partida()
    : idPartida(0),
      idJugador(0),
      diaActual(1),
      dificultad(1),
      dinero(100),
      vidas(3),
      puntaje(0),
      estado("En curso"),
      indiceOleada(0),
      oleadaIniciada(false),
      ultimaActualizacion(std::chrono::steady_clock::now()) {

    int cantidades[7] = {5, 8, 12, 16, 20, 25, 8};

    for (int i = 0; i < 7; i++) {
        oleadas.emplace_back(i + 1, i + 1, cantidades[i]);
    }
}

Partida::Partida(int id, int jugador, int dif)
    : idPartida(id),
      idJugador(jugador),
      diaActual(1),
      dificultad(dif),
      dinero(100),
      vidas(3),
      puntaje(0),
      estado("En curso"),
      indiceOleada(0),
      oleadaIniciada(false),
      ultimaActualizacion(std::chrono::steady_clock::now()) {

    int cantidades[7] = {5, 8, 12, 16, 20, 25, 8};

    for (int i = 0; i < 7; i++) {
        oleadas.emplace_back(i + 1, i + 1, cantidades[i]);
    }
}

// INICIAR OLEADA

void Partida::iniciarOleada() {

    if (indiceOleada < (int)oleadas.size() && !oleadaIniciada) {

        oleadas[indiceOleada].generarEnemigos();

        oleadaIniciada = true;
        ultimaActualizacion = std::chrono::steady_clock::now();
    }
}

// ACTUALIZAR PARTIDA

void Partida::actualizarPartida() {

    if (partidaTerminada()) {
        return;
    }

    if (indiceOleada >= (int)oleadas.size()) {
        estado = "Victoria";
        return;
    }

    if (!oleadaIniciada) {
        iniciarOleada();
    }

    auto ahora = std::chrono::steady_clock::now();

    float tiempoTranscurrido =
        std::chrono::duration<float>(
            ahora - ultimaActualizacion
        ).count();

    ultimaActualizacion = ahora;

    Oleada& oleada = oleadas[indiceOleada];

    // Generar enemigos progresivamente
    oleada.actualizarApariciones();

    const std::vector<Enemigo*>& enemigos = oleada.getEnemigos();

    int cantidadActivos = oleada.getCantidadActivos();

    // =====================================
    // ATAQUES DE LAS TORRES
    // =====================================

    for (auto& colocacion : defensas) {

        Defensa* torre = colocacion.getDefensa();

        if (torre == nullptr || !torre->puedeAtacar()) {
            continue;
        }

        if (torre->estaEliminada()) {
            continue;
        }

        float posicionTorre = colocacion.getPosicion();

        // TORRE ARQUERA
        if (dynamic_cast<TorreArquera*>(torre) != nullptr) {

            Enemigo* objetivo = nullptr;

            for (int i = 0; i < cantidadActivos; i++) {

                Enemigo* enemigo = enemigos[i];

                if (enemigo == nullptr || enemigo->fueEliminado()) {
                    continue;
                }

                float distancia =
                    std::fabs(enemigo->getPosicion() - posicionTorre);

                if (distancia <= torre->getAlcance()) {

                    if (objetivo == nullptr ||
                        enemigo->getPosicion() > objetivo->getPosicion()) {

                        objetivo = enemigo;
                    }
                }
            }

            if (objetivo != nullptr) {

                objetivo->recibirDano(torre->getDano());

                torre->registrarAtaque();

                if (objetivo->fueEliminado()) {
                    agregarDinero(objetivo->getRecompensa());
                    puntaje += 10;
                }
            }
        }

        // TORRE DE FUEGO
        else if (dynamic_cast<TorreFuego*>(torre) != nullptr) {

            bool ataco = false;

            for (int i = 0; i < cantidadActivos; i++) {

                Enemigo* enemigo = enemigos[i];

                if (enemigo == nullptr || enemigo->fueEliminado()) {
                    continue;
                }

                float distancia =
                    std::fabs(enemigo->getPosicion() - posicionTorre);

                if (distancia <= torre->getAlcance()) {

                    enemigo->recibirDano(torre->getDano());

                    ataco = true;

                    if (enemigo->fueEliminado()) {
                        agregarDinero(enemigo->getRecompensa());
                        puntaje += 10;
                    }
                }
            }

            if (ataco) {
                torre->registrarAtaque();
            }
        }

        // TORRE DE HIELO
        else if (dynamic_cast<TorreHielo*>(torre) != nullptr) {

            Enemigo* objetivo = nullptr;

            for (int i = 0; i < cantidadActivos; i++) {

                Enemigo* enemigo = enemigos[i];

                if (enemigo == nullptr || enemigo->fueEliminado()) {
                    continue;
                }

                float distancia =
                    std::fabs(enemigo->getPosicion() - posicionTorre);

                if (distancia <= torre->getAlcance()) {

                    if (objetivo == nullptr ||
                        enemigo->getPosicion() > objetivo->getPosicion()) {

                        objetivo = enemigo;
                    }
                }
            }

            if (objetivo != nullptr) {

                objetivo->recibirDano(torre->getDano());

                objetivo->ralentizar(0.5f, 3.0f);

                torre->registrarAtaque();

                if (objetivo->fueEliminado()) {
                    agregarDinero(objetivo->getRecompensa());
                    puntaje += 10;
                }
            }
        }
    }

    // =====================================
    // MOVIMIENTO DE LOS ENEMIGOS
    // =====================================

    for (int i = 0; i < cantidadActivos; i++) {

        Enemigo* enemigo = enemigos[i];

        if (enemigo == nullptr || enemigo->fueEliminado()) {
            continue;
        }

        enemigo->avanzar(tiempoTranscurrido);

        // FINAL DEL CAMINO
        if (enemigo->getPosicion() >= 10.0f) {

            fortaleza.recibirDano(enemigo->getDano());

            enemigo->recibirDano(enemigo->getVida());

            if (fortaleza.estaDestruida()) {
                estado = "Derrota";
                return;
            }
        }
    }

    // =====================================
    // FINALIZACION DE OLEADA
    // =====================================

    if (oleada.estaCompleta()) {
        avanzarDia();
    }
}

// AVANZAR DIA

void Partida::avanzarDia() {

    if (indiceOleada >= (int)oleadas.size()) {
        return;
    }

    if (!oleadas[indiceOleada].estaCompleta()) {
        return;
    }

    if (diaActual >= 7) {
        estado = "Victoria";
        return;
    }

    diaActual++;
    indiceOleada++;
    oleadaIniciada = false;

    iniciarOleada();
}

// CONSTRUIR DEFENSA

void Partida::construirDefensa(Defensa* d, int p) {

    if (d != nullptr && dinero >= d->getCosto()) {

        dinero -= d->getCosto();

        defensas.emplace_back(
            (int)defensas.size() + 1,
            idPartida,
            d->getIdTorre(),
            p,
            d
        );

        // VERIFICAR SI ES UNA MURALLA
        Muralla* muralla = dynamic_cast<Muralla*>(d);

        if (muralla != nullptr) {
            muralla->aumentarResistencia(fortaleza);
        }
    }
}

// MEJORAR DEFENSA

void Partida::mejorarDefensa(int i) {

    if (i >= 0 && i < (int)defensas.size()) {
        defensas[i].mejorarNivel();
    }
}

// MOSTRAR RECURSOS

void Partida::verRecursos() const {

    std::cout << "\n========== RECURSOS ==========" << std::endl;
    std::cout << "Dia: " << diaActual << std::endl;
    std::cout << "Oro: " << dinero << std::endl;
    std::cout << "Vidas: " << vidas << std::endl;
    std::cout << "Resistencia: " << fortaleza.getResistencia() << std::endl;
    std::cout << "Puntaje: " << puntaje << std::endl;
    std::cout << "==============================" << std::endl;
}

// REPARAR FORTALEZA

void Partida::repararFortaleza() {

    if (dinero >= 25) {
        dinero -= 25;
        fortaleza.reparar();
    }
}

// GUARDAR PARTIDA

void Partida::guardarPartida() const {
    // Pendiente implementar guardado.
}

// AGREGAR OLEADA

void Partida::agregarOleada(const Oleada& o) {
    oleadas.push_back(o);
}

// AGREGAR DINERO

void Partida::agregarDinero(int c) {

    if (c > 0) {
        dinero += c;
    }
}

// GETTERS

int Partida::getPuntaje() const {
    return puntaje;
}

int Partida::getDinero() const {
    return dinero;
}

int Partida::getVidas() const {
    return vidas;
}

int Partida::getDia() const {
    return diaActual;
}

int Partida::getResistencia() const {
    return fortaleza.getResistencia();
}

std::string Partida::getEstado() const {
    return estado;
}

// VERIFICAR FIN DE PARTIDA

bool Partida::partidaTerminada() const {
    return estado != "En curso" || fortaleza.estaDestruida();
}

// CAMBIAR ESTADO

void Partida::setEstado(const std::string& e) {
    estado = e;
}
