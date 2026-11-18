#include "GestorArchivos.h"
#include <fstream>

// Implementaciones base. La persistencia binaria de objetos con std::string o
// punteros requiere un formato de serializacion propio; por eso estas funciones
// devuelven false hasta definir ese formato para el proyecto.
bool GestorArchivos::cargarJugadores(std::vector<Jugador>&, const std::string&) { return false; }
bool GestorArchivos::guardarJugadores(const std::vector<Jugador>&, const std::string&) { return false; }
bool GestorArchivos::cargarOleadas(std::vector<Oleada>&, const std::string&) { return false; }
bool GestorArchivos::guardarOleadas(const std::vector<Oleada>&, const std::string&) { return false; }
bool GestorArchivos::cargarEnemigos(std::vector<Enemigo*>&, const std::string&) { return false; }
bool GestorArchivos::guardarEnemigos(const std::vector<Enemigo*>&, const std::string&) { return false; }
bool GestorArchivos::cargarDefensas(std::vector<DefensaColocada>&, const std::string&) { return false; }
bool GestorArchivos::guardarDefensas(const std::vector<DefensaColocada>&, const std::string&) { return false; }
bool GestorArchivos::cargarEventos(std::vector<Evento>&, const std::string&) { return false; }
bool GestorArchivos::guardarEventos(const std::vector<Evento>&, const std::string&) { return false; }
