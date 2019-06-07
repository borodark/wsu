/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a Class defenition for Complex type used in answering Question 4 of Assignment 2
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass2/include/Complex.h
   The program is compiles and run correctly. Produces the correct results.
**/
#include <string>
#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class Complex{

 public:
  /*
    Constructor with 0 as defaults for real in imaginary
   */
  explicit Complex( int const real = 0, int const imaginary = 0);
  int getR() const;
  //  void setR(const int ); // IMHO this has to be immutable
  int getI() const;
  // void setI(const int imaginary);  // IMHO this has to be immutable
  string print() const;
  /* Behaviour declaration */
  const Complex add(const Complex toAdd);
  const Complex subtract(const Complex toSubtrack);
  /* privite data declaration */
 private:
  int r;
  int i;
};

#endif
