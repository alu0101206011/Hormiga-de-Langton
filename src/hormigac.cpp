#include <iostream> 
#include <cstdlib>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/reglas.h"
#include "../include/celda.h"
#include "../include/hormiga.h"
#include "../include/vector.h"
#include "../include/mundo.h"
#include "../include/hormigac.h"

HormigaC::HormigaC(Mundo& mundo, int semilla) : Hormiga(mundo, semilla) {}

HormigaC::HormigaC(Mundo& mundo, int i, int j) : Hormiga(mundo,i,j) {}

HormigaC::HormigaC(Mundo& mundo) : Hormiga(mundo) {}

void HormigaC::cerebro(void) {
  Regla regla;
  regla.regla6(this);
}