#include <string>
#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class Complex{

 public:
  explicit Complex( int const real, int const imaginary );
  int getR() const;
  void setR(const int );
  int getI() const;
  void setI(const int imaginary);
  ostream& print(const ostream& os);

 private:
  int r;
  int i;

};

#endif
