#include <iostream>

#include "../include/posicion.h"
#include "../include/celda.h"

Celda::Celda(unsigned i, unsigned j, unsigned color): color_(color) {
  posicion_.x = i;
  posicion_.y = j;
}

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
    return os << "O";
  } else if (kCelda.get_color() == 1) {
    return os << "X";
  } else return os;
}