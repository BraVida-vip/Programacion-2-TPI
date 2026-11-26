#ifndef OLEADA_H
#define OLEADA_H
#include <vector>
using namespace std;
class Enemigo;
class Oleada {
private:
    int idOleada, dia, cantidadEnemigos, idEnemigo;
    int cantidadActivos;
    float tiempoAcumulado;
    vector<Enemigo*> enemigos;

public:
    Oleada();
    Oleada(int id, int dia, int cantidad, int idEnemigo = 0);
    void generarEnemigos();
    void actualizarApariciones(float tiempo);
    int getCantidadActivos() const;
    bool estaCompleta() const;
    void agregarEnemigo(Enemigo* enemigo);
    const vector<Enemigo*>& getEnemigos() const;
      void liberarEnemigos();
};
#endif
