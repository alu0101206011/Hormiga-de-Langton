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

Mundo::Mundo(unsigned m, unsigned n): random_(false) { 
  set_size(m,n);
  tablero_.new_size(size_.Xmin,size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    tablero_[i].new_size(size_.Ymin,size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      Celda aux(i,j,0);
      tablero_[i][j] = aux;
    }
  }
}


Mundo::Mundo(): random_(false) {
  set_size(5,5);
  tablero_.new_size(size_.Xmin,size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    tablero_[i].new_size(size_.Ymin,size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      Celda aux(i,j,0);
      tablero_[i][j] = aux;
    }
  }
}


Mundo::Mundo(int random): random_(true) {
  set_size(std::rand() % 10 + 2, std::rand() % 10 + 2);
  tablero_.new_size(size_.Xmin,size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    tablero_[i].new_size(size_.Ymin,size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      Celda aux(i,j,rand() % NUM_COLOR);
      tablero_[i][j] = aux;
    }
  }
}


Mundo::~Mundo() {}


MatrizCeldas Mundo::get_tablero(void) const {
  return tablero_;
}

MatrizCeldas& Mundo::get_tablero(void) {
  return tablero_;
}

BoardSize Mundo::get_size(void) const {
  return size_;
}

unsigned Mundo::get_color(const Posicion& kPosicion) const {
  return tablero_[kPosicion.get_x()][kPosicion.get_y()].get_color();
}

void Mundo::set_tablero(MatrizCeldas const& kNuevoTablero) {
  tablero_ = kNuevoTablero;
}
void Mundo::set_size(int m, int n) {
  assert(m > 1 && n > 1);
  size_.filas_ = m;
  size_.columnas_ = n;
  size_.Xmin = 0 - m / 2;
  size_.Ymin = 0 - n / 2;
  size_.Xmax = (m / 2) + (m % 2);
  size_.Ymax = (n / 2) + (n % 2);
}


void Mundo::set_color(const Posicion& kPosicion, int color) {
  tablero_[kPosicion.get_x()][kPosicion.get_y()].set_color(color);
}


Direcciones Mundo::es_una_esquina(Posicion posicion) {
  if (posicion.get_x() == size_.Xmin && posicion.get_y() == size_.Ymin) {
    return arriba_izquierda;
  } else if (posicion.get_x() == size_.Xmin && posicion.get_y() == size_.Ymax - 1) {
    return arriba_derecha;
  } else if (posicion.get_x() == size_.Xmax - 1 && posicion.get_y() == size_.Ymin) {
    return abajo_izquierda;
  } else if (posicion.get_x() == size_.Xmax - 1 && posicion.get_y() == size_.Ymax - 1) {
    return abajo_derecha;
  }
  return (Direcciones)-1;
}