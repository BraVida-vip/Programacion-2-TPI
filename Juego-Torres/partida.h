#ifndef PARTIDA_H
#define PARTIDA_H
#include <string>
#include <vector>
#include "Fortaleza.h"
#include "DefensaColocada.h"
#include "Oleada.h"
class Partida {
private:
    int idPartida, idJugador, diaActual, dificultad, dinero, vidas, puntaje;
    std::string estado;
    Fortaleza fortaleza;
    std::vector<DefensaColocada> defensas;
    std::vector<Oleada> oleadas;
    int indiceOleada;
public:
    Partida();
    Partida(int idPartida, int idJugador, int dificultad);
    void iniciarOleada();
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
    std::string getEstado() const;
    void setEstado(const std::string& estado);
};
#endif
