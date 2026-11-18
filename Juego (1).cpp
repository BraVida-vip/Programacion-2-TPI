#include "Juego.h"
#include <iostream>
using namespace std;
Juego::Juego() {}
void Juego::mostrarMenu() { cout<<"=== ELDORIA ==="<<endl<<"1. Iniciar partida"<<endl<<"2. Estadisticas"<<endl<<"3. Creditos"<<endl<<"0. Salir ";
cout<<"Seleccione una opcion..."<<endl; }
void Juego::iniciarPartida() { partidaActual = Partida(1, jugadorActual.getIdJugador(), 1); }
void Juego::ejecutar() {
    int opcion;
    do{
            do{
    mostrarMenu();
    cin>>opcion;
     if (opcion < 0 || opcion > 3) {
        cout<<"Opcion incorrecta. Intente nuevamente."<<endl;
    }
} while (opcion < 0 || opcion > 3);
    switch(opcion){
        case 1:  iniciarPartida();
                 break;
        case 2 : mostrarEstadisticas();
                 break; 
        case 3:  mostrarCreditos();
                 break;        
        case 0:  cout<<"Saliendo de Eldoria..."<<endl;
                 break;
        default: cout<<"Opcion incorrecta"<<endl;
                 break;
}
} while(opcion != 0);
}
void Juego::mostrarEstadisticas() {
    cout<<"=== ESTADISTICAS ==="<<endl;
    cout<<"Puntaje maximo:"<<jugadorActual.getPuntajeMaximo()<<endl;
}
void Juego::mostrarCreditos() {
    cout<<"===== CREDITOS DE ELDORIA ====="<<endl;
    cout<<"Trabajo Practico Integrador GRUPO 23"<<endl;
    cout<<"Universidad: UTN Materia: Programacion II"<<endl;
    cout<<"Desarrollado por:"<<endl;
    cout<<"Mateo Gómez, Evelyn Baini, Brian Vidla, Francisco Valentín Garcia Aller"<<endl;
    cout<<"==============================";
}

Jugador& Juego::getJugadorActual() { return jugadorActual; }
Partida& Juego::getPartidaActual() { return partidaActual; }
