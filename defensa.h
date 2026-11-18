#ifndef DEFENSA_H
#define DEFENSA_H

#include <string>
#include <chrono>

class Defensa {
protected:
    int idTorre;
    std::string nombre;
    int tipo, dano, alcance;
    float velocidadAtaque;
    int costo, nivel;
    bool eliminado;

    std::chrono::steady_clock::time_point ultimoAtaque;

    bool desactivada;

public:
    Defensa();

    Defensa(int id, const std::string& nombre, int tipo, int dano,
            int alcance, float velocidadAtaque, int costo, int nivel = 1);

    virtual ~Defensa() = default;

    virtual void atacar() = 0;
    virtual void mejorar();
    virtual std::string getTipo() const = 0;

    int getIdTorre() const;
    std::string getNombre() const;
    int getDano() const;
    int getAlcance() const;
    int getCosto() const;
    int getNivel() const;
    float getVelocidadAtaque() const;

    bool estaEliminada() const;
    bool estaDesactivada() const;

    void setEliminada(bool valor);
    void setDesactivada(bool valor);

    bool puedeAtacar() const;
    void registrarAtaque();
};

#endif
