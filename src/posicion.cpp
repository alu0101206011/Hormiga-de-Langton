#include <iostream>

#include "../include/posicion.h"

Posicion::Posicion(): x_(-1), y_(-1) {}

Posicion::Posicion(int x, int y): x_(x), y_(y) {}
  
int Posicion::get_x(void) const { 
  return x_; 
}
int Posicion::get_y(void) const { 
  return y_; 
}

void Posicion::set_x(const int& kNewX) {
  x_ = kNewX;
}
void Posicion::set_y(const int& kNewY) {
  y_ = kNewY;
}