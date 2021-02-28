#include <iostream>

#include "../include/posicion.h"
#include "../include/celda.h"

Celda::Celda(unsigned i, unsigned j, unsigned color)
    : posicion_(i,j), color_(color) {}

Posicion Celda::get_posicion() const {
  return posicion_;
}

unsigned Celda::get_color() const{
  return color_;
}

void Celda::set_color(const unsigned& kNuevoColor) {
  color_ = kNuevoColor;
}


std::ostream& operator<<(std::ostream& os, const Celda& kCelda) {
  if (kCelda.get_color() == 0) {
    return os << "⬜";
  } else if (kCelda.get_color() == 1) {
    return os << "🔳";
  } else return os;
}