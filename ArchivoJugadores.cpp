#include "ArchivoJugadores.h"
#include <cstdio>
#include <cstring>
#include <cctype>

static bool iguales(const char* a, const char* b) {
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) return false;
        a++; b++;
    }
    return *a == *b;
}

ArchivoJugadores::ArchivoJugadores(const char* nombre) {
    strncpy(nombreArchivo, nombre, sizeof(nombreArchivo) - 1);
    nombreArchivo[sizeof(nombreArchivo) - 1] = '\0';
}

bool ArchivoJugadores::agregarRegistro(const Jugador& reg) {
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Jugador), 1, p) == 1;
    fclose(p);
    return ok;
}

bool ArchivoJugadores::modificarRegistro(const Jugador& reg, int pos) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Jugador), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Jugador), 1, p) == 1;
    fclose(p);
    return ok;
}

Jugador ArchivoJugadores::leerRegistro(int pos) {
    Jugador reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Jugador), SEEK_SET);
    fread(&reg, sizeof(Jugador), 1, p);
    fclose(p);
    return reg;
}

int ArchivoJugadores::contarRegistros() {
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    long bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Jugador);
}

int ArchivoJugadores::buscarPorNombre(const char* nombre) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Jugador reg = leerRegistro(i);
        if (!reg.getEliminado() && iguales(reg.getNombre(), nombre)) return i;
    }
    return -1;
}

int ArchivoJugadores::generarId() {
    return contarRegistros() + 1;
}
