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


const unsigned NUM_COLOR = 2;
const unsigned HORMIGA_SIZE = 1;


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
  // Vector de 1 hormiga
  srand(time(NULL));
  hormiga_ = new Hormiga*[HORMIGA_SIZE];
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    hormiga_[i] = new Hormiga(*this, rand());
  } 
}


Mundo::Mundo(): random_(false) {
  set_size(25,25);
  tablero_.new_size(size_.Xmin,size_.Xmax);
  for (int i = size_.Xmin; i < size_.Xmax; i++) {
    tablero_[i].new_size(size_.Ymin,size_.Ymax);
    for (int j = size_.Ymin; j < size_.Ymax; j++) {
      Celda aux(i,j,0);
      tablero_[i][j] = aux;
    }
  }
  hormiga_ = new Hormiga*[HORMIGA_SIZE];
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    hormiga_[i] = new Hormiga(*this);
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

  hormiga_ = new Hormiga*[HORMIGA_SIZE];
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    hormiga_[i] = new Hormiga(*this, random);
  }
}


Mundo::~Mundo() {
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    delete hormiga_[i];
  }
  delete[] hormiga_;
}


MatrizCeldas Mundo::get_tablero(void) const {
  return tablero_;
}
BoardSize Mundo::get_size(void) const {
  return size_;
}
Hormiga** Mundo::get_hormiga(void) const {
  return hormiga_;
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

void Mundo::inicio(void) {
  std::cout << *this << "\n";
  for (int i = 0; i < 11500; i++) {
    system("clear");
    for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
      world_edge(hormiga_[i]->get_posicion_actual());
      hormiga_[i]->cerebro();
    }
    std::cout << *this << "\n";
    usleep(100000);
  } 
  std::cout << *this << "\n";
}

void Mundo::world_edge(Posicion pos) {
  for (unsigned int i = 0; i < HORMIGA_SIZE; i++) {
    if (pos == hormiga_[i]->get_posicion_actual()) {
      if (pos.get_x() > size_.Xmax - 1) {
        hormiga_[i]->set_posicion_actual(size_.Xmin, pos.get_y());
      } else if (pos.get_x() < size_.Xmin) {
        hormiga_[i]->set_posicion_actual(size_.Xmax - 1, pos.get_y());
      } else if (pos.get_y() > size_.Ymax - 1) {
        hormiga_[i]->set_posicion_actual(pos.get_x(), size_.Ymin);
      } else if (pos.get_y() < size_.Ymin) {
        hormiga_[i]->set_posicion_actual(pos.get_x(), size_.Ymax - 1);
      }
    }
  }
}


void Mundo::resize(const unsigned kNumPorLado, const int kZonaAmpliar) {
/*   MatrizCeldas aux;
  unsigned fila_original = size_.filas_;
  unsigned columna_original = size_.columnas_;
  if (kZonaAmpliar == arriba || kZonaAmpliar == abajo) {
    ampliar_vertical(kZonaAmpliar, kNumPorLado, aux);
    if (kZonaAmpliar == arriba) {
      for (unsigned i = 0; i < HORMIGA_SIZE; i++) 
        hormiga_[i]->actualizar_posiciones(hormiga_[i]->get_posicion_actual().get_x() + kNumPorLado, hormiga_[i]->get_posicion_actual().get_y());
   } 
  } else if (kZonaAmpliar == izquierda || kZonaAmpliar == derecha) {
    ampliar_horizontal(kZonaAmpliar, kNumPorLado, aux);
    if (kZonaAmpliar == izquierda) {
      for (unsigned i = 0; i < HORMIGA_SIZE; i++) 
        hormiga_[i]->actualizar_posiciones(hormiga_[i]->get_posicion_actual().get_x(), hormiga_[i]->get_posicion_actual().get_y() + kNumPorLado);
    } 
  }
  eliminar_espacio(tablero_, fila_original, columna_original);
  tablero_ = aux;
  **aux = NULL;
  *aux = NULL;
  aux = NULL; */
}


