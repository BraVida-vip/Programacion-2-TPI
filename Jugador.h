#ifndef JUGADOR_H
#define JUGADOR_H
#include <cstring>

class Jugador {
private:
    int  idJugador;
    char nombre[30];
    int  puntajeMaximo;
    int  nivelMaximo;
    int  partidasJugadas;
    bool eliminado;
public:
    Jugador();
    Jugador(int id, const char* nombre);

    void actualizarEstadisticas(int puntaje, int nivel);
    void mostrar() const;

    int  getIdJugador() const;
    const char* getNombre() const;
    int  getPuntajeMaximo() const;
    int  getNivelMaximo() const;
    int  getPartidasJugadas() const;
    bool getEliminado() const;

    void setNombre(const char* n);
    void setEliminado(bool valor);
};
#endif

