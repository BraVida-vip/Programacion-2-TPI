#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include "GestorArchivos.h"
#include <vector>
#include "TORRES.h"
#include "Muralla.h"
#include <thread>
#include <chrono>
using namespace std;
Juego::Juego() {}
void Juego::mostrarMenu() {
        system("cls");
        cout<<"=== ELDORIA ==="<<endl<<"1. Iniciar partida"<<endl<<"2. Estadisticas"<<endl<<"3. Creditos"<<endl<<"0. Salir ";
        cout<<"Seleccione una opcion..."<<endl; }
void Juego::iniciarPartida() {
        system("cls");
        int opcion;
        jugadorActual = Jugador();
        do {
        cout<<"=== INICIAR PARTIDA ==="<<endl;
        cout<<"1. Elegir jugador"<<endl;
        cout<<"2. Registrar jugador"<<endl;
        cout<<"0. Volver"<<endl;
        cout<<"Seleccione una opcion..."<<endl;
        cin>>opcion;
        if(opcion<0 || opcion>2) {
        cout<<"Opcion incorrecta. Intente nuevamente."<<endl;}}
        while(opcion<0 || opcion>2);
        switch (opcion){
        case 1:
            elegirJugador();
            break;
        case 2:
            registrarJugador();
            break;
        case 0:
            return;}
        if (jugadorActual.getIdJugador() != 0) {
        partidaActual = Partida(1, jugadorActual.getIdJugador(), 1);
        if (partidaActual.cargarPartida(jugadorActual.getIdJugador())) {
        system("cls");
        cout<<"=== PARTIDA GUARDADA ==="<<endl;
        cout<<"1. Continuar partida"<<endl;
        cout<<"2. Iniciar nueva partida"<<endl;
        cout<<"0. Volver"<<endl;
        do {
        cout<<"Seleccione una opcion: ";
        cin>>opcion;
        if (opcion < 0 || opcion > 2) {
        cout<<"Opcion incorrecta."<<endl;}}
        while (opcion < 0 || opcion > 2);
        if (opcion == 0) {
        partidaActual.liberarMemoria();
        return;}
        if (opcion == 2) {
            partidaActual.liberarMemoria();
            partidaActual = Partida(1, jugadorActual.getIdJugador(), 1);}}
        else {
        partidaActual = Partida(1, jugadorActual.getIdJugador(), 1);}
        menuPartida();
        partidaActual.liberarMemoria();}}
void Juego::ejecutar() {
        int opcion;
        do{
        do{
        mostrarMenu();
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        if (opcion < 0 || opcion > 3) {
        cout<<"Opcion incorrecta. Intente nuevamente."<<endl;}}
        while (opcion < 0 || opcion > 3);
        switch(opcion){
        case 1:  iniciarPartida();
            break;
        case 2 : mostrarEstadisticas();
            break;
        case 3:  system("cls");
            mostrarCreditos();
            system("pause");
            break;
        case 0:  cout<<"Saliendo de Eldoria..."<<endl;
            break;
        default: cout<<"Opcion incorrecta"<<endl;
            break;}}       while(opcion != 0);}
void Juego::mostrarEstadisticas() {
        system("cls");
        GestorArchivos gestor;
        vector<Jugador> jugadores;
        cout<<"========== ESTADISTICAS =========="<<endl;
        if (!gestor.cargarJugadores(jugadores)) {
        cout<<"No se pudieron cargar los jugadores."<<endl;
        system("pause");
        return;}
        if (jugadores.empty()) {
        cout<<"No hay jugadores registrados."<<endl;}
        for (int i = 0; i < jugadores.size(); i++) {
        if (!jugadores[i].getEliminado()) {
        cout<<"Jugador: "<<jugadores[i].getNombre()<<endl;
        cout<<"Puntaje maximo: "<<jugadores[i].getPuntajeMaximo()<<endl;
        cout<<"Nivel maximo: "<<jugadores[i].getNivelMaximo()<<endl;
        cout<<"Partidas jugadas: "<<jugadores[i].getPartidasJugadas()<<endl;
        cout<<"=================================="<<endl;}}
        system("pause");}
