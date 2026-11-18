#ifndef ARCHIVOPARTIDAS_H
#define ARCHIVOPARTIDAS_H

const int MAX_DEFENSAS_GUARDADAS = 100;

struct DefensaGuardada {
    int tipo;
    int id;
    int posicion;
    int nivel;
};

struct DatosPartida {
    int idPartida;
    int idJugador;
    int diaActual;
    int dificultad;

    int dinero;
    int vidas;
    int puntaje;

    int resistencia;
    int resistenciaMaxima;

    int estado;

    int cantidadDefensas;

    DefensaGuardada defensas[MAX_DEFENSAS_GUARDADAS];
};

class ArchivoPartidas {
public:
    bool guardar(const DatosPartida& datos) const;
    bool cargar(int idJugador, DatosPartida& datos) const;
    bool existe(int idJugador) const;
};

#endif
