#include "TORRES.h"

using namespace std;
// TORRE ARQUERA
TorreArquera::TorreArquera(): Defensa(0, "TorreArquera", 0, 400, 2, 2.0f, 50, 1) {}
TorreArquera::TorreArquera(int id): Defensa(id, "TorreArquera", 0, 400, 2, 2.0f, 50, 1) {}
void TorreArquera::atacar() {}
    string TorreArquera::getTipo() const {
    return "TorreArquera";}
void TorreArquera::dispararRapido() {
    atacar();}

// TORRE FUEGO
TorreFuego::TorreFuego()
    : Defensa(0, "TorreFuego", 1, 500, 3, 0.7f, 80, 1) {}
TorreFuego::TorreFuego(int id)
    : Defensa(id, "TorreFuego", 1, 500, 3, 0.7f, 80, 1) {}
void TorreFuego::atacar() {}
    string TorreFuego::getTipo() const {
    return "TorreFuego";}
void TorreFuego::lanzarArea() {
    atacar();}

// TORRE HIELO
TorreHielo::TorreHielo():Defensa(0, "TorreHielo", 2, 100, 3, 1.0f, 70, 1) {}

TorreHielo::TorreHielo(int id): Defensa(id, "TorreHielo", 2, 100, 3, 1.0f, 70, 1) {}

void TorreHielo::atacar() {}

string TorreHielo::getTipo() const {
    return "TorreHielo";}

void TorreHielo::ralentizarEnemigo() {
    atacar();}


// TORRE HIELO
TorreHielo::TorreHielo():Defensa(0, "TorreHielo", 2, 100, 3, 1.0f, 70, 1) {}

TorreHielo::TorreHielo(int id): Defensa(id, "TorreHielo", 2, 100, 3, 1.0f, 70, 1) {}

void TorreHielo::atacar() {}

string TorreHielo::getTipo() const {
    return "TorreHielo";}

void TorreHielo::ralentizarEnemigo() {
    atacar();}
