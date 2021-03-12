#include <iostream> 
#include <cassert>
#include <cstdlib>
#include <unistd.h>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/celda.h"
#include "../include/reglas.h"
#include "../include/hormiga.h"
#include "../include/vector.h"
#include "../include/mundo.h"
#include "../include/mundofinito.h"

MundoFinito::MundoFinito(): Mundo() {}


MundoFinito::MundoFinito(unsigned m, unsigned n): Mundo(m,n) {}


MundoFinito::MundoFinito(int seed): Mundo(seed) {}


void MundoFinito::world_edge(Hormiga* hormiga_actual) {
  Posicion posicion;
  Movimiento move;
  int flag = -1;
  posicion = hormiga_actual->get_posicion_actual();
  flag = es_una_esquina(posicion);
  if (flag == hormiga_actual->get_direccion()) {
    flag = flag;
  } else if (posicion.get_x() == size_.Xmin && move.hacia_arriba(hormiga_actual->get_direccion())) {
    flag = arriba;
  } else if (posicion.get_x() == size_.Xmax - 1 && move.hacia_abajo(hormiga_actual->get_direccion())) {
    flag = abajo;
  } else if (posicion.get_y() == size_.Ymin && move.hacia_izquierda(hormiga_actual->get_direccion())) {
    flag = izquierda;
  } else if (posicion.get_y() == size_.Ymax - 1 && move.hacia_derecha(hormiga_actual->get_direccion())) {
    flag = derecha;
  } 
  if (!(flag % 2)) {
    movimiento_trivial((Direcciones)flag, hormiga_actual);
  } else if (flag % 2 && flag != -1) {
    movimiento_esquina((Direcciones)flag, hormiga_actual);
  }

}


void MundoFinito::movimiento_esquina(const Direcciones& esquina, Hormiga* hormiga) {
  switch (esquina) {
  case arriba_izquierda: hormiga->actualizar_posicion(size_.Xmax - 1, size_.Ymax - 1); break;
  case arriba_derecha: hormiga->actualizar_posicion(size_.Xmax - 1, size_.Ymin); break;
  case abajo_izquierda: hormiga->actualizar_posicion(size_.Xmin, size_.Ymax - 1); break;
  case abajo_derecha: hormiga->actualizar_posicion(size_.Xmin, size_.Ymin); break;
  default: break;
  }
}


void MundoFinito::movimiento_trivial(const Direcciones& pared, Hormiga* hormiga) {
  switch (pared) {
  case abajo: hormiga->actualizar_posicion(size_.Xmin, hormiga->get_posicion_actual().get_y());
    break;
  case arriba: hormiga->actualizar_posicion(size_.Xmax - 1, hormiga->get_posicion_actual().get_y());
    break;  
  case derecha: hormiga->actualizar_posicion(hormiga->get_posicion_actual().get_x(), size_.Ymin);
    break; 
  case izquierda: hormiga->actualizar_posicion(hormiga->get_posicion_actual().get_x(), size_.Ymax - 1);
    break; 
  default: break;
  }
}