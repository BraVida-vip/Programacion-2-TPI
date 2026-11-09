#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include <vector>
#include <chrono>

#include "Fortaleza.h"
#include "DefensaColocada.h"
#include "Oleada.h"

class Defensa;

class Partida {
private:
    int idPartida, idJugador, diaActual, dificultad;
    int dinero, vidas, puntaje;

    std::string estado;

    Fortaleza fortaleza;

    std::vector<DefensaColocada> defensas;
    std::vector<Oleada> oleadas;

    int indiceOleada;
    bool oleadaIniciada;

    std::chrono::steady_clock::time_point ultimaActualizacion;

public:
    Partida();
    Partida(int idPartida, int idJugador, int dificultad);

    void iniciarOleada();
    void actualizarPartida();
    void avanzarDia();

    void construirDefensa(Defensa* defensa, int posicion);
    void mejorarDefensa(int indice);

    void verRecursos() const;
    void repararFortaleza();
    void guardarPartida() const;

    void agregarOleada(const Oleada& oleada);
    void agregarDinero(int cantidad);

    int getPuntaje() const;
    int getDinero() const;
    int getVidas() const;
    int getDia() const;
    int getResistencia() const;

    bool partidaTerminada() const;

    std::string getEstado() const;
    void setEstado(const std::string& estado);
};

#endif
