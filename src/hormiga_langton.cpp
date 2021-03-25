#include <iostream> 
#include <cstdlib>

#include "../include/posicion.h"
#include "../include/movimiento.h"
#include "../include/reglas.h"
#include "../include/celda.h"
#include "../include/hormiga.h"
#include "../include/vector.h"
#include "../include/mundo.h"
#include "../include/hormiga_langton.h"

HormigaLangton::HormigaLangton(Mundo& mundo, int semilla) : Hormiga(mundo, semilla) {}

HormigaLangton::HormigaLangton(Mundo& mundo, int i, int j) : Hormiga(mundo,i,j) {}

HormigaLangton::HormigaLangton(Mundo& mundo) : Hormiga(mundo) {}

void HormigaLangton::cerebro(void) {
  Regla regla;
  if (regla.regla2(this)) {
    return;
  } else if (regla.regla3(this)) {
    return;
  }
}