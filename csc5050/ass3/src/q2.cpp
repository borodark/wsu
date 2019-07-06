/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver/test for Question 2 of Assignment 3
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass3/src/q2.cpp
   The program is compiles and run correctly. Produces the correct results.
   See inline comments
**/

#include <iostream>
#include <cassert>
#include "Fraction.h"

using namespace std;

int main(){
  Fraction a = Fraction{1,2};
  cout << a.add(Fraction{1,2}).print() << endl;
  
  Fraction invalid = Fraction{1,0};

  return 0;
}

