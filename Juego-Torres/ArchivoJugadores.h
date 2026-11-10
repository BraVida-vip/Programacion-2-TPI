#ifndef ARCHIVOJUGADORES_H
#define ARCHIVOJUGADORES_H
#include "Jugador.h"

class ArchivoJugadores {
private:
    char nombreArchivo[30];
public:
    ArchivoJugadores(const char* nombre = "Jugadores.dat");

    bool agregarRegistro(const Jugador& reg);
    bool modificarRegistro(const Jugador& reg, int pos);
    Jugador leerRegistro(int pos);
    int  contarRegistros();
    int  buscarPorNombre(const char* nombre);
    int  generarId();
};
#endif
