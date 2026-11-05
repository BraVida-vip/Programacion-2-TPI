#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
class Jugador {
private:
    int idJugador, puntajeMaximo, nivelMaximo, partidasJugadas;
    std::string nombre;
    bool habilitado;
public:
    Jugador();
    Jugador(int id, const std::string& nombre);
    void actualizarEstadisticas(int puntaje);
    int getIdJugador() const;
    std::string getNombre() const;
    int getPuntajeMaximo() const;
    int getPartidasJugadas() const;
    bool estaHabilitado() const;
    void setHabilitado(bool valor);
};
#endif
