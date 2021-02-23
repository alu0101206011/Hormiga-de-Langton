/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Algoritmos y Estructuras de Datos avanzadas
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 21 Jan 2021
/// @brief Programa que simule el comportamiento de la hormiga 
/// de Langton durante un número indefinido de pasos de tiempo
///
/// @see https://es.wikipedia.org/wiki/Hormiga_de_Langton
///
/// To compile: make
/// To clean files: make clean

#include <iostream>
#include <vector>

#include "celda.h"
#include "mundo.h"
#include "hormiga.h"

void Usage(int argc, char *argv[]);

/// Main function
/// @param[in] argc Number of command line parameters
/// @param[in] argv Vector containing (char*) the parameters
int main(int argc, char *argv[]) {
  Usage(argc, argv);

  Celda hola(0,0,0);
  Mundo tablero(1,1);
  std::cout << hola;
  std::cout << tablero;
  return 0;
}

/// @brief Funtion that show the usage of this program
/// @param[in] argc Number of command line parameters
/// @param[in] argv Vector containing (char*) the parameters
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