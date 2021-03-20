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
#include "../include/mundoinfinito.h"

MundoInfinito::MundoInfinito(): Mundo() {}


MundoInfinito::MundoInfinito(unsigned m, unsigned n): Mundo(m,n) {}


MundoInfinito::MundoInfinito(int seed): Mundo(seed) {}


void MundoInfinito::ampliar_izquierda(int add) {
  MatrizCeldas aux(size_.Xmin, size_.Xmax);
  int j_tab = size_.Ymin + add;

  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      if (j < size_.Ymin + add) {
        Celda aux_celda(i, j, rand() % NUM_COLOR * random_);
        aux[i][j] = aux_celda;
      } else {
        Celda aux_celda(i,j, get_tablero()[i][j_tab].get_color());
        aux[i][j] = aux_celda;
        j_tab++;
      }
    }
    j_tab = size_.Ymin + add;
  }
  get_tablero().~Vector();
  get_tablero() = aux;
  aux.~Vector();
}


void MundoInfinito::ampliar_arriba(int add) {
  MatrizCeldas aux(size_.Xmin, size_.Xmax);

  for (int i = size_.Xmin, i_tab = size_.Xmin + add; i < size_.Xmax; i++, i_tab++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      if (i < size_.Xmin + add) {  
        Celda aux_celda(i, j, rand() % NUM_COLOR * random_);
        aux[i][j] = aux_celda;
        i_tab = size_.Xmin + add - 1;
      } else {
        Celda aux_celda(i,j, get_tablero()[i_tab][j].get_color());
        aux[i][j] = aux_celda;
      }
    }
  }
  get_tablero().~Vector();
  get_tablero() = aux;
  aux.~Vector();
}


void MundoInfinito::ampliar_derecha(int add) {
  MatrizCeldas aux(size_.Xmin, size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      if (size_.Ymax - add <= j) { 
        Celda aux_celda(i, j, rand() % NUM_COLOR * random_);
        aux[i][j] = aux_celda;
      } else {
        Celda aux_celda(i,j, get_tablero()[i][j].get_color());
        aux[i][j] = aux_celda;
      }
    }
  }
  get_tablero().~Vector();
  get_tablero() = aux;
  aux.~Vector();
}


void MundoInfinito::ampliar_abajo(int add) {
  MatrizCeldas aux(size_.Xmin, size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      if (size_.Xmax - add <= i) { 
        Celda aux_celda(i, j, rand() % NUM_COLOR * random_);
        aux[i][j] = aux_celda;
      } else {
        Celda aux_celda(i,j, get_tablero()[i][j].get_color());
        aux[i][j] = aux_celda;
      }
    }
  }
  get_tablero().~Vector();
  get_tablero() = aux;
  aux.~Vector();
}


void MundoInfinito::decrementar_izquierda(int add) {
  size_.columnas_ = size_.columnas_ + add;
  size_.Ymin = size_.Ymin - add; 
  MatrizCeldas aux(size_.Xmin, size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      Celda aux_celda(i,j, get_tablero()[i][j].get_color());
      aux[i][j] = aux_celda;
    }
  }
  get_tablero().~Vector();
  get_tablero() = aux;
  aux.~Vector();
}


void MundoInfinito::decrementar_arriba(int add) {
  size_.filas_ = size_.filas_ + add;
  size_.Xmin = size_.Xmin - add;
  MatrizCeldas aux(size_.Xmin, size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      Celda aux_celda(i,j, get_tablero()[i][j].get_color());
      aux[i][j] = aux_celda;
    }
  }
  get_tablero().~Vector();
  get_tablero() = aux;
  aux.~Vector();
}


void MundoInfinito::decrementar_derecha(int add) {
  size_.columnas_ = size_.columnas_ + add;
  size_.Ymax = size_.Ymax + add;
  MatrizCeldas aux(size_.Xmin, size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      Celda aux_celda(i,j, get_tablero()[i][j].get_color());
      aux[i][j] = aux_celda;
    }
  }
  get_tablero().~Vector();
  get_tablero() = aux;
  aux.~Vector();
}


void MundoInfinito::decrementar_abajo(int add) {
  size_.filas_ = size_.filas_ + add;
  size_.Xmax = size_.Xmax + add;
  MatrizCeldas aux(size_.Xmin, size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    aux[i].new_size(size_.Ymin, size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      Celda aux_celda(i,j, get_tablero()[i][j].get_color());
      aux[i][j] = aux_celda;
    }
  }
  get_tablero().~Vector();
  get_tablero() = aux;
  aux.~Vector();
}


void MundoInfinito::world_edge(Hormiga* hormiga_actual) {
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


void MundoInfinito::change_size(Direcciones dir, int add) {
  switch (dir) {
  case arriba:
    size_.filas_ = size_.filas_ + add;
    size_.Xmin = size_.Xmin - add;
    ampliar_arriba(add);
    //decrementar_abajo(-add);
    break;
  case derecha:
    size_.columnas_ = size_.columnas_ + add;
    size_.Ymax = size_.Ymax + add;
    ampliar_derecha(add);
    //decrementar_izquierda(-add);
    break;
  case abajo:
    size_.filas_ = size_.filas_ + add;
    size_.Xmax = size_.Xmax + add;
    ampliar_abajo(add);
    //decrementar_arriba(-add);
    break;
  case izquierda:
    size_.columnas_ = size_.columnas_ + add;
    size_.Ymin = size_.Ymin - add;  
    ampliar_izquierda(add);
    //decrementar_derecha(-add);
    break;
  default:
    std::cout << "Error: Dirección incorrecta.\n";
    break;
  }
}


void MundoInfinito::change_size_esquinas(Direcciones dir, int add) {
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