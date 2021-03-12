#include <iostream>

#include "../include/posicion.h"
#include "../include/celda.h"



Celda::Celda(void) : posicion_(0, 0), color_(0) {}
   

Celda::Celda(int i, int j, unsigned color)
    : posicion_(i,j), color_(color) {}

Posicion Celda::get_posicion() const {
  return posicion_;
}

unsigned Celda::get_color() const {
  return color_;
}

void Celda::set_color(const unsigned& kNuevoColor) {
  color_ = kNuevoColor;
}


std::ostream& operator<<(std::ostream& os, const Celda& kCelda) {
  if (kCelda.get_color() == Blanco) {
    return os << "⬜";
  } else if (kCelda.get_color() == Negro) {
    return os << "🔳";
  } else {
    return os << "E "; 
  }
}