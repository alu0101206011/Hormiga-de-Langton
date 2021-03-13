#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/celda.h"
#include "../include/reglas.h"
#include "../include/hormiga.h"
#include "../include/vector.h"
#include "../include/mundo.h"
#include "../include/universo.h"


void Universo::build_hormiga(void) {
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    Hormiga hormiga(*mundo_);
    hormiga_list_.push_back(hormiga); 
  } 
}

void Universo::build_hormiga(int seed) {
  srand(seed);
  for (unsigned i = 0; i < HORMIGA_SIZE; i++) {
    Hormiga hormiga(*mundo_, rand());
    hormiga_list_.push_back(hormiga);
  }
}


void Universo::ordenar_lista(void) {
  hormiga_list_.sort();
}


void Universo::next_hormiga_pos(void) {
  if (HORMIGA_SIZE != 1) {
    unsigned count = 0;
    do {
      count++;
      const Hormiga hormiga_head = hormiga_list_.front();
      hormiga_list_.pop_front();
      hormiga_list_.push_back(hormiga_head);
    } while (hormiga_list_.front().get_posicion_actual() == hormiga_list_.back().get_posicion_actual() && count != HORMIGA_SIZE);
  }
}

Universo::Universo(Mundo* mundo, std::list<Hormiga> hormiga_list, unsigned num_hormigas)
     : mundo_(mundo), hormiga_list_(hormiga_list), HORMIGA_SIZE(num_hormigas) {
  if (hormiga_list_.empty())
    build_hormiga();
}

Universo::Universo(Mundo* mundo,  std::list<Hormiga> hormiga_list, int seed, unsigned num_hormigas) 
     : mundo_(mundo), hormiga_list_(hormiga_list), HORMIGA_SIZE(num_hormigas) {
  if (hormiga_list_.empty())
    build_hormiga(seed);
}

Mundo* Universo::get_mundo(void) const {
  return mundo_;
}

std::list<Hormiga> Universo::get_hormiga(void) const {
  return hormiga_list_;
}

void Universo::start_simulation(int iter, Velocidad velocidad) {
  ordenar_lista();
  std::cout << *this << "\n";
  int simulation_speed = velocidad_simulacion(velocidad);
  for (int i = 0; i < iter; i++) {
    usleep(simulation_speed);
    system("clear");
    for (Hormiga& hormiga : hormiga_list_) {
      hormiga.cerebro();
    }
    ordenar_lista();
    std::cout << *this << "\n";
  } 
}

unsigned Universo::velocidad_simulacion(Velocidad velocidad) {
  switch (velocidad) {
  case lento: return 1000000;
  case medio: return 500000;
  case rapido: return 100000;
  default: return 500000;
  }
}

std::ostream& operator<<(std::ostream& os, Universo& universe) {
  Posicion hormiga_posicion;
  for (int i = universe.get_mundo()->get_size().Xmin; i < universe.get_mundo()->get_size().Xmax; i++) {
    for (int j = universe.get_mundo()->get_size().Ymin; j < universe.get_mundo()->get_size().Ymax; j++) {
      hormiga_posicion.set_x(i);
      hormiga_posicion.set_y(j);      // solo mirar la primera posición de lista
      if (hormiga_posicion == universe.get_hormiga().front().get_posicion_actual()) {
        os << universe.get_hormiga().front();
        universe.next_hormiga_pos();
      } else {
        os << universe.get_mundo()->get_tablero()[i][j]; 
      }
    }
    os << "\n";
  }
  return os; 
}