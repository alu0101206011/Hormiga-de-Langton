#include <iostream> 
#include <stdlib.h>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/reglas.h"
#include "../include/celda.h"
#include "../include/hormiga.h"
#include "../include/mundo.h"

Hormiga::Hormiga(Mundo& mundo, int semilla): direccion_(arriba), mundo_(&mundo) {
  srand(semilla);
  posicion_actual_.set_x(rand()% mundo_->get_size().filas_);
  posicion_actual_.set_x(rand() % mundo_->get_size().columnas_);
} //En esta semilla del random

Hormiga::Hormiga(Mundo& mundo, Posicion posicion)
    : direccion_(arriba), posicion_actual_(posicion), mundo_(&mundo) {}

Hormiga::Hormiga(Mundo& mundo): direccion_(arriba), mundo_(&mundo) {}

Direcciones Hormiga::get_direccion(void) const {
  return direccion_;
}
Posicion Hormiga::get_posicion_actual(void) const {
  return posicion_actual_;
}
Regla Hormiga::get_movimiento(void) const {
  return movimiento_;
}
Mundo* Hormiga::get_mundo(void) const {
  return mundo_;
}

void Hormiga::set_direccion(const Direcciones& kNewDireccion) {
  direccion_ = kNewDireccion;
}
void Hormiga::set_posicion_actual(const Posicion& kNewPosicion) {
  posicion_actual_ = kNewPosicion;
}
void Hormiga::set_movimiento(const Regla& kNewMovimiento) {
  movimiento_ = kNewMovimiento;
}
void Hormiga::set_mundo(Mundo* const& kNewMundo) {
  mundo_ = kNewMundo;
}