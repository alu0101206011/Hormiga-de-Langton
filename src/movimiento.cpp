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

Posicion* Movimiento::get_next_pos(const Direcciones& kDireccion) const {
  return direcciones_[kDireccion];
}

Direcciones Movimiento::get_girar_derecha(const Direcciones& kDireccion) const {
  if (kDireccion == arriba) {
    return arriba_izquierda;
  } else {
    return (Direcciones)(kDireccion - 1);
  } 
}

Direcciones Movimiento::get_girar_izquierda(const Direcciones& kDireccion) const {
  if (kDireccion == arriba_izquierda) {
    return arriba;
  } else {
    return (Direcciones)(kDireccion + 1);
  } 
}

Direcciones Movimiento::girar_derecha_puro(const Direcciones& kDireccion) const {
  if (kDireccion == arriba_izquierda || kDireccion == izquierda) {
    return arriba;
  } else if (!es_diagonal(kDireccion)) {
    return (Direcciones)(kDireccion + 2);
  } else {
    return (Direcciones)(kDireccion + 1);
  }
}

Direcciones Movimiento::girar_izquierda_puro(const Direcciones& kDireccion) const {
  if (kDireccion == arriba) {
    return izquierda;
  } else if (!es_diagonal(kDireccion)) {
    return (Direcciones)(kDireccion - 2);
  } else {
    return (Direcciones)(kDireccion - 1);
  }
}

Direcciones Movimiento::get_move_diagonal_derecha(const Direcciones& kDireccion) const {
  if (kDireccion == arriba_izquierda) {
    return arriba_derecha;
  } else if (es_diagonal(kDireccion)) {
    return (Direcciones)(kDireccion + 2);
  } else {
    return (Direcciones)(kDireccion + 1);
  }
}

Direcciones Movimiento::get_move_diagonal_izquierda(const Direcciones& kDireccion) const {
  if (kDireccion == arriba_derecha || kDireccion == arriba) {
    return arriba_izquierda;
  } else if (es_diagonal(kDireccion)) {
    return (Direcciones)(kDireccion - 2);
  } else {
    return (Direcciones)(kDireccion - 1);
  }
}

void Movimiento::set_direccion(Posicion** const& kNewDireccion) {
  direcciones_ = kNewDireccion;
}

bool Movimiento::es_diagonal(const Direcciones& kDireccion) const {
  return (kDireccion == abajo_izquierda || 
          kDireccion == abajo_derecha ||
          kDireccion == arriba_izquierda || 
          kDireccion == arriba_derecha);
}

bool Movimiento::hacia_arriba(const Direcciones& kDireccion) const {
  return (kDireccion == arriba || 
          kDireccion == arriba_izquierda || 
          kDireccion == arriba_derecha);
}

bool Movimiento::hacia_derecha(const Direcciones& kDireccion) const {
  return (kDireccion == derecha || 
          kDireccion == abajo_derecha || 
          kDireccion == arriba_derecha);
}

bool Movimiento::hacia_abajo(const Direcciones& kDireccion) const {
  return (kDireccion == abajo || 
          kDireccion == abajo_izquierda || 
          kDireccion == abajo_derecha);
}

bool Movimiento::hacia_izquierda(const Direcciones& kDireccion) const {
  return (kDireccion == izquierda || 
          kDireccion == abajo_izquierda || 
          kDireccion == arriba_izquierda);
}