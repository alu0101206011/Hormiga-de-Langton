#include <iostream> 
#include <cstdlib>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/reglas.h"
#include "../include/celda.h"
#include "../include/hormiga.h"
#include "../include/vector.h"
#include "../include/mundo.h"


Hormiga::Hormiga(Mundo& mundo, int semilla): direccion_(arriba), mundo_(&mundo) {
  srand(semilla);
  posicion_actual_.set_x((rand() % mundo_->get_size().filas_) + mundo_->get_size().Xmin);
  posicion_actual_.set_y((rand() % mundo_->get_size().columnas_) + mundo_->get_size().Ymin);
  set_posicion_siguiente();
} 

Hormiga::Hormiga(Mundo& mundo, int i, int j): direccion_(arriba), mundo_(&mundo) {
  set_posiciones(i, j);
}

Hormiga::Hormiga(Mundo& mundo): direccion_(arriba), mundo_(&mundo) {
  posicion_actual_.set_x(0);
  posicion_actual_.set_y(0);
  set_posicion_siguiente();
}


Direcciones Hormiga::get_direccion(void) const {
  return direccion_;
}

Posicion Hormiga::get_posicion_actual(void) const {
  return posicion_actual_;
}

Posicion Hormiga::get_posicion_siguiente(void) const {
  return posicion_siguiente_;
}

Regla Hormiga::get_movimiento(void) const {
  return movimiento_;
}

Mundo* Hormiga::get_mundo(void) const {
  return mundo_;
}

int Hormiga::get_color_actual(void) const {
  return mundo_->get_color(posicion_actual_);
}

int Hormiga::get_color_siguiente(void) {
  mundo_->world_edge(this);
  return mundo_->get_color(posicion_siguiente_);
}

void Hormiga::set_direccion(const Direcciones& kNewDireccion) {
  direccion_ = kNewDireccion;
}

void Hormiga::set_posiciones(const Posicion& kNewPosicion) {
  Posicion aux = get_posicion_actual();
  mundo_->world_edge(this);
  if (aux == get_posicion_actual()) {
    set_posicion_actual(kNewPosicion);
    set_posicion_siguiente();
  }
}

void Hormiga::set_posiciones(const int& kNewX, const int& kNewY) {
  Posicion aux = get_posicion_actual();
  mundo_->world_edge(this);
  if (aux == get_posicion_actual()) {
    set_posicion_actual(kNewX, kNewY);
    set_posicion_siguiente();
  }
}

void Hormiga::set_posicion_actual(const Posicion& kNewPosicion) {
  posicion_actual_ = kNewPosicion;
}

void Hormiga::set_posicion_actual(const int& i, const int& j) {
  posicion_actual_.set_x(i);
  posicion_actual_.set_y(j);
}

void Hormiga::set_posicion_siguiente(const Posicion& kNewPosicion) {
  posicion_siguiente_ = kNewPosicion;
}

void Hormiga::set_posicion_siguiente(void) {
  Movimiento move;
  posicion_siguiente_ = *move.get_next_pos(direccion_);  
  posicion_siguiente_ = get_posicion_actual() + posicion_siguiente_;
}

void Hormiga::set_movimiento(const Regla& kNewMovimiento) {
  movimiento_ = kNewMovimiento;
}

void Hormiga::set_mundo(Mundo* const& kNewMundo) {
  mundo_ = kNewMundo;
}

void Hormiga::set_color_actual(const int& kNewColor) {
  mundo_->set_color(posicion_actual_, kNewColor);
}

void Hormiga::set_color_siguiente(const int& kNewColor) {
  mundo_->set_color(posicion_siguiente_, kNewColor);
}


void Hormiga::actualizar_posicion(const Posicion& kNewPosicion) {
  set_posicion_actual(kNewPosicion);
  set_posicion_siguiente();
}

void Hormiga::actualizar_posicion(const int& kNewX, const int& kNewY) {
  set_posicion_actual(kNewX, kNewY);
  set_posicion_siguiente();
}


void Hormiga::cerebro(void) {
  Regla regla;
/*   if (regla.regla1(this)) {
    return;
  } else */ if (regla.regla2(this)) {
    return;
  } else if (regla.regla3(this)) {
    return;
  }
}


std::ostream& operator<<(std::ostream& os, const Hormiga& kHormiga) {
  switch (kHormiga.get_direccion()) {
  case arriba: return os << "↑ ";
  case arriba_derecha: return os << "↗ ";
  case derecha: return os << "⟶ ";
  case abajo_derecha: return os << "↘ ";
  case abajo: return os << "↓ ";
  case abajo_izquierda: return os << "↙ ";
  case izquierda: return os << "⟵ ";
  case arriba_izquierda: return os << "↖ ";
  default: return os << "E ";
  }
}
