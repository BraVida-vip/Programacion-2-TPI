#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
#include <string>
#include <vector>
#include "Jugador.h"
#include "Partida.h"
#include "Oleada.h"
#include "DefensaColocada.h"
#include "Enemigo.h"
#include "Evento.h"

class GestorArchivos {
public:
    GestorArchivos() = default;
    bool cargarJugadores(std::vector<Jugador>& jugadores, const std::string& archivo = "jugadores.dat");
    bool guardarJugadores(const std::vector<Jugador>& jugadores, const std::string& archivo = "jugadores.dat");
    bool cargarOleadas(std::vector<Oleada>& oleadas, const std::string& archivo = "oleadas.dat");
    bool guardarOleadas(const std::vector<Oleada>& oleadas, const std::string& archivo = "oleadas.dat");
    bool cargarEnemigos(std::vector<Enemigo*>& enemigos, const std::string& archivo = "enemigos.dat");
    bool guardarEnemigos(const std::vector<Enemigo*>& enemigos, const std::string& archivo = "enemigos.dat");
    bool cargarDefensas(std::vector<DefensaColocada>& defensas, const std::string& archivo = "defensas.dat");
    bool guardarDefensas(const std::vector<DefensaColocada>& defensas, const std::string& archivo = "defensas.dat");
    bool cargarEventos(std::vector<Evento>& eventos, const std::string& archivo = "eventos.dat");
    bool guardarEventos(const std::vector<Evento>& eventos, const std::string& archivo = "eventos.dat");
};
#endif
