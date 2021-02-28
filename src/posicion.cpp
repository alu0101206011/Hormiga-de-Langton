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

bool Posicion::operator==(const Posicion& kOtherPosition) {
  return ((x_ == kOtherPosition.get_x()) && 
           y_ == kOtherPosition.get_y());
}

Posicion Posicion::operator+(const Posicion& kOtherPosition) {
  Posicion result;
  result.set_x(kOtherPosition.get_x() + x_);
  result.set_y(kOtherPosition.get_y() + y_);
  return result;
}