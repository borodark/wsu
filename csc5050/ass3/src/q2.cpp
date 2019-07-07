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
  Fraction b = Fraction{1,2};
  assert(a.equals(b));
  cout << a.add(b).print() << endl;
  Fraction c = Fraction{1,4};
  assert(!a.equals(c) && !b.equals(c));
  cout << b.add(c).print() << endl;
  assert((Fraction{1,2}).add(Fraction{1,4}).equals(Fraction{3,4}));
  Fraction d = Fraction{2,4};
  Fraction d1 = Fraction{2,3};
  cout << d.subtract(d1).print() << endl;

  Fraction e = Fraction{3,9};
  Fraction g = Fraction{64,32};
  Fraction h = Fraction{12,15};
  cout << g.add(h).print() << endl;

  Fraction k1 = Fraction{8,31};
  Fraction k = Fraction{2,3};
  cout << k.subtract(k1).print() << endl;

  Fraction l = Fraction{1,3};
  Fraction l1 = Fraction{3,4};
  cout << l.multiply(l1).print() << endl;

  Fraction m = Fraction{1,3};
  Fraction m1 = Fraction{3,4};
  cout << m.divide(m1).print() << endl;


  Fraction n = Fraction{23,3};
  Fraction n1 = Fraction{5,4};
  cout << n.divide(n1).print() << endl;

  /// chain

  cout << d1.divide(h).add(k1).subtract(l1).multiply(n1).print() << endl;


  Fraction invalid = Fraction{1,0};

  return 0;
}

