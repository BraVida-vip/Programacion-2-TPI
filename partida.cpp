#include "Partida.h"
#include "Defensa.h"
#include "Enemigo.h"
#include "Muralla.h"
#include "ArchivoPartidas.h"
#include "TORRES.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
Partida::Partida()
    : idPartida(0),
      idJugador(0),
      diaActual(1),
      dificultad(1),
      dinero(100),
      vidas(3),
      puntaje(0),
      estado("En curso"),
      indiceOleada(0),
      oleadaIniciada(false),
      ultimaActualizacion(std::chrono::steady_clock::now()) {
      int cantidades[7] = {5, 6, 6, 8, 8, 5, 1};
      for (int i = 0; i < 7; i++) {
      oleadas.emplace_back(i + 1, i + 1, cantidades[i]);}}
      Partida::Partida(int id, int jugador, int dif)
    : idPartida(id),
      idJugador(jugador),
      diaActual(1),
      dificultad(dif),
      dinero(100),
      vidas(3),
      puntaje(0),
      estado("En curso"),
      indiceOleada(0),
      oleadaIniciada(false),
      ultimaActualizacion(std::chrono::steady_clock::now()) {
      int cantidades[7] = {5, 6, 6, 8, 8, 5, 1};
      for (int i = 0; i < 7; i++) {
        oleadas.emplace_back(i + 1, i + 1, cantidades[i]);}}
void Partida::iniciarOleada() {
      if (indiceOleada < (int)oleadas.size() && !oleadaIniciada) {
      oleadas[indiceOleada].generarEnemigos();
      generarEvento();
      aplicarEvento();
      oleadaIniciada = true;
      ultimaActualizacion = std::chrono::steady_clock::now();}}
void Partida::actualizarPartida() {
      if (partidaTerminada()) {
      return;}
      if (indiceOleada >= (int)oleadas.size()) {
      estado = "Victoria";
      return;}
      if (!oleadaIniciada) {
      iniciarOleada();}
      auto ahora = std::chrono::steady_clock::now();
      float tiempoTranscurrido =
      std::chrono::duration<float>(
      ahora - ultimaActualizacion).count();
      ultimaActualizacion = ahora;
      if (eventoActual.estaActivo() &&
      eventoActual.getDuracion() > 0) {
      tiempoEvento += tiempoTranscurrido;
      if (tiempoEvento >= eventoActual.getDuracion()) {
      finalizarEvento();}}
      Oleada& oleada = oleadas[indiceOleada];
      oleada.actualizarApariciones(tiempoTranscurrido);
      const std::vector<Enemigo*>& enemigos = oleada.getEnemigos();
      int cantidadActivos = oleada.getCantidadActivos();
      for (auto& colocacion : defensas) {
      Defensa* torre = colocacion.getDefensa();
      if (torre == nullptr || !torre->puedeAtacar()) {
      continue;}
      if (torre->estaEliminada()) {
      continue;}
      float posicionTorre = colocacion.getPosicion();
      if (dynamic_cast<TorreArquera*>(torre) != nullptr){
      Enemigo* objetivo = nullptr;
      for (int i = 0; i < cantidadActivos; i++) {
      Enemigo* enemigo = enemigos[i];
      if (enemigo == nullptr || enemigo->fueEliminado()) {
      continue;}
      float distancia =
      std::fabs(enemigo->getPosicion() - posicionTorre);
      if (distancia <= torre->getAlcance()){
      if (objetivo == nullptr ||
      enemigo->getPosicion() > objetivo->getPosicion()) {
      objetivo = enemigo;}}}
      if (objetivo != nullptr) {
      objetivo->recibirDano(torre->getDano());
      torre->registrarAtaque();
      if (objetivo->fueEliminado()) {
      agregarDinero(objetivo->getRecompensa());
      puntaje += 10;}}}
      else if (dynamic_cast<TorreFuego*>(torre) != nullptr) {
      bool ataco = false;
      for (int i = 0; i < cantidadActivos; i++) {
      Enemigo* enemigo = enemigos[i];
      if (enemigo == nullptr || enemigo->fueEliminado()) {
      continue;}
      float distancia =
      std::fabs(enemigo->getPosicion() - posicionTorre);
      if (distancia <= torre->getAlcance()) {
      enemigo->recibirDano(torre->getDano());
      ataco = true;
      if (enemigo->fueEliminado()) {
      agregarDinero(enemigo->getRecompensa());
      puntaje += 10;}}}
      if (ataco) {
      torre->registrarAtaque();}}
      else if (dynamic_cast<TorreHielo*>(torre) != nullptr) {
      Enemigo* objetivo = nullptr;
      for (int i = 0; i < cantidadActivos; i++) {
      Enemigo* enemigo = enemigos[i];
      if (enemigo == nullptr || enemigo->fueEliminado()) {continue;}
      float distancia =
      std::fabs(enemigo->getPosicion() - posicionTorre);
      if (distancia <= torre->getAlcance()) {
      if (objetivo == nullptr ||
      enemigo->getPosicion() > objetivo->getPosicion()) {
      objetivo = enemigo;}}}
      if (objetivo != nullptr) {
      objetivo->recibirDano(torre->getDano());
      objetivo->ralentizar(0.5f, 3.0f);
      torre->registrarAtaque();
      if (objetivo->fueEliminado()) {
      agregarDinero(objetivo->getRecompensa());
      puntaje += 10;}}}}
      for (int i = 0; i < cantidadActivos; i++) {
      Enemigo* enemigo = enemigos[i];
      if (enemigo == nullptr || enemigo->fueEliminado()) {
      continue;}
      enemigo->avanzar(tiempoTranscurrido);
      if (enemigo->getPosicion() >= 10.0f) {
      fortaleza.recibirDano(enemigo->getDano());
      enemigo->recibirDano(enemigo->getVida());
      if (fortaleza.estaDestruida()) {
      estado = "Derrota";
      finalizarEvento();
      return;}}}
      if (oleada.estaCompleta()) {
      avanzarDia();}}
      void Partida::avanzarDia() {
      if (indiceOleada >= (int)oleadas.size()) {
      return;}
      if (!oleadas[indiceOleada].estaCompleta()) {
      return;}
      finalizarEvento();
      if (diaActual >= 7) {
      estado = "Victoria";
      return;}
      diaActual++;
      indiceOleada++;
      oleadaIniciada = false;
      agregarDinero(40);}
