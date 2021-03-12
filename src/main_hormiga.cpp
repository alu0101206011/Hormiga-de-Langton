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
/// g++ -g -Wall --std=c++17 -o ./bin/hormiga src/vector.cpp src/posicion.cpp src/movimiento.cpp src/celda.cpp src/reglas.cpp src/hormiga.cpp src/mundo.cpp src/mundofinito.cpp src/mundoinfinito.cpp src/universo.cpp src/main_hormiga.cpp

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
#include "../include/universo.h"

void Usage(int argc, char *argv[]);


int main(int argc, char *argv[]) {
  Usage(argc, argv);
  Mundo *mundo;
  mundo = new MundoInfinito();
  Universo universe(mundo);
  universe.start_simulation(40);
  return 0;
}


void Usage(int argc, char *argv[]) {
  if (argc == 2)
    if((std::string)argv[1] == "-h" || (std::string)argv[1] == "--help") {
      std::cout << "Uso: " << argv[0] << " [Sin opciones]\n";
      exit(0);
    }
  if (argc != 1) {
    std::cout << "Tiene argumentos invalidos.\nEscriba "
              << "--help para más ayuda\n";
    exit(1);
  } 
}