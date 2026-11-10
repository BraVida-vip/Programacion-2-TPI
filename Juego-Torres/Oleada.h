#ifndef OLEADA_H
#define OLEADA_H
#include <vector>
class Enemigo;
class Oleada {
private:
    int idOleada, dia, cantidadEnemigos, idEnemigo;
    int cantidadActivos;
    std::vector<Enemigo*> enemigos;
public:
    Oleada();
    Oleada(int id, int dia, int cantidad, int idEnemigo = 0);
    void generarEnemigos();
    void actualizarApariciones();
    int getCantidadActivos() const;
    bool estaCompleta() const;
    void agregarEnemigo(Enemigo* enemigo);
    const std::vector<Enemigo*>& getEnemigos() const;
};
#endif
