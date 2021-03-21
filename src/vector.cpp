#include <iostream>
#include <exception>

#include "../include/posicion.h"
#include "../include/celda.h"
#include "../include/vector.h"
#include "../include/exceptions_hormiga.h"

template <class T> 
void Vector<T>::remove(void) {
  if (a_ != 0)
    delete[] a_;
  a_ = 0;
  upper_ = 0;
  lower_ = 0;
}

template <class T> 
void Vector<T>::build(void) {
  if (upper_ - lower_ > 0) {
    a_ = new T[upper_ - lower_];
  } else if (upper_ - lower_ == 0) {
    a_ = 0;
  } 
}

template <class T> 
Vector<T>::Vector(void): lower_(0), upper_(0) { 
  build();
}

template <class T> 
Vector<T>::Vector(int m, int n): lower_(m), upper_(n) { 
  build();
}

template <class T> 
Vector<T>::Vector(const Vector<T>& kNewVector) {
  lower_ = kNewVector.get_lower();
  upper_ = kNewVector.get_upper();
  build();
  for (int i = lower_; i < upper_; i++) {
    (*this)[i] = kNewVector[i];
  }
}

template <class T> 
Vector<T>::~Vector() { 
  remove();
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
  build();
}


template <class T> 
Vector<T>& Vector<T>::operator=(const Vector<T>& kNewVector) {
  remove();
  lower_ = kNewVector.get_lower();
  upper_ = kNewVector.get_upper();
  build();
  for (int i = lower_; i < upper_; i++) {
    (*this)[i] = kNewVector[i];
  }
  return *this;
}

template <class T> 
T& Vector<T>::operator[](const int& i) { 
  if (i < lower_ || i >= upper_) {
    throw 3;
  } else {
      return a_[i-lower_];
  }
}

template<class T>
T Vector<T>::operator[](const int& i) const {
  if (i < lower_ || i >= upper_) {
    throw 3;
  } else {
      return a_[i-lower_];
  }
}

template class Vector<Celda>;
template class Vector<Vector<Celda>>;