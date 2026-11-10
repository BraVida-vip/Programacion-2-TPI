#include <iostream>
#include "Partida.h"
#include "IngresoJugador.h"

using namespace std;

int main()
{
    Jugador jugador = ingresarJugador();

    Partida partida;

    while (partida.getDia() <= 7 && partida.getResistencia() > 0)
    {
        cout << "\n==========================" << endl;
        cout << "       DIA " << partida.getDia() << endl;
        cout << "==========================" << endl;

        cout << "Oro: " << partida.getDinero() << endl;
        cout << "Castillo: " << partida.getResistencia() << endl;

        cout << "\nComienza la oleada "
             << partida.getDia()
             << "..." << endl;

        // Aca despues agregamos el combate
        // enemigos, torres, daño, recompensas, etc.

        if (partida.getDia() == 7)
        {
            break;
        }

        partida.avanzarDia();
    }

    if (partida.getResistencia() > 0)
    {
        cout << "\n==========================" << endl;
        cout << "       VICTORIA!" << endl;
        cout << "==========================" << endl;
        cout << "Eldoria sobrevivio los 7 dias." << endl;
    }
    else
    {
        cout << "\n==========================" << endl;
        cout << "        DERROTA" << endl;
        cout << "==========================" << endl;
        cout << "El castillo de Eldoria ha caido." << endl;
    }

    return 0;
}
/**
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "Partida.h"
#include "TorreArquera.h"
#include "TorreFuego.h"
#include "TorreHielo.h"

using namespace std;

// MOSTRAR MENU
void mostrarMenu() {

system("cls");

cout << "\n========================================" << endl;
cout << "          DEFENSA DE ELDORIA" << endl;
cout << "========================================" << endl;

cout << "\n                 CONTROLES" << endl;
cout << "----------------------------------------" << endl;

cout << "  1. Construir defensa" << endl;
cout << "  2. Mejorar defensa" << endl;
cout << "  3. Ver recursos" << endl;
cout << "  4. Reparar fortaleza" << endl;
cout << "  5. Iniciar oleada" << endl;
cout << "  6. Guardar partida" << endl;
cout << "  7. Salir" << endl;

cout << "----------------------------------------" << endl;
cout << "\nSeleccione una opcion: ";

}

int main() {

// CREAR PARTIDA
Partida partida;

// CREAR TORRES
TorreArquera arquera(1);
TorreFuego fuego(2);

// COLOCAR TORRES
partida.construirDefensa(&arquera, 4);
partida.construirDefensa(&fuego, 7);

cout << "\n==================================" << endl;
cout << "       DEFENSA DE ELDORIA" << endl;
cout << "==================================" << endl;

cout << "\nComienza la batalla..." << endl;

cout << "\nTorres colocadas:" << endl;
cout << "- Torre Arquera: posicion 4" << endl;
cout << "- Torre Fuego: posicion 7" << endl;

cout << "\nOro inicial: " << partida.getDinero() << endl;

cout << "\nPresione ENTER para continuar...";
cin.get();

mostrarMenu();

return 0;

}
*/
