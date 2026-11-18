#include <iostream>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "Partida.h"
#include "IngresoJugador.h"
#include "ArchivoJugadores.h"
#include "TORRES.h"
#include "Muralla.h"

using namespace std;

// Pausa portable (no depende de <thread>)
void pausa(int milisegundos) {
#ifdef _WIN32
    Sleep(milisegundos);
#else
    usleep(milisegundos * 1000);
#endif
}

void mostrarMenu(const Partida& partida) {
    cout << "\n========================================" << endl;
    cout << "   DEFENSA DE ELDORIA - DIA " << partida.getDia() << " de 7" << endl;
    cout << "========================================" << endl;
    cout << "  1. Construir defensa" << endl;
    cout << "  2. Mejorar defensa" << endl;
    cout << "  3. Ver recursos" << endl;
    cout << "  4. Reparar fortaleza" << endl;
    cout << "  5. Iniciar oleada" << endl;
    cout << "  6. Guardar partida" << endl;
    cout << "  7. Salir" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Seleccione una opcion: ";
}

// 1. CONSTRUIR DEFENSA
void construirDefensa(Partida& partida) {
    cout << "\n1. Torre Arquera (50 oro)" << endl;
    cout << "2. Torre de Fuego (80 oro)" << endl;
    cout << "3. Torre de Hielo (70 oro)" << endl;
    cout << "4. Muralla (75 oro)" << endl;
    cout << "0. Cancelar" << endl;
    cout << "Tipo de defensa: ";

    int tipo;
    cin >> tipo;
    if (tipo < 1 || tipo > 4) return;

    int posicion = 0;
    if (tipo != 4) {
        do {
            cout << "Posicion en el camino (1 a 9): ";
            cin >> posicion;
        } while (posicion < 1 || posicion > 9);
    }

    Defensa* d = nullptr;
    int id = partida.getCantidadDefensas() + 1;

    if (tipo == 1)      d = new TorreArquera(id);
    else if (tipo == 2) d = new TorreFuego(id);
    else if (tipo == 3) d = new TorreHielo(id);
    else                d = new Muralla(id);

    if (partida.getDinero() < d->getCosto()) {
        cout << "No alcanza el oro (necesitas " << d->getCosto() << ")." << endl;
        delete d;
        return;
    }

    partida.construirDefensa(d, posicion);
    cout << d->getNombre() << " construida." << endl;
}

// 2. MEJORAR DEFENSA
void mejorarDefensa(Partida& partida) {
    if (partida.getCantidadDefensas() == 0) {
        cout << "Todavia no construiste defensas." << endl;
        return;
    }
    cout << endl;
    partida.mostrarDefensas();
    cout << "Numero de defensa a mejorar (0 para cancelar): ";
    int n;
    cin >> n;
    if (n >= 1 && n <= partida.getCantidadDefensas()) {
        if (partida.mejorarDefensa(n - 1)) {
            cout << "Defensa mejorada." << endl;
        } else {
            cout << "No se pudo mejorar (oro insuficiente o nivel maximo)." << endl;
        }
    }
}

// 5. INICIAR OLEADA (corre hasta que termina el dia o la partida)
void correrOleada(Partida& partida) {
    int diaInicial = partida.getDia();

    cout << "\n>>> Comienza la oleada del dia " << diaInicial << "!" << endl;
    partida.iniciarOleada();

    int tick = 0;
    while (partida.getDia() == diaInicial && !partida.partidaTerminada()) {
        partida.actualizarPartida();
        pausa(100);

        tick++;
        if (tick % 10 == 0) {
            cout << "  ... Castillo: " << partida.getResistencia()
                 << " | Oro: " << partida.getDinero() << endl;
        }
    }

    if (!partida.partidaTerminada()) {
        cout << "\nOleada superada! Preparate para el dia " << partida.getDia() << "." << endl;
    }
}

int main()
{
    Jugador jugador = ingresarJugador();

    // La partida queda asociada al jugador que ingreso (dificultad Normal por ahora)
    Partida partida(1, jugador.getIdJugador(), 2);

    int opcion;
    do {
        mostrarMenu(partida);
        cin >> opcion;

        switch (opcion) {
            case 1: construirDefensa(partida); break;
            case 2: mejorarDefensa(partida);   break;
            case 3: partida.verRecursos();     break;
            case 4:
                if (partida.repararFortaleza()) {
                    cout << "Fortaleza reparada (-30 oro)." << endl;
                } else {
                    cout << "No se puede reparar (necesitas 30 oro y la fortaleza danada)." << endl;
                }
                break;
            case 5: correrOleada(partida);     break;
            case 6:
                partida.guardarPartida();
                cout << "Guardado de partida: pendiente de implementar." << endl;
                break;
            case 7: cout << "Saliendo de Eldoria..." << endl; break;
            default: cout << "Opcion incorrecta." << endl; break;
        }
    } while (opcion != 7 && !partida.partidaTerminada());

    // FIN DE PARTIDA
    if (partida.getEstado() == "Victoria") {
        cout << "\n==========================" << endl;
        cout << "       VICTORIA!" << endl;
        cout << "==========================" << endl;
        cout << "Eldoria sobrevivio los 7 dias." << endl;
    }
    else if (partida.getEstado() == "Derrota") {
        cout << "\n==========================" << endl;
        cout << "        DERROTA" << endl;
        cout << "==========================" << endl;
        cout << "El castillo de Eldoria ha caido." << endl;
    }

    // Actualizar estadisticas del jugador solo si la partida termino
    if (partida.partidaTerminada()) {
        ArchivoJugadores archivo;
        int pos = archivo.buscarPorNombre(jugador.getNombre());
        jugador.actualizarEstadisticas(partida.getPuntaje(), partida.getDia());
        if (pos >= 0) archivo.modificarRegistro(jugador, pos);
        cout << "Puntaje de la partida: " << partida.getPuntaje() << endl;
    }

    return 0;
}
