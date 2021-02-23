#include <iostream>

#include "celda.h"

std::ostream& operator<<(std::ostream& os, const Celda& kCelda) {
  if (kCelda.get_estado() == 0) {
    return os << " ";
  } else if (kCelda.get_estado() == 1) {
    return os << "X";
  }
}