#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <string>
#include <chrono>

class Enemigo {
protected:
    int idEnemigo;
    std::string nombre;
    int tipo, vida, dano, alcance;

    float velocidad;

    int recompensa, duracion;

    bool eliminado;

    float posicion;

    // Control de ralentización
    float factorRalentizacion;
    std::chrono::steady_clock::time_point finRalentizacion;

public:
    Enemigo();

    Enemigo(int id, const std::string& nombre, int tipo, int vida,
            int dano, int alcance, float velocidad,
            int recompensa, int duracion);

    virtual ~Enemigo() = default;

    virtual void atacar() = 0;

    virtual void recibirDano(int cantidad);

    virtual std::string estaVivo() const;

    int getIdEnemigo() const;
    int getVida() const;
    int getDano() const;
    int getRecompensa() const;

    float getPosicion() const;
    float getVelocidad() const;

    bool fueEliminado() const;

    void avanzar(float tiempoTranscurrido);

    // Aplicar ralentización
    void ralentizar(float factor, float segundos);

};

#endif