void Juego::mostrarCreditos() {
        system("cls");
        cout<<"===== CREDITOS DE ELDORIA ====="<<endl;
        cout<<"Trabajo Practico Integrador GRUPO 23"<<endl;
        cout<<"Universidad: UTN Materia: Programacion II"<<endl;
        cout<<"Desarrollado por:"<<endl;
        cout<<"Mateo Gomez, Evelyn Baini, Brian Vidla, Francisco Valentin Garcia Aller"<<endl;
        cout<<"=============================="<<endl;
        system("pause");}
        Jugador& Juego::getJugadorActual() { return jugadorActual; }
        Partida& Juego::getPartidaActual() { return partidaActual; }
        void Juego::elegirJugador() {
        system("cls");
        GestorArchivos gestor;
        vector<Jugador>jugadores;
        int id;
        cout<<"=== ELEGIR JUGADOR ==="<<endl;
        gestor.cargarJugadores(jugadores);
        if (jugadores.empty()) {
        cout<<"No hay jugadores disponibles."<<endl;
        system("pause");
        return;}
        for (int i = 0; i < jugadores.size(); i++) {
        if (!jugadores[i].getEliminado()) {
        cout<<"ID: "<<jugadores[i].getIdJugador()<<" - Nombre: "<< jugadores[i].getNombre()<<endl;}}
         cout<<"Ingrese el ID del jugador: ";
         cin>>id;
         for(int i = 0; i < jugadores.size(); i++) {
         if (jugadores[i].getIdJugador() == id &&
         !jugadores[i].getEliminado()) {
         jugadorActual=jugadores[i];
         cout<<"Jugador seleccionado correctamente."<<endl;
         cout<<"Bienvenido a Eldoria, "<<jugadorActual.getNombre()<<endl;
         system("pause");
         system("cls");
         return;}}
         cout << "Jugador no encontrado." << endl;
         system("pause");
         system("cls");}
void Juego::registrarJugador() {
         system("cls");
         GestorArchivos gestor;
         vector<Jugador> jugadores;
         gestor.cargarJugadores(jugadores);
         char nombre[30];
         int id = 1;
         for (int i = 0; i < jugadores.size(); i++) {
         if (jugadores[i].getIdJugador() >= id) {id=jugadores[i].getIdJugador() + 1;}}
         cout << "=== REGISTRAR JUGADOR ==="<<endl;
         cout << "Ingrese su nombre: ";
         cin.ignore();
         cin.getline(nombre, 30);
         jugadorActual = Jugador(id, nombre);
         jugadores.push_back(jugadorActual);
         if (gestor.guardarJugadores(jugadores)) {
         cout<<"Jugador registrado correctamente."<<endl;
         cout<<"Bienvenido a Eldoria, "
            << jugadorActual.getNombre()<<endl;}
         else {
         cout << "Error al guardar el jugador." << endl;
         jugadorActual = Jugador();}
         system("pause");
         system("cls");}
void Juego::menuPartida() {
         int opcion;
         do {
         system("cls");
         cout<<"========== ELDORIA =========="<<endl;
         cout<<"Jugador: "<<jugadorActual.getNombre()<<endl;
         partidaActual.verRecursos();
         cout<<"1. Construir defensa"<<endl;
         cout<<"2. Mejorar defensa"<<endl;
         cout<<"3. Mostrar defensas"<<endl;
         cout<<"4. Reparar fortaleza"<<endl;
         cout<<"5. Iniciar oleada"<<endl;
         cout<<"6. Guardar partida"<<endl;
         cout<<"0. Volver al menu principal"<<endl;
         cout<<"Seleccione una opcion: ";
         cin>>opcion;
         switch (opcion) {
         case 1:
            construirDefensa();
            break;
         case 2:
            break;
         case 3:
            system("cls");
            partidaActual.mostrarDefensas();
            system("pause");
            break;
         case 4:
            system("cls");
            if (partidaActual.repararFortaleza()) {
            cout<<"Fortaleza reparada."<<endl;}
         else {
            cout<<"No se pudo reparar la fortaleza."<<endl;}
            system("pause");
            break;
         case 5:
            iniciarOleada();
            break;
         case 6:
            system("cls");
            if (partidaActual.guardarPartida()) {
            cout<<"Partida guardada correctamente."<<endl;}
            else {
            cout<<"Error al guardar la partida."<<endl;}
            system("pause");
            break;
         case 0:
            break;
         default:
            cout<<"Opcion incorrecta."<<endl;
            system("pause");
            break;}}        while (opcion != 0 &&
         !partidaActual.partidaTerminada());}
