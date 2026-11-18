#include "IngresoJugador.h"
#include "ArchivoJugadores.h"
#include <iostream>
#include <string>

using namespace std;

Jugador ingresarJugador() {
    ArchivoJugadores archivo;
    string nombre;

    do {
        cout << "Ingrese su nombre de jugador: ";
        getline(cin, nombre);
        if (nombre.empty()) cout << "El nombre no puede estar vacio." << endl;
    } while (nombre.empty());

    int pos = archivo.buscarPorNombre(nombre.c_str());

    if (pos >= 0) {
        Jugador jugador = archivo.leerRegistro(pos);
        cout << "\nBienvenido de nuevo, " << jugador.getNombre() << "!" << endl;
        jugador.mostrar();
        return jugador;
    }

    Jugador nuevo(archivo.generarId(), nombre.c_str());
    if (archivo.agregarRegistro(nuevo)) {
        cout << "\nJugador nuevo registrado. Bienvenido, " << nuevo.getNombre() << "!" << endl;
    } else {
        cout << "\nNo se pudo guardar el jugador en Jugadores.dat" << endl;
    }
    return nuevo;
}
