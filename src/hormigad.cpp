#include <iostream> 
#include <cstdlib>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/reglas.h"
#include "../include/celda.h"
#include "../include/hormiga.h"
#include "../include/vector.h"
#include "../include/mundo.h"
#include "../include/hormigad.h"

HormigaD::HormigaD(Mundo& mundo, int semilla) : Hormiga(mundo, semilla) {}

HormigaD::HormigaD(Mundo& mundo, int i, int j) : Hormiga(mundo,i,j) {}

HormigaD::HormigaD(Mundo& mundo) : Hormiga(mundo) {}

void HormigaD::cerebro(void) {
  Regla regla;
  regla.regla7(this);
}