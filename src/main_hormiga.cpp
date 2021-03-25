/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Algoritmos y Estructuras de Datos avanzadas
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 26 Jan 2021
/// @brief Programa que simule el comportamiento de la hormiga 
/// de Langton durante un número indefinido de pasos de tiempo
///
/// @see https://es.wikipedia.org/wiki/Hormiga_de_Langton
///
/// To compile: make
/// To clean files: make clean
/// g++ -g -Wall --std=c++17 -o ./bin/hormiga src/vector.cpp src/posicion.cpp src/movimiento.cpp src/celda.cpp src/reglas.cpp src/hormiga.cpp src/mundo.cpp src/mundofinito.cpp src/mundoinfinito.cpp src/universo.cpp src/main_functions.cpp src/main_hormiga.cpp

#include <iostream>
#include <list>
#include <ctime>

#include "../include/vector.h"
#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/celda.h"
#include "../include/reglas.h"
#include "../include/hormiga.h"
#include "../include/mundo.h"
#include "../include/mundofinito.h"
#include "../include/mundoinfinito.h"
#include "../include/hormiga_langton.h"
#include "../include/hormiga_inverso.h"
#include "../include/hormigac.h"
#include "../include/hormigad.h"
#include "../include/universo.h"
#include "../include/main_functions.h"

int main(int argc, char *argv[]) {
  Usage(argc, argv);
  cabecera();
  Mundo* mundo;
  std::list<Hormiga*> hormigas;
  if (todo_default(mundo, hormigas)) {
    Universo universe(mundo, hormigas, hormigas.size());
    universe.start_simulation(40, medio);
    return 0;
  }
  mundo = crear_mundo();
  int num_hormigas = 0;
  hormigas = eleccion_hormigas(mundo, num_hormigas);
  Universo universe(mundo, hormigas, num_hormigas);
  unsigned nturnos = turnos();
  Velocidad velocidad = velocidad_preferida();
  universe.start_simulation(nturnos, velocidad);
  return 0;
}


