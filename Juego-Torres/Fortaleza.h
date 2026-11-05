#ifndef FORTALEZA_H
#define FORTALEZA_H
class Fortaleza {
private:
    int resistencia;
    int resistenciaMaxima;
public:
    Fortaleza();
    explicit Fortaleza(int resistenciaMaxima);
    void recibirDano(int cantidad);
    void reparar();
    int getResistencia() const;
    int getResistenciaMaxima() const;
    bool estaDestruida() const;
};
#endif
