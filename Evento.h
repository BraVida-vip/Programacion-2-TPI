#ifndef EVENTO_H
#define EVENTO_H
#include <string>
using namespace std;
class Evento {
private:
    string nombre, descripcion;
    int duracion;
    bool activo;
public:
    Evento();
    Evento(const string& nombre,
           const string& descripcion,
           int duracion);
    void aplicar();
    void finalizar();
    bool estaActivo() const;
    string getNombre() const;
    string getDescripcion() const;
    int getDuracion() const;
};

#endif
