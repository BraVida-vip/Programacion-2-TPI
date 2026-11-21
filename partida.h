#ifndef PARTIDA_H
#define PARTIDA_H
#include <string>
#include <vector>
#include <chrono>
#include "Fortaleza.h"
#include "DefensaColocada.h"
#include "Oleada.h"
#include "Evento.h"
using namespace std;
class Defensa;

class Partida {
private:
    int idPartida, idJugador, diaActual, dificultad;
    int dinero, vidas, puntaje;

    string estado;
    Evento eventoActual;
    Defensa* defensaSaboteada = nullptr;
float tiempoEvento = 0.0f;
    Fortaleza fortaleza;
    vector<DefensaColocada> defensas;
    vector<Oleada> oleadas;
    int indiceOleada;
    bool oleadaIniciada;
    chrono::steady_clock::time_point ultimaActualizacion;
public:
    Partida();
    Partida(int idPartida, int idJugador, int dificultad);
    void iniciarOleada();
    void actualizarPartida();
    void avanzarDia();
    void mostrarCombate() const;
    void liberarMemoria();
    void construirDefensa(Defensa* defensa, int posicion);
    bool mejorarDefensa(int indice);
    void verRecursos() const;
    bool repararFortaleza();
    bool guardarPartida() const;
    bool cargarPartida(int idJugadorBuscado);
    void agregarOleada(const Oleada& oleada);
    void agregarDinero(int cantidad);
    int getPuntaje() const;
    int getDinero() const;
    int getVidas() const;
    int getDia() const;
    int getResistencia() const;
    bool partidaTerminada() const;
    string getEstado() const;
    void setEstado(const string& estado);
    void mostrarDefensas() const;
    int getCantidadDefensas() const;
    void generarEvento();
    void aplicarEvento();
    void finalizarEvento();
    void mostrarEvento() const;
};

#endif
