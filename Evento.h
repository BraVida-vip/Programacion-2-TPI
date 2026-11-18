#ifndef EVENTO_H
#define EVENTO_H
#include <string>
class Evento {
private:
    std::string nombre, descripcion;
    int duracion;
    bool activo;
public:
    Evento();
    Evento(const std::string& nombre, const std::string& descripcion, int duracion);
    void aplicar();
    void finalizar();
    bool estaActivo() const;
    std::string getNombre() const;
};
#endif
