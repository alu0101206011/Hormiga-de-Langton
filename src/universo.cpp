#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/celda.h"
#include "../include/reglas.h"
#include "../include/hormiga.h"
#include "../include/vector.h"
#include "../include/mundo.h"
#include "../include/universo.h"

/* void Universo::build_mundo(void) {
  mundo_ = new Mundo();
}

void Universo::build_mundo(int m, int n) {
  mundo_ = new Mundo(m, n);
}

void Universo::build_mundo(int seed) {
  mundo_ = new Mundo(seed);
} */

void Universo::build_hormiga(void) {
  hormiga_ = new Hormiga*[HORMIGA_SIZE];
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    hormiga_[i] = new Hormiga(*mundo_);
  } 
}

void Universo::build_hormiga(int m, int n) {
  hormiga_ = new Hormiga*[HORMIGA_SIZE];
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    hormiga_[i] = new Hormiga(*mundo_, m, n);
  } 
}

void Universo::build_hormiga(int seed) {
  hormiga_ = new Hormiga*[HORMIGA_SIZE];
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    hormiga_[i] = new Hormiga(*mundo_, seed);
  }
}

Universo::Universo(Mundo* mundo): mundo_(mundo) {
  build_hormiga();
}

Universo::Universo(unsigned m, unsigned n) {
  //build_mundo(m, n);
  build_hormiga();
}

Universo::Universo(int seed) {
  //build_mundo(seed);
  build_hormiga(seed);
}

Mundo* Universo::get_mundo(void) const{
  return mundo_;
}

Hormiga** Universo::get_hormiga(void) const {
  return hormiga_;
}

void Universo::start_simulation(int iter) {
  std::cout << *this << "\n";
  for (int i = 0; i < iter; i++) {
    //system("clear");
    for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
      hormiga_[i]->cerebro();
    }
    std::cout << *this << "\n";
    usleep(1000000);
  }
  std::cout << *this << "\n";
}

std::ostream& operator<<(std::ostream& os, const Universo& universe){
  Posicion hormiga_posicion;
  for (int i = universe.get_mundo()->get_size().Xmin; i < universe.get_mundo()->get_size().Xmax; i++) {
    for (int j = universe.get_mundo()->get_size().Ymin; j < universe.get_mundo()->get_size().Ymax; j++) {
      hormiga_posicion.set_x(i);
      hormiga_posicion.set_y(j);
      for (unsigned k = 0; k < HORMIGA_SIZE; k++) { 
        if (hormiga_posicion == universe.get_hormiga()[k]->get_posicion_actual()) {
          os << *(universe.get_hormiga()[k]);
          break;
        } else if (k == HORMIGA_SIZE - 1) {
          os << universe.get_mundo()->get_tablero()[i][j]; 
        }
      }
    }
    os << "\n";
  }
  return os;
}