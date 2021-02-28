#include <iostream>

#include "../include/posicion.h"
#include "../include/movimiento.h"


Movimiento::Movimiento(void) {
  direcciones_ = new Posicion*[SIZE_DIRECTIONS];
  for (unsigned i = 0; i < SIZE_DIRECTIONS; i++) {
    direcciones_[i] = new Posicion();
  }
  direcciones_[arriba]->set_x(-1);
  direcciones_[arriba]->set_y(0);
  direcciones_[derecha]->set_x(0);
  direcciones_[derecha]->set_y(1);
  direcciones_[abajo]->set_x(1);
  direcciones_[abajo]->set_y(0);
  direcciones_[izquierda]->set_x(0);
  direcciones_[izquierda]->set_y(-1);
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

Posicion* Movimiento::get_girar_direccion(Direcciones direccion) const {
  return direcciones_[direccion];
}

Direcciones Movimiento::get_girar_derecha(Direcciones direccion) const {
  if (direccion == arriba) {
    return derecha;
  } else if (direccion == derecha) {
    return abajo;
  } else if (direccion == abajo) {
    return izquierda;
  } else {
    return arriba;
  }
}

Direcciones Movimiento::get_girar_izquierda(const Direcciones direccion) const {
  if (direccion == arriba) {
    return izquierda;
  } else if (direccion == izquierda) {
    return abajo;
  } else if (direccion == abajo) {
    return derecha;
  } else {
    return arriba;
  } 
}

void Movimiento::set_direccion(Posicion** const& kNewDireccion) {
  direcciones_ = kNewDireccion;
}