void Partida::construirDefensa(Defensa* d, int p) {
      if (d != nullptr && dinero >= d->getCosto()) {
      dinero -= d->getCosto();
      defensas.emplace_back(
      (int)defensas.size() + 1,
      idPartida,
      d->getIdTorre(),p,d);
      Muralla* muralla = dynamic_cast<Muralla*>(d);
      if (muralla != nullptr) {
      muralla->aumentarResistencia(fortaleza);}}}
bool Partida::mejorarDefensa(int i) {
      if (i < 0 || i >= (int)defensas.size()) {
      return false;}
      Defensa* d = defensas[i].getDefensa();
      int costoMejora = d->getCosto() / 2;
      if (d->getNivel() >= 3 || d->getCosto() == 0 || dinero < costoMejora) {
      return false;}
      dinero -= costoMejora;
      defensas[i].mejorarNivel();
      return true;}
      int Partida::getCantidadDefensas() const {
      return (int)defensas.size();}
void Partida::mostrarDefensas() const {
      if (defensas.empty()) {
      std::cout << "No hay defensas construidas." << std::endl;
      return;}
      for (int i=0;i<(int)defensas.size();i++) {
      Defensa* d = defensas[i].getDefensa();
      cout<<i+1<<". "<<d->getNombre()<<" | nivel "<<d->getNivel()<<" | posicion "<<defensas[i].getPosicion();
      cout<<" | mejora: "<<(d->getNivel()>=3 ? string("nivel maximo") : std::to_string(d->getCosto() / 2) + " oro")<<endl;}}
void Partida::verRecursos() const {
      cout<<"\n========== RECURSOS =========="<<endl;
      cout<<"Dia: "<<diaActual<<endl;
      cout<<"Oro: "<<dinero<<endl;
      cout<<"Vidas: "<<vidas<<endl;
      cout<<"Resistencia: "<<fortaleza.getResistencia()<<endl;
      cout<<"Puntaje: "<<puntaje<<endl;
      cout<<"=============================="<<endl;}
