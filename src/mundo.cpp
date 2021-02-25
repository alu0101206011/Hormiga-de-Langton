#include <iostream> 
#include <cassert>

#include "../include/posicion.h"
#include "../include/celda.h"
#include "../include/reglas.h"
#include "../include/hormiga.h"
#include "../include/mundo.h"

std::ostream& operator<<(std::ostream& os, const Mundo& kTablero) {
  for (unsigned i = 0; i < kTablero.get_size().filas_; i++) {
    for (unsigned j = 0; j < kTablero.get_size().columnas_; j++) {
      os << kTablero(i,j);
    }
    os << "\n";
  }
  return os;
}

// Constructor
Mundo::Mundo(unsigned m, unsigned n) { 
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
}

Mundo::~Mundo() {
  for (unsigned i = 0; i < size_.filas_; i++) {
    for (unsigned j = 0; j < size_.columnas_; j++) {
      delete tablero_[i][j];
    } 
    delete tablero_[i];  
  }
  delete tablero_; 
}


Celda& Mundo::operator()(const unsigned int i, const unsigned int j) const {
  assert(i < size_.filas_ && j < size_.columnas_);
  return *tablero_[i][j];
}

void Mundo::inicio(void) {
  tablero_[0][0]->set_color(1);
  //resize(2);
  std::cout << *this;
}

Celda*** Mundo::get_tablero(void) const {
  return tablero_;
}

BoardSize Mundo::get_size() const {
  return size_;
}

void Mundo::set_tablero(Celda*** const& kNuevoTablero) {
  tablero_ = kNuevoTablero;
}


void Mundo::resize(const unsigned kNumPorLado) {
/*   filas_ += kNumPorLado * 2;
  columnas_ += kNumPorLado * 2;
  Celda*** aux = new Celda**[filas_];
  for (unsigned i = kNumPorLado - 1, i_tab = 0; i < filas_, i_tab < filas_ - (kNumPorLado * 2); i++, i_tab++) {
    aux[i] = new Celda*[columnas_];
    std::cout << "hola\n";
    for (unsigned j = kNumPorLado - 1, j_tab = 0; j < columnas_, j_tab < columnas_ - (kNumPorLado * 2); j++, j_tab++) {
      std::cout << "hola2\n";
      std::cout << "i = " << i << "\t j = " << j << "\n";
      std::cout << "i_tab = " << i_tab << "\t j_tab = " << j_tab << "\n";
      aux[i][j] = tablero_[i_tab][j_tab];
    }
  }
  eliminar_espacio(tablero_);
  tablero_ = aux;
  eliminar_espacio(aux); */
}


void Mundo::eliminar_espacio(Celda*** const& matriz) {
  for (unsigned i = 0; i < size_.filas_; i++) {
/*     for (unsigned j = 0; j < columnas_; j++) {
      delete tablero_[i][j];
    }  */
    delete matriz[i];  
  }
  delete[] matriz;  
} 


bool Mundo::detectar_borde(const unsigned& i, const unsigned& j) {
  if (i == 0 || j == 0 || i == size_.filas_ || j == size_.columnas_)
    return true;
  return false;
}
