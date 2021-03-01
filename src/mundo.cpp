#include <iostream> 
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/celda.h"
#include "../include/reglas.h"
#include "../include/hormiga.h"
#include "../include/mundo.h"

const unsigned NUM_COLOR = 2;
const unsigned HORMIGA_SIZE = 1;

// Constructor
Mundo::Mundo(unsigned m, unsigned n): random_(false) { 
  assert(m>1 && n>1);
  size_.filas_ = m;
  size_.columnas_ = n;

  tablero_ = new Celda**[size_.filas_];
  for (unsigned i = 0; i < size_.filas_; i++) {
    tablero_[i] = new Celda*[size_.columnas_];
    for (unsigned j = 0; j < size_.columnas_; j++) {
      tablero_[i][j] = new Celda(i,j,0);
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
  size_.filas_ = 20;
  size_.columnas_ = 20;
  tablero_ = new Celda**[size_.filas_];
  for (unsigned i = 0; i < size_.filas_; i++) {
    tablero_[i] = new Celda*[size_.columnas_];
    for (unsigned j = 0; j < size_.columnas_; j++) {
      tablero_[i][j] = new Celda(i,j,0);
    }
  }
  hormiga_ = new Hormiga*[HORMIGA_SIZE];
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    hormiga_[i] = new Hormiga(*this);
  }
}

Mundo::Mundo(int random): random_(true) {
  std::srand(random);
  size_.filas_ = std::rand() % 10 + 2;
  size_.columnas_ = std::rand() % 10 + 2;


  tablero_ = new Celda**[size_.filas_];
  for (unsigned i = 0; i < size_.filas_; i++) {
    tablero_[i] = new Celda*[size_.columnas_];
    for (unsigned j = 0; j < size_.columnas_; j++) {
      tablero_[i][j] = new Celda(i,j,rand() % NUM_COLOR);
    }
  }
  hormiga_ = new Hormiga*[HORMIGA_SIZE];
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    hormiga_[i] = new Hormiga(*this, random);
  }
}

Mundo::~Mundo() {
  for (unsigned i = 0; i < size_.filas_; i++) {
    for (unsigned j = 0; j < size_.columnas_; j++) {
      delete tablero_[i][j];
    } 
    delete[] tablero_[i]; 
  }
  delete[] tablero_;
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    delete hormiga_[i];
  }
  delete[] hormiga_;
}


Celda*** Mundo::get_tablero(void) const {
  return tablero_;
}
BoardSize Mundo::get_size(void) const {
  return size_;
}
Hormiga** Mundo::get_hormiga(void) const {
  return hormiga_;
}
unsigned Mundo::get_color(const Posicion& kPosicion) const {
  return tablero_[kPosicion.get_x()][kPosicion.get_y()]->get_color();
}

void Mundo::set_tablero(Celda*** const& kNuevoTablero) {
  tablero_ = kNuevoTablero;
}


void Mundo::inicio(void) {
  for (int i = 0; i < 11500; i++) {
    system("clear");
    std::cout << *this << "\n";
    for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
      hormiga_[i]->cerebro();
    }
    usleep(1000);
  }
  std::cout << *this << "\n";
}


void Mundo::resize(const unsigned kNumPorLado, const int kZonaAmpliar) {
  Celda*** aux;
  unsigned fila_original = size_.filas_;
  unsigned columna_original = size_.columnas_;
//  QUE DECIDA QUE ZONA AMPLIAR Y QUE LLAME A ESAS COSAS
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
  //delete aux;
}

void Mundo::ampliar_vertical(const unsigned kZonaAmpliar, const unsigned kNumPorLado, Celda***& aux) {
  size_.filas_ += kNumPorLado;
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
  }
}

/*
  aux nuevo espacio filas(3+5) = 8
  for (i recorro 3+5)
    nuevo espacio comumnas(3)
    for (j recorro 3)
    if (arriba)
      if (i < tam_original)
        aux = tablero;
      else aux (nuevo)
    else if (abajo)
      if (i >= tam_original) 
        aux = tablero;
      else aux (nuevo)

*/
void Mundo::ampliar_horizontal(const unsigned kZonaAmpliar, const unsigned kNumPorLado, Celda***& aux) {
  size_.columnas_ += kNumPorLado;
  aux = new Celda**[size_.filas_]; 
  for (unsigned i = 0; i < (unsigned)(size_.filas_); i++) {
    aux[i] = new Celda*[size_.columnas_]; 
    for (unsigned j = 0, j_tab = 0; j < (unsigned)(size_.columnas_); j++, j_tab++) {
      if (kZonaAmpliar == derecha) {
        if (j < size_.columnas_ - kNumPorLado) {  // copiarla entera hasta llegar a lo nuevo
          aux[i][j] = new Celda(i,j, tablero_[i][j_tab]->get_color());
          //if (j_tab == size_.columnas_ - kNumPorLado - 1) i_tab++;
        } else {
          aux[i][j] = new Celda(i,j,rand() % NUM_COLOR * random_);
          j_tab = -1;
        }
      } else if (kZonaAmpliar == izquierda) {
        if (j >= kNumPorLado) {  // copiar despues de lo nuevo
          aux[i][j] = new Celda(i,j, tablero_[i][j_tab]->get_color());
          //if (j_tab == size_.columnas_ - kNumPorLado - 1) i_tab++;
        } else {
          aux[i][j] = new Celda(i,j,rand() % NUM_COLOR * random_);
          j_tab = -1;
        }
      }
    }
  }
}


void Mundo::movimiento_peligroso(Hormiga* hormiga_actual) {
  Posicion posicion;
  int flag = -1;
  posicion = hormiga_actual->get_posicion_actual();
  if (posicion.get_x() == 0 && hormiga_actual->get_direccion() == arriba) {
    flag = arriba;
  } else if (posicion.get_x() == (int)size_.filas_ - 1 && hormiga_actual->get_direccion() == abajo) {
    flag = abajo;
  } else if (posicion.get_y() == 0 && hormiga_actual->get_direccion() == izquierda) {
    flag = izquierda;
  } else if (posicion.get_y() == (int)size_.columnas_ - 1 && hormiga_actual->get_direccion() == derecha) {
    flag = derecha;
  }
  if (flag != -1) {
    resize(1, flag);
  }
}

void Mundo::eliminar_espacio(Celda*** some_world, const unsigned& kFilas, const unsigned& kColumnas) {
  for (unsigned i = 0; i < kFilas; i++) {
    for (unsigned j = 0; j < kColumnas; j++) {
      delete some_world[i][j];
    } 
    delete[] some_world[i]; 
  }
  delete[] some_world; 
}


std::ostream& operator<<(std::ostream& os, const Mundo& kTablero) {
  Posicion hormiga_posicion;
  for (unsigned i = 0; i < kTablero.get_size().filas_; i++) {
    for (unsigned j = 0; j < kTablero.get_size().columnas_; j++) {
      hormiga_posicion.set_x(i);
      hormiga_posicion.set_y(j);
      for (unsigned k = 0; k < HORMIGA_SIZE; k++) { // No dibujes dos veces
        if (hormiga_posicion == kTablero.get_hormiga()[k]->get_posicion_actual()) {
          os << *(kTablero.get_hormiga()[k]);
          break;
        } else if (k == HORMIGA_SIZE - 1) {
          os << *(kTablero.get_tablero()[i][j]); 
        }
      }
    }
    os << "\n";
  }
  return os;
}