void Juego::construirDefensa() {
         system("cls");
         int opcion;
         int posicion;
         Defensa* defensa = nullptr;
         int id = partidaActual.getCantidadDefensas() + 1;
         cout<<"=== CONSTRUIR DEFENSA ==="<<endl;
         cout<<"Oro disponible: "<<partidaActual.getDinero()<<endl;
         cout<<"1. Torre Arquera - 50 oro"<<endl;
         cout<<"2. Torre Fuego - 80 oro"<<endl;
         cout<<"3. Torre Hielo - 70 oro"<<endl;
         cout<<"4. Muralla - 75 oro"<<endl;
         cout<<"0. Volver"<<endl;
         cout<<"Seleccione una opcion: ";
         cin>>opcion;
         switch(opcion) {
         case 1:
            defensa = new TorreArquera(id);
            break;
         case 2:
            defensa = new TorreFuego(id);
            break;
         case 3:
            defensa = new TorreHielo(id);
            break;
         case 4:
            defensa = new Muralla(id);
            break;
         case 0:
            return;
         default:
            cout<<"Opcion incorrecta."<<endl;
            system("pause");
            return;}
         if (partidaActual.getDinero() < defensa->getCosto()) {
         cout<<"No tiene suficiente oro."<<endl;
         delete defensa;
         system("pause");
         return;}
         cout<<"Ingrese la posicion de la defensa (0 a 10): ";
         cin>>posicion;
         if (posicion < 0 || posicion > 10) {
         cout<<"Posicion incorrecta."<<endl;
         delete defensa;
         system("pause");
         return;}
         partidaActual.construirDefensa(defensa, posicion);
         cout<<"Defensa construida correctamente."<<endl;
         system("pause");}
void Juego::iniciarOleada() {
         system("cls");
         int dia = partidaActual.getDia();
         cout<<"=== COMIENZA LA OLEADA ==="<<endl;
         cout<<"Dia: "<<dia<<endl;
         partidaActual.iniciarOleada();
         while (!partidaActual.partidaTerminada() &&
         partidaActual.getDia() == dia) {
         system("cls");
         partidaActual.mostrarCombate();
         partidaActual.actualizarPartida();
         std::this_thread::sleep_for(
         std::chrono::milliseconds(200));}
         system("cls");
         if (partidaActual.getEstado() == "Victoria") {
         cout<<"Felicidades! Has defendido Eldoria."<<endl;}
         else if (partidaActual.getEstado() == "Derrota") {
         cout<<"La fortaleza ha sido destruida."<<endl;}
         else {
         cout<<"Oleada superada correctamente."<<endl;
         partidaActual.verRecursos();}
         if (partidaActual.partidaTerminada()) {
         guardarEstadisticas();}
         system("pause");}
void Juego::guardarEstadisticas() {
         GestorArchivos gestor;
         vector<Jugador> jugadores;
         if (!gestor.cargarJugadores(jugadores)) {
         cout<<"Error al cargar jugadores."<<endl;
         return;}
    jugadorActual.actualizarEstadisticas(
         partidaActual.getPuntaje(),
         partidaActual.getDia());
         for (int i = 0; i < jugadores.size(); i++) {
         if (jugadores[i].getIdJugador() ==
         jugadorActual.getIdJugador()) {
         jugadores[i] = jugadorActual;
         if (gestor.guardarJugadores(jugadores)) {
         cout<<"Estadisticas guardadas correctamente."<<endl;}
         else {
         cout<<"Error al guardar estadisticas."<<endl;}
         return;
}}}
