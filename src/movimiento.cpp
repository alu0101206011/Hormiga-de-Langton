#include <iostream>

#include "../include/posicion.h"
#include "../include/movimiento.h"

Movimiento::Movimiento(void) {
  direccion_ = new Posicion*[4];
/*   for (unsigned i = 0; i < 4; i++) {
    direccion_[i] = new Posicion;
  } */
  direccion_[arriba]->set_x(-1);
  direccion_[arriba]->set_y(0);
  direccion_[derecha]->set_x(0);
  direccion_[derecha]->set_y(1);
  direccion_[abajo]->set_x(1);
  direccion_[abajo]->set_y(0);
  direccion_[izquierda]->set_x(0);
  direccion_[izquierda]->set_y(-1);
}

Posicion** Movimiento::get_direccion(void) const {
  return direccion_;
}

void Movimiento::set_direccion(Posicion** const& kNewDireccion) {
  direccion_ = kNewDireccion;
}