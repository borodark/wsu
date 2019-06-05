#include <string>
#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class Complex{

 public:
  explicit Complex( int const real = 0, int const imaginary = 0);
  int getR() const;
  void setR(const int );
  int getI() const;
  void setI(const int imaginary);
  string print() const;
  const Complex add(const Complex toAdd);
  const Complex subtract(const Complex toSubtrack);
 private:
  int r;
  int i;

};

#endif
