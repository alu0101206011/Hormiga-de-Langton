#include "../include/posicion.h"
#include "../include/movimiento.h"


Movimiento::Movimiento(void) {
  direcciones_ = new Posicion*[SIZE_DIRECTIONS];
  for (unsigned i = 0; i < SIZE_DIRECTIONS; i++) {
    direcciones_[i] = new Posicion();
  }
  direcciones_[arriba]->set_x(-1);
  direcciones_[arriba]->set_y(0);
  direcciones_[arriba_derecha]->set_x(-1);
  direcciones_[arriba_derecha]->set_y(1);
  direcciones_[derecha]->set_x(0);
  direcciones_[derecha]->set_y(1);
  direcciones_[abajo_derecha]->set_x(1);
  direcciones_[abajo_derecha]->set_y(1);
  direcciones_[abajo]->set_x(1);
  direcciones_[abajo]->set_y(0);
  direcciones_[abajo_izquierda]->set_x(1);
  direcciones_[abajo_izquierda]->set_y(-1);
  direcciones_[izquierda]->set_x(0);
  direcciones_[izquierda]->set_y(-1);
  direcciones_[arriba_izquierda]->set_x(-1);
  direcciones_[arriba_izquierda]->set_y(-1);
}

Movimiento::~Movimiento() {
  for (unsigned i = 0; i < SIZE_DIRECTIONS; i++) {
    delete direcciones_[i];
  }
  delete[] direcciones_;
}

Posicion** Movimiento::get_direcciones(void) const {
  return direcciones_;
}

Posicion* Movimiento::get_next_pos(Direcciones direccion) const {
  return direcciones_[direccion];
}

Direcciones Movimiento::get_girar_derecha(Direcciones direccion) const {
  if (direccion == arriba) {
    return arriba_izquierda;
  } else {
    return (Direcciones)(direccion - 1);
  } 
}

Direcciones Movimiento::get_girar_izquierda(const Direcciones direccion) const {
  if (direccion == arriba_izquierda) {
    return arriba;
  } else {
    return (Direcciones)(direccion + 1);
  } 
}

void Movimiento::set_direccion(Posicion** const& kNewDireccion) {
  direcciones_ = kNewDireccion;
}

bool Movimiento::hacia_arriba(const Direcciones& direccion) {
  return (direccion == arriba || 
          direccion == arriba_izquierda || 
          direccion == arriba_derecha);
}

bool Movimiento::hacia_derecha(const Direcciones& direccion) {
  return (direccion == derecha || 
          direccion == abajo_derecha || 
          direccion == arriba_derecha);
}

bool Movimiento::hacia_abajo(const Direcciones& direccion) {
  return (direccion == abajo || 
          direccion == abajo_izquierda || 
          direccion == abajo_derecha);
}

bool Movimiento::hacia_izquierda(const Direcciones& direccion) {
  return (direccion == izquierda || 
          direccion == abajo_izquierda || 
          direccion == arriba_izquierda);
}