void Mundo::ampliar_vertical(const unsigned kZonaAmpliar, const unsigned kNumPorLado, MatrizCeldas& aux) {
/*   size_.filas_ += kNumPorLado;
  aux = new Celda**[size_.filas_]; 
  for (unsigned i = 0, i_tab = 0; i < (unsigned)(size_.filas_); i++, i_tab++) {
    aux[i] = new Celda*[size_.columnas_]; 
    for (unsigned j = 0, j_tab = 0; j < (unsigned)(size_.columnas_); j++, j_tab++) {
      if (kZonaAmpliar == abajo) {
        if (i < size_.filas_ - kNumPorLado) {  // copiarla entera hasta llegar a lo nuevo
          aux[i][j] = new Celda(i,j, tablero_[i_tab][j_tab]->get_color());
        } else {
          aux[i][j] = new Celda(i,j,rand() % NUM_COLOR * random_);
          j_tab--;
        }
      } else if (kZonaAmpliar == arriba) {
        if (i >= kNumPorLado) {  // copiar despues de lo nuevo
          aux[i][j] = new Celda(i,j, tablero_[i_tab][j_tab]->get_color());
        } else {
          aux[i][j] = new Celda(i,j,rand() % NUM_COLOR * random_);
          j_tab = -1;
          i_tab = -1;
        }
      }
    }
  } */
}


void Mundo::ampliar_horizontal(const unsigned kZonaAmpliar, const unsigned kNumPorLado, MatrizCeldas& aux) {
 /*  size_.columnas_ += kNumPorLado;
  aux = new Celda**[size_.filas_]; 
  for (unsigned i = 0; i < (unsigned)(size_.filas_); i++) {
    aux[i] = new Celda*[size_.columnas_]; 
    for (unsigned j = 0, j_tab = 0; j < (unsigned)(size_.columnas_); j++, j_tab++) {
      if (kZonaAmpliar == derecha) {
        if (j < size_.columnas_ - kNumPorLado) {  // copiarla entera hasta llegar a lo nuevo
          aux[i][j] = new Celda(i,j, tablero_[i][j_tab]->get_color());
        } else {
          aux[i][j] = new Celda(i,j,rand() % NUM_COLOR * random_);
          j_tab = -1;
        }
      } else if (kZonaAmpliar == izquierda) {
        if (j >= kNumPorLado) {  // copiar despues de lo nuevo
          aux[i][j] = new Celda(i,j, tablero_[i][j_tab]->get_color());
        } else {
          aux[i][j] = new Celda(i,j,rand() % NUM_COLOR * random_);
          j_tab = -1;
        }
      }
    }
  } */
}


void Mundo::movimiento_peligroso(Hormiga* hormiga_actual) {
  Posicion posicion;
  int flag = -1;
  posicion = hormiga_actual->get_posicion_actual();
  if (posicion.get_x() == size_.Xmin && hormiga_actual->get_direccion() == arriba) {
    flag = arriba;
  } else if (posicion.get_x() == size_.Xmax - 1 && hormiga_actual->get_direccion() == abajo) {
    flag = abajo;
  } else if (posicion.get_y() == size_.Ymin && hormiga_actual->get_direccion() == izquierda) {
    flag = izquierda;
  } else if (posicion.get_y() == size_.Ymax - 1 && hormiga_actual->get_direccion() == derecha) {
    flag = derecha;
  }
  if (flag != -1) {
    resize(5, flag);
  }
}


void Mundo::eliminar_espacio(MatrizCeldas some_world, const int& kFilas, const int& kColumnas) {
/*   for (int i = size_.Xmin; i < kFilas; i++) {
    for (int j = size_.Ymin; j < kColumnas; j++) {
      delete some_world[i][j];
    } 
    delete[] some_world[i]; 
  }
  delete[] some_world;  */
}


std::ostream& operator<<(std::ostream& os, const Mundo& kTablero) {
  Posicion hormiga_posicion;
  for (int i = kTablero.get_size().Xmin; i < kTablero.get_size().Xmax; i++) {
    for (int j = kTablero.get_size().Ymin; j < kTablero.get_size().Ymax; j++) {
      hormiga_posicion.set_x(i);
      hormiga_posicion.set_y(j);
      for (unsigned k = 0; k < HORMIGA_SIZE; k++) { // No dibujes dos veces
        if (hormiga_posicion == kTablero.get_hormiga()[k]->get_posicion_actual()) {
          os << *(kTablero.get_hormiga()[k]);
          break;
        } else if (k == HORMIGA_SIZE - 1) {
          os << kTablero.get_tablero()[i][j]; 
        }
      }
    }
    os << "\n";
  }
  return os;
}