bool Partida::repararFortaleza(){
      if (dinero < 30 || fortaleza.getResistencia() >= fortaleza.getResistenciaMaxima()) {
      return false;}
      dinero -= 30;
      fortaleza.reparar();
      return true;}
bool Partida::guardarPartida() const {
      ArchivoPartidas archivo;
      DatosPartida datos = {};
      datos.idPartida = idPartida;
      datos.idJugador = idJugador;
      datos.diaActual = diaActual;
      datos.dificultad = dificultad;
      datos.dinero = dinero;
      datos.vidas = vidas;
      datos.puntaje = puntaje;
      datos.resistencia = fortaleza.getResistencia();
      datos.resistenciaMaxima = fortaleza.getResistenciaMaxima();
      if (estado == "Victoria") {
      datos.estado = 1;}
      else if (estado == "Derrota") {
      datos.estado = 2;}
      else {
      datos.estado = 0;}
      if (defensas.size() > MAX_DEFENSAS_GUARDADAS) {
      return false;}
      datos.cantidadDefensas = static_cast<int>(defensas.size());
      for (int i = 0; i < datos.cantidadDefensas; i++) {
      Defensa* defensa = defensas[i].getDefensa();
      if (defensa == nullptr) {
      return false;}
      if (dynamic_cast<TorreArquera*>(defensa)) {
      datos.defensas[i].tipo = 1;}
      else if (dynamic_cast<TorreFuego*>(defensa)) {
      datos.defensas[i].tipo = 2;}
      else if (dynamic_cast<TorreHielo*>(defensa)) {
      datos.defensas[i].tipo = 3;}
      else if (dynamic_cast<Muralla*>(defensa)) {
      datos.defensas[i].tipo = 4;}
      else {
      return false;}
      datos.defensas[i].id = defensa->getIdTorre();
      datos.defensas[i].posicion = defensas[i].getPosicion();
      datos.defensas[i].nivel = defensas[i].getNivelActual();}
      return archivo.guardar(datos);}
bool Partida::cargarPartida(int idJugadorBuscado) {
      ArchivoPartidas archivo;
      DatosPartida datos;
      if (!archivo.cargar(idJugadorBuscado, datos)) {
      return false;}
      idPartida=datos.idPartida;
      idJugador=datos.idJugador;
      diaActual=datos.diaActual;
      dificultad=datos.dificultad;
      dinero = datos.dinero;
      vidas = datos.vidas;
      puntaje = datos.puntaje;
      if (datos.estado == 1) {
      estado = "Victoria";}
      else if (datos.estado == 2) {
      estado = "Derrota";}
      else {
      estado = "En curso";}
      fortaleza.restaurar(datos.resistencia,
      datos.resistenciaMaxima);
      if (diaActual < 1 || diaActual > 7) {
      return false;}
      indiceOleada = diaActual - 1;
      oleadaIniciada = false;
      ultimaActualizacion = std::chrono::steady_clock::now();
      defensas.clear();
      for (int i = 0; i < datos.cantidadDefensas; i++) {
      Defensa* defensa = nullptr;
      int tipo = datos.defensas[i].tipo;
      int id = datos.defensas[i].id;
      int posicion = datos.defensas[i].posicion;
      int nivel = datos.defensas[i].nivel;
      switch (tipo) {
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
         default:
        return false;}
      if (nivel < 1) {
      delete defensa;
      return false;}
      DefensaColocada colocada(i + 1,idPartida,id,posicion,defensa);
      for (int j = 1; j < nivel; j++) {
      colocada.mejorarNivel();}
      defensas.push_back(colocada);}
      return true;}
void Partida::agregarOleada(const Oleada& o) {
      oleadas.push_back(o);}
void Partida::agregarDinero(int c) {
      if (c > 0) {
      dinero += c;}}
int Partida::getPuntaje() const {
      return puntaje;}
int Partida::getDinero() const {
      return dinero;}
int Partida::getVidas() const {
      return vidas;}
int Partida::getDia() const {
      return diaActual;}
int Partida::getResistencia() const {
      return fortaleza.getResistencia();}
      string Partida::getEstado() const {
      return estado;}
bool Partida::partidaTerminada() const {
      return estado != "En curso" || fortaleza.estaDestruida();}
