#include <iostream>
#include <list>

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
#include "../include/main_functions.h"


void Usage(int argc, char *argv[]) {
  if (argc == 2)
    if((std::string)argv[1] == "-h" || (std::string)argv[1] == "--help") {
      std::cout << "Uso: " << argv[0] << " [Sin opciones]\n";
      exit(0);
    }
  if (argc != 1) {
    std::cout << "Tiene argumentos inválidos.\nEscriba "
              << "--help para más ayuda\n";
    exit(1);
  } 
}


void cabecera(void) {
  system("clear");
  std::cout << "----------------------------------------"
            << "\n|                                      |\n"
            << "|      Bienvenido a mundo hormiga      |"
            << "\n|                                      |\n"
            << "----------------------------------------\n\n";
}

bool todo_default(Mundo* &mundo) {
  char default_dado = default_tipo(3);
  if (default_dado == 's') {
    const char tipo = tipo_mundo();
    switch (tipo) {
      case 'f': mundo = new MundoFinito(); break;
      case 'i': mundo = new MundoInfinito(); break; 
      default: break;
    }
    return true;
  }
  return false;
}

char tipo_mundo(void) {
  std::cout << "Hay dos tipos de mundos: Mundo [f]inito y mundo [i]nfinito: ";
  char tipo = '\0';
  do {
    std::cin >> tipo;
    if (tipo != 'f' && tipo != 'i') {
      std::cout << "Seleccione 'i' o 'f' si desea un mundo infinito o finito respectivamente.\n";
      tipo = '\0';
    }
  } while (tipo == '\0');
  return tipo;
}

char default_tipo(int tipo) {
  char decision = '\0';
  std::cout << "¿Desea ";
  if (tipo == 1) std::cout << "un mundo";
  else if (tipo == 0) std::cout << "las hormigas";
  else std::cout << "todo";
  std::cout << " por defecto? Seleccione 's' o 'n': "; 
  do {
    std::cin >> decision;
    switch (decision) {
    case 's': break;
    case 'n': break;
    default: std::cout << "Seleccione 's' o 'n' si desea o no por defecto respectivamente.\n";
      decision = '\0'; break;
    }
  } while (decision == '\0');  
  return decision;
}


Mundo* crear_mundo(void) {
  const char tipo = tipo_mundo();
  int m, n;
  Mundo* mundo;
  const char defecto = default_tipo(1);
  if (defecto == 'n') {
    std::cout << "Tamaño del mundo que desea:\n";
    do {
      std::cout << " Filas: ";
      m = control_errores_int();
      std::cout << " Columnas: ";
      n = control_errores_int();
      if (m <= 1 || n <= 1) 
        std::cout << "Introduzca un tamaño de mundo válido.\n\n";
    } while (m <= 1 || n <= 1);
  }
  switch (tipo) {
  case 'f': 
    if (defecto == 's') mundo = new MundoFinito();
    else mundo = new MundoFinito(m,n);
    break;
  case 'i':
    if (defecto == 's') mundo = new MundoInfinito();
    else mundo = new MundoInfinito(m,n);
    break;  
  default: break;
  }
  return mundo;
}


std::list<Hormiga> eleccion_hormigas(Mundo* mundo, int& num_hormigas) {
  num_hormigas = 0;
  std::list<Hormiga> hormiga_list;
  do {
    std::cout << "\n¿Cuántas hormigas desea tener?\n Número de hormigas deseadas: ";
    num_hormigas = control_errores_int();
    if (num_hormigas <= 0 || (unsigned)num_hormigas > mundo->get_size().filas_ * mundo->get_size().columnas_) {
      std::cout << "Número de hormigas no válido.\n";
    }
  } while (num_hormigas <= 0 || (unsigned)num_hormigas > mundo->get_size().filas_ * mundo->get_size().columnas_);
  const char defecto = default_tipo(0);
  if (defecto == 'n') {
    int contador = 0;
    while (num_hormigas > contador) {
      std::cout << "\nPosición hormiga " << contador + 1 << "\n";
      Posicion posicion = posiciones(mundo);
      Hormiga hormiga(*mundo, posicion.get_x(), posicion.get_y());
      hormiga_list.push_back(hormiga);
      contador++;
    }
  }
  return hormiga_list;
}


Posicion posiciones(Mundo* mundo) {
  int i,j;
  do{
    std::cout << "Posición i: ";
    i = control_errores_int();
    std::cout << "Posición j: ";
    j = control_errores_int();
    if (i < mundo->get_size().Xmin || i > mundo->get_size().Xmax - 1 || j < mundo->get_size().Ymin || j > mundo->get_size().Ymax - 1)
      std::cout << '\n' <<"Posición no válida, inténtelo de nuevo. " << '\n';
  } while (i < mundo->get_size().Xmin || i > mundo->get_size().Xmax - 1 || j < mundo->get_size().Ymin || j > mundo->get_size().Ymax - 1);
  Posicion posicion(i,j);
  return posicion;
}

int control_errores_int(void) {
  std::string param;
  std::cin >> param;
  do {
    if (!isdigit(param[0])) {
      if (param[0] == '-' && param.length() > 1) {
        if (isdigit(param[1])) {
          break;
        }
      } else {
        std::cout << "\nSe ha introducido una opción no válida\n";
        std::cout << "Introduzca la opción otra vez: ";
        std::cin >> param;
      }
    }
  } while (!isdigit(param[0]));
  int number = stoi(param);
  return number;
}

unsigned turnos(void) {
  std::cout << "\nNúmero de turnos que quiere: ";
  int turnos = 0;
  do {
    turnos = control_errores_int();
  } while (turnos <= 0);
  return (unsigned)turnos;
}

Velocidad velocidad_preferida(void) {
  std::cout << "\nVelocidad preferida: [1] Lento, [2] Medio, [3] Rápido \n";
  unsigned veloz = 0;
  do {
    veloz = control_errores_int();
  } while (veloz != 1 && veloz != 2 && veloz != 3);
  return (Velocidad)(veloz - 1);
}