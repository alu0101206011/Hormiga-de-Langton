#include <iostream>

#include "../include/posicion.h"
#include "../include/celda.h"
#include "../include/vector.h"

template <class T> 
Vector<T>::Vector(void): lower_(0), upper_(0) { 
  a_ = NULL; 
}

template <class T> 
Vector<T>::Vector(int m, int n): lower_(m), upper_(n) { 
  a_ = new T[n - m]; 
}

template <class T> 
Vector<T>::~Vector() { 
  delete[] a_;
}

template <class T> 
int Vector<T>::get_lower(void) const {
  return lower_;
}
template <class T> 
int Vector<T>::get_upper(void) const {
  return upper_;
}

template <class T> 
void Vector<T>::set_lower(const int& kNewLower) {
  lower_ = kNewLower;
}

template <class T> 
void Vector<T>::set_upper(const int& kNewUpper) {
  upper_ = kNewUpper;
}

template <class T> 
void Vector<T>::new_size(const int& kNewLower, const int& kNewUpper) {
  lower_ = kNewLower;
  upper_ = kNewUpper;
  a_ = new T[upper_ - lower_]; 
}

template <class T> 
T& Vector<T>::operator[](const int& i) { 
  if (i < lower_ || i >= upper_) {
    std::cout << "Outside array bounds";
    exit(1);
  } else {
      std::cout << "i: " << i << " resta: " << i-lower_ << "\n";
      return a_[i-lower_];
  }
}

template<class T>
T Vector<T>::operator[](const int& i) const {
  if (i < lower_ || i >= upper_) {
    std::cout << "Outside array bounds";
    exit(1);
  } else {
      return a_[i-lower_];
  }
}

template class Vector<Celda>;
template class Vector<Vector<Celda>>;