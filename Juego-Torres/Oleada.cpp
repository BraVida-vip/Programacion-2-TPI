#include "Oleada.h"
#include "Enemigo.h"
#include "ENEMIGOS.h"

Oleada::Oleada() : idOleada(0), dia(0), cantidadEnemigos(0), idEnemigo(0), cantidadActivos(0) {}
Oleada::Oleada(int id, int d, int c, int ie) : idOleada(id), dia(d), cantidadEnemigos(c), idEnemigo(ie), cantidadActivos(0) {}

// Crea los enemigos de la oleada segun el dia (tabla del informe)
void Oleada::generarEnemigos() {
    if (!enemigos.empty()) return;   // ya fue generada

    for (int i = 0; i < cantidadEnemigos; i++) {
        int id = i + 1;
        Enemigo* e = nullptr;

        switch (dia) {
            case 1:  // Goblins
                e = new Goblin(id);
                break;
            case 2:  // Goblins y Esqueletos
                if (i % 2 == 0) e = new Goblin(id);
                else            e = new Esqueleto(id);
                break;
            case 3:  // Orcos
                e = new Orco(id);
                break;
            case 4:  // Orcos y Nigromantes
                if (i % 4 == 3) e = new Nigromante(id);
                else            e = new Orco(id);
                break;
            case 5:  // Horda mixta
                switch (i % 4) {
                    case 0:  e = new Goblin(id);     break;
                    case 1:  e = new Esqueleto(id);  break;
                    case 2:  e = new Orco(id);       break;
                    default: e = new Nigromante(id); break;
                }
                break;
            case 6:  // Bestias Oscuras
                e = new BestiaOscura(id);
                break;
            default: // Dia 7: Mordak
                e = new Mordak(id);
                break;
        }
        enemigos.push_back(e);
    }
}

bool Oleada::estaCompleta() const { for (auto e : enemigos) if (e && !e->fueEliminado()) return false; return true; }
void Oleada::agregarEnemigo(Enemigo* e) { if (e) enemigos.push_back(e); }
const std::vector<Enemigo*>& Oleada::getEnemigos() const { return enemigos; }
void Oleada::actualizarApariciones() { if (cantidadActivos < (int)enemigos.size()) cantidadActivos++; }
int Oleada::getCantidadActivos() const { return cantidadActivos; }
