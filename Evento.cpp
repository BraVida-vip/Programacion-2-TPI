
#include "Evento.h"
using namespace std;
Evento::Evento() : duracion(0), activo(false) {}
Evento::Evento(const string& n, const string& d, int du) : nombre(n), descripcion(d), duracion(du), activo(false) {}
void Evento::aplicar() { activo = true; }
void Evento::finalizar() { activo = false; }
bool Evento::estaActivo() const { return activo; }
string Evento::getNombre() const { return nombre; }
string Evento::getDescripcion() const {
    return descripcion;
}

int Evento::getDuracion() const {
    return duracion;
}
