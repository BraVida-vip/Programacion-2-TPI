#include "ArchivoPartidas.h"
#include <fstream>

using namespace std;

const char* NOMBRE_ARCHIVO_PARTIDAS = "Partidas.dat";

// GUARDAR O ACTUALIZAR UNA PARTIDA
bool ArchivoPartidas::guardar(const DatosPartida& datos) const {

    if (datos.cantidadDefensas < 0 ||
        datos.cantidadDefensas > MAX_DEFENSAS_GUARDADAS) {
        return false;
    }

    fstream archivo(NOMBRE_ARCHIVO_PARTIDAS,
                    ios::in | ios::out | ios::binary);

    if (!archivo.is_open()) {
        ofstream nuevo(NOMBRE_ARCHIVO_PARTIDAS, ios::binary);

        if (!nuevo.is_open()) {
            return false;
        }

        nuevo.close();

        archivo.open(NOMBRE_ARCHIVO_PARTIDAS,
                     ios::in | ios::out | ios::binary);
    }

    if (!archivo.is_open()) {
        return false;
    }

    DatosPartida registro;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&registro),
                        sizeof(DatosPartida))) {

        if (registro.idJugador == datos.idJugador) {

            streampos posicion = archivo.tellg();
            posicion -= static_cast<streamoff>(sizeof(DatosPartida));

            archivo.clear();
            archivo.seekp(posicion);

            archivo.write(reinterpret_cast<const char*>(&datos),
                          sizeof(DatosPartida));

            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        archivo.clear();
        archivo.seekp(0, ios::end);

        archivo.write(reinterpret_cast<const char*>(&datos),
                      sizeof(DatosPartida));
    }

    bool correcto = archivo.good();

    archivo.close();

    return correcto;
}

// CARGAR UNA PARTIDA
bool ArchivoPartidas::cargar(int idJugador, DatosPartida& datos) const {

    ifstream archivo(NOMBRE_ARCHIVO_PARTIDAS, ios::binary);

    if (!archivo.is_open()) {
        return false;
    }

    DatosPartida registro;

    while (archivo.read(reinterpret_cast<char*>(&registro),
                        sizeof(DatosPartida))) {

        if (registro.idJugador == idJugador) {

            if (registro.cantidadDefensas < 0 ||
                registro.cantidadDefensas > MAX_DEFENSAS_GUARDADAS) {
                archivo.close();
                return false;
            }

            datos = registro;

            archivo.close();
            return true;
        }
    }

    archivo.close();

    return false;
}

// VERIFICAR SI EXISTE UNA PARTIDA
bool ArchivoPartidas::existe(int idJugador) const {

    DatosPartida datos;

    return cargar(idJugador, datos);
}
