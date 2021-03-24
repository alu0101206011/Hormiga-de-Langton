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
  int edge = es_una_esquina(hormiga_actual->get_posicion_actual());
  posicion = hormiga_actual->get_posicion_actual();
  if (edge == hormiga_actual->get_direccion()) {
    movimiento_esquina((Direcciones)edge, hormiga_actual);
  } else if (posicion.get_x() < size_.Xmin) {
    movimiento_trivial(arriba, hormiga_actual);
  } else if (posicion.get_x() > size_.Xmax - 1) {
    movimiento_trivial(abajo, hormiga_actual);
  } else if (posicion.get_y() < size_.Ymin) {
    movimiento_trivial(izquierda, hormiga_actual);
  } else if (posicion.get_y() > size_.Ymax - 1) {
    movimiento_trivial(derecha, hormiga_actual);
  }
}


void MundoFinito::movimiento_esquina(const Direcciones& esquina, Hormiga* hormiga) {
  switch (esquina) {
  case arriba_izquierda: hormiga->set_posiciones(size_.Xmax - 1, size_.Ymax - 1); break;
  case arriba_derecha: hormiga->set_posiciones(size_.Xmax - 1, size_.Ymin); break;
  case abajo_izquierda: hormiga->set_posiciones(size_.Xmin, size_.Ymax - 1); break;
  case abajo_derecha: hormiga->set_posiciones(size_.Xmin, size_.Ymin); break;
  default: break;
  }
}


void MundoFinito::movimiento_trivial(const Direcciones& pared, Hormiga* hormiga) {
  switch (pared) {
  case abajo:
    hormiga->set_posiciones(size_.Xmin, hormiga->get_posicion_siguiente().get_y());
    break;
  case arriba: hormiga->set_posiciones(size_.Xmax - 1, hormiga->get_posicion_siguiente().get_y());
    break;
  case derecha: hormiga->set_posiciones(hormiga->get_posicion_siguiente().get_x(), size_.Ymin);
    break;
  case izquierda: hormiga->set_posiciones(hormiga->get_posicion_siguiente().get_x(), size_.Ymax - 1);
    break;
  default: break;
  }
}