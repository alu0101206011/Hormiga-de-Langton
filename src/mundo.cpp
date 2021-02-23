#include <iostream> 
#include <vector>

#include "celda.h"
#include "mundo.h"

// Constructor
Mundo::Mundo(int filas, int columnas) {
  tablero_ = new Celda**[filas];
  for (unsigned i = 0; i < filas; i++) {
    tablero_[i] = new Celda*[columnas];
    for (unsigned j = 0; j < columnas; j++) {
      tablero_[i][j] = new Celda(i,j,0);
    }
  }
}

Celda*** Mundo::get_tablero() const {
  return tablero_;
}

unsigned Mundo::get_filas(void) const {
  return filas_;
}

unsigned Mundo::get_columnas(void) const {
  return columnas_;
}

void Mundo::set_tablero(const Celda***& kNuevoTablero) {
  tablero_ = kNuevoTablero;
}

std::ostream& operator<<(std::ostream& os, const Mundo& kTablero) {
  for (unsigned i = 0; i < kTablero.get_tablero(); i++) {
    for (unsigned j = 0; j < kTablero.get_tablero()[i].size(); j++) {
      os << kTablero.get_tablero()[i][j];
    }
    os << "\n";
  }
  return os;
}