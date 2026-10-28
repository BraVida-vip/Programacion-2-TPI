#ifndef PARTIDA_H
#define PARTIDA_H

class Partida {
private:
    int diaActual;
    int oro;
    int resistenciaCastillo;

public:
    Partida();

    void avanzarDia();
    void sumarOro(int cantidad);
    bool gastarOro(int cantidad);
    void recibirDanio(int cantidad);

    bool juegoTerminado();
    bool victoria();

    int getDia();
    int getOro();
    int getResistencia();
};

#endif
