#include <iostream> 
#include <cstdlib>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/reglas.h"
#include "../include/celda.h"
#include "../include/hormiga.h"
#include "../include/vector.h"
#include "../include/mundo.h"
#include "../include/hormiga_inverso.h"

HormigaInverso::HormigaInverso(Mundo& mundo, int semilla) : Hormiga(mundo, semilla) {}

HormigaInverso::HormigaInverso(Mundo& mundo, int i, int j) : Hormiga(mundo,i,j) {}

HormigaInverso::HormigaInverso(Mundo& mundo) : Hormiga(mundo) {}

void HormigaInverso::cerebro(void) {
  Regla regla;
/*   if (regla.regla1(this)) {
    return;
  } else */ if (regla.regla4(this)) {
    return;
  } else if (regla.regla5(this)) {
    return;
  }
}