void Partida::setEstado(const std::string& e) {
      estado = e;}
void Partida::mostrarCombate() const {
      cout<<"========== ELDORIA =========="<<endl;
      verRecursos();
      mostrarEvento();
      cout<<"============================="<<endl;
      cout<<"CAMPO DE BATALLA"<<endl;
      cout<<"Entrada               Fortaleza"<<endl;
      for (int i = 0; i <= 10; i++) {
      cout<<i<<" ";}
      cout<<endl;
      for (int i = 0; i <= 10; i++) {
      bool hayDefensa = false;
      for (int j = 0; j < getCantidadDefensas(); j++) {
      if (defensas[j].getPosicion() == i) {
      hayDefensa = true;}}
      if (hayDefensa) {
      cout<<"T ";}
      else {
      cout<<"- ";}}
      cout<<endl;
      if (indiceOleada < oleadas.size()) {
      const vector<Enemigo*>& enemigos =
      oleadas[indiceOleada].getEnemigos();
      for (int i = 0; i <= 10; i++) {
      bool hayEnemigo = false;
      for (int j = 0;
      j < oleadas[indiceOleada].getCantidadActivos(); j++) {
      if (!enemigos[j]->fueEliminado() &&
      int(enemigos[j]->getPosicion()) == i) {
      hayEnemigo = true;}}
      if (hayEnemigo) {cout<<"E ";}
      else {cout<<"- ";}}}
      cout<<endl;
      cout<<"============================="<<endl;
      mostrarDefensas();}
void Partida::generarEvento() {
      int numero = rand() % 5 + 1;
      switch (numero) {
      case 1:
      eventoActual = Evento("Bendicion de los templarios","Recibes 50 monedas de oro.",0);
      break;
      case 2:
      eventoActual = Evento("Tormenta de hielo","Los enemigos se ralentizan.",5);
      break;
      case 3:
      eventoActual = Evento("Sabotaje enemigo","Una torre queda desactivada.",5);
      break;
      case 4:
      eventoActual = Evento("Ataque de Mordak","La fortaleza pierde 100 de resistencia.",0);
      break;
      case 5:
      eventoActual = Evento("Refuerzos del reino","La fortaleza aumenta su resistencia en 100.",0);
      break;}}
void Partida::mostrarEvento() const {
      if (eventoActual.estaActivo()) {
      cout<<"========== EVENTO =========="<<endl;
      cout<<eventoActual.getNombre()<<endl;
      cout<<eventoActual.getDescripcion()<<endl;
      cout<<"============================"<<endl;}}
void Partida::aplicarEvento() {
      if (eventoActual.estaActivo()) {
      return;}
      eventoActual.aplicar();
      tiempoEvento = 0.0f;
      if (eventoActual.getNombre() == "Bendicion de los templarios") {
      agregarDinero(50);}
      else if (eventoActual.getNombre() == "Ataque de Mordak") {
      fortaleza.recibirDano(100);
      if (fortaleza.estaDestruida()) {
      estado = "Derrota";}}
      else if (eventoActual.getNombre() == "Refuerzos del reino") {
      fortaleza.aumentarResistencia(100);}
      else if (eventoActual.getNombre() == "Sabotaje enemigo") {
      for (int i = 0; i < getCantidadDefensas(); i++) {
      Defensa* defensa = defensas[i].getDefensa();
      if (defensa != nullptr &&
      defensa->getDano() > 0 &&
      !defensa->estaEliminada() &&
      !defensa->estaDesactivada()) {
      defensaSaboteada = defensa;
      defensaSaboteada->setDesactivada(true);
      break;}}}}
void Partida::finalizarEvento() {
      if (defensaSaboteada != nullptr) {
      defensaSaboteada->setDesactivada(false);
      defensaSaboteada = nullptr;}
      eventoActual.finalizar();
      tiempoEvento = 0.0f;}
void Partida::liberarMemoria() {
      finalizarEvento();
      for (int i = 0; i < getCantidadDefensas(); i++) {
      Defensa* defensa = defensas[i].getDefensa();
      delete defensa;}
      defensas.clear();
      for (int i = 0; i < (int)oleadas.size(); i++) {
      oleadas[i].liberarEnemigos();}
      oleadas.clear();}
