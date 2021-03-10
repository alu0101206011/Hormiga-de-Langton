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
  srand(time(NULL));
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

void Mundo::change_size(Direcciones dir, int add) {
  switch (dir) {
  case arriba:
    size_.filas_ = size_.filas_ + add;
    size_.Xmin = size_.Xmin - add;
    ampliar_arriba(add);
    break;
  case derecha:
    size_.columnas_ = size_.columnas_ + add;
    size_.Ymax = size_.Ymax + add;
    ampliar_derecha(add);
    break;
  case abajo:
    size_.filas_ = size_.filas_ + add;
    size_.Xmax = size_.Xmax + add;
    ampliar_abajo(add);
    break;
  case izquierda:
    size_.columnas_ = size_.columnas_ + add;
    size_.Ymin = size_.Ymin - add;  
    ampliar_izquierda(add);
    break;
  default:
    std::cout << "Error: Dirección incorrecta.\n";
    break;
  }
}


void Mundo::change_size_esquinas(Direcciones dir, int add) {
  switch (dir) {
  case arriba_derecha:
    change_size(arriba, add);
    change_size(derecha, add);
    break;
  case arriba_izquierda:
    change_size(arriba, add);
    change_size(izquierda, add);
    break;
  case abajo_derecha:
    change_size(abajo, add);
    change_size(derecha, add);
    break;
  case abajo_izquierda:
    change_size(abajo, add);
    change_size(izquierda, add);
    break;
  default:
    std::cout << "Error: Dirección incorrecta.\n";
    break;
  } 
}


void Mundo::set_color(const Posicion& kPosicion, int color) {
  tablero_[kPosicion.get_x()][kPosicion.get_y()].set_color(color);
}


void Mundo::world_edge(Posicion pos, Hormiga** hormiga) {
  for (unsigned int i = 0; i < HORMIGA_SIZE; i++) {
    if (pos == hormiga[i]->get_posicion_actual()) {
      if (pos.get_x() > size_.Xmax - 1) {
        hormiga[i]->set_posicion_actual(size_.Xmin, pos.get_y());
      } else if (pos.get_x() < size_.Xmin) {
        hormiga[i]->set_posicion_actual(size_.Xmax - 1, pos.get_y());
      } else if (pos.get_y() > size_.Ymax - 1) {
        hormiga[i]->set_posicion_actual(pos.get_x(), size_.Ymin);
      } else if (pos.get_y() < size_.Ymin) {
        hormiga[i]->set_posicion_actual(pos.get_x(), size_.Ymax - 1);
      }
    }
  }
}


void Mundo::ampliar_izquierda(int add) {
  MatrizCeldas aux(size_.Xmin, size_.Xmax);
  int j_tab = size_.Ymin + add;

  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      if (j < size_.Ymin + add) { 
        Celda aux_celda(i, j, rand() % NUM_COLOR * random_);
        aux[i][j] = aux_celda;
      } else {
        Celda aux_celda(i,j, tablero_[i][j_tab].get_color());
        aux[i][j] = aux_celda;
        j_tab++;
      }
    }
    j_tab = size_.Ymin + add;
  }
  tablero_.~Vector();
  tablero_ = aux;
  aux.~Vector();
}


void Mundo::ampliar_arriba(int add) {
  MatrizCeldas aux(size_.Xmin, size_.Xmax);

  for (int i = size_.Xmin, i_tab = size_.Xmin + add; i < size_.Xmax; i++, i_tab++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      if (i < size_.Xmin + add) {  
        Celda aux_celda(i, j, rand() % NUM_COLOR * random_);
        aux[i][j] = aux_celda;
        i_tab = size_.Xmin + add - 1;
      } else {
        Celda aux_celda(i,j, tablero_[i_tab][j].get_color());
        aux[i][j] = aux_celda;
      }
    }
  }
  tablero_.~Vector();
  tablero_ = aux;
  aux.~Vector();
}


void Mundo::ampliar_derecha(int add) {
  MatrizCeldas aux(size_.Xmin, size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      if (size_.Ymax - add <= j) { 
        Celda aux_celda(i, j, rand() % NUM_COLOR * random_);
        aux[i][j] = aux_celda;
      } else {
        Celda aux_celda(i,j, tablero_[i][j].get_color());
        aux[i][j] = aux_celda;
      }
    }
  }
  tablero_.~Vector();
  tablero_ = aux;
  aux.~Vector();
}


void Mundo::ampliar_abajo(int add) {
  MatrizCeldas aux(size_.Xmin, size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      if (size_.Xmax - add <= i) { 
        Celda aux_celda(i, j, rand() % NUM_COLOR * random_);
        aux[i][j] = aux_celda;
      } else {
        Celda aux_celda(i,j, tablero_[i][j].get_color());
        aux[i][j] = aux_celda;
      }
    }
  }
  tablero_.~Vector();
  tablero_ = aux;
  aux.~Vector();
}


void Mundo::movimiento_peligroso(Hormiga* hormiga_actual) {
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
    change_size((Direcciones)flag, ADD_SIZE);
  } else if (flag % 2 && flag != -1) {
    change_size_esquinas((Direcciones)flag, ADD_SIZE);
  }
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

