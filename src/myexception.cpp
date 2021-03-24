#include <iostream>
#include <exception>

#include "../include/myexception.h"

MyException::MyException() {}

const char* MyException::what() const noexcept {
  return "";
}
