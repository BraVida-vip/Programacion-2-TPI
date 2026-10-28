#include <iostream>
#include "Partida.h"

using namespace std;

int main()
{
    Partida partida;

    while (partida.getDia() <= 7 && partida.getResistencia() > 0)
    {
        cout << "\n==========================" << endl;
        cout << "       DIA " << partida.getDia() << endl;
        cout << "==========================" << endl;

        cout << "Oro: " << partida.getOro() << endl;
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
