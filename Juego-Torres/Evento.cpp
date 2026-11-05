#include "Evento.h"
Evento::Evento() : duracion(0), activo(false) {}
Evento::Evento(const std::string& n, const std::string& d, int du) : nombre(n), descripcion(d), duracion(du), activo(false) {}
void Evento::aplicar() { activo = true; }
void Evento::finalizar() { activo = false; }
bool Evento::estaActivo() const { return activo; }
std::string Evento::getNombre() const { return nombre; }
