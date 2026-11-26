#include "GestorArchivos.h"
#include <fstream>

// Implementaciones base. La persistencia binaria de objetos con std::string o
// punteros requiere un formato de serializacion propio; por eso estas funciones
// devuelven false hasta definir ese formato para el proyecto.
bool GestorArchivos::cargarJugadores(std::vector<Jugador>& jugadores,const std::string& archivo) {
    std::ifstream entrada(archivo, std::ios::binary);
    if (!entrada.is_open()){
    return false;
}
    jugadores.clear();
    Jugador jugador;
    while (entrada.read(reinterpret_cast<char*>(&jugador),
    sizeof(Jugador))) {
    jugadores.push_back(jugador);
}
    entrada.close();
    return true;
}
bool GestorArchivos::guardarJugadores(const std::vector<Jugador>& jugadores,const std::string& archivo){
    std::ofstream salida(archivo, std::ios::binary);
    if (!salida.is_open()) {
    return false;
}
    for (int i = 0; i < jugadores.size(); i++) {
    salida.write(reinterpret_cast<const char*>(&jugadores[i]),sizeof(Jugador));
    if (!salida) {
    return false;
    }
}
    salida.close();
    return !salida.fail();
}
bool GestorArchivos::cargarOleadas(std::vector<Oleada>&, const std::string&) { return false; }
bool GestorArchivos::guardarOleadas(const std::vector<Oleada>&, const std::string&) { return false; }
bool GestorArchivos::cargarEnemigos(std::vector<Enemigo*>&, const std::string&) { return false; }
bool GestorArchivos::guardarEnemigos(const std::vector<Enemigo*>&, const std::string&) { return false; }
bool GestorArchivos::cargarDefensas(std::vector<DefensaColocada>&, const std::string&) { return false; }
bool GestorArchivos::guardarDefensas(const std::vector<DefensaColocada>&, const std::string&) { return false; }
bool GestorArchivos::cargarEventos(std::vector<Evento>&, const std::string&) { return false; }
bool GestorArchivos::guardarEventos(const std::vector<Evento>&, const std::string&) { return false; }
