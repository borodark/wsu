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
#include "MixedNumber.h"
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
  Fraction n1 = Fraction{66,14};
  cout << n.divide(n1).print() << endl;

  /// chain

  cout << d1.divide(h).add(k1).subtract(l1).multiply(n1).print() << endl;

  MixedNumber mn = MixedNumber{1, n1}; // is 5 and 5/7
  MixedNumber mnf = MixedNumber{n1};

  MixedNumber m5and5by7 = MixedNumber{5, 5, 7};
  assert(mn.equals(m5and5by7));
  cout << "-----------------------" << endl;
  cout << "(5 5/7) + (5 5/7) = ";

  cout << mn.add(m5and5by7).print() << endl;


  MixedNumber m557 = MixedNumber{5, 5, 7};
  assert(m5and5by7.equals(m557));
  cout << "-----------------------" << endl;
  cout << "(5 5/7) - (5 5/7) = ";

  cout << m557.subtract(m5and5by7).print() << endl;

  MixedNumber m457 = MixedNumber{4, 5, 7};
  cout << "-----------------------" << endl;
  cout << "(5 5/7) - (4 5/7) = ";
  m5and5by7.subtract(m457);
  assert(m5and5by7.equals(MixedNumber{1,0,1}));
  cout << m5and5by7.print() << endl;

  cout << "-----------------------" << endl;
  cout << "(4 5/7) - (5 5/7) = (-1 0/1)";
  m457.subtract(MixedNumber{5, 5, 7});
  assert(m457.equals(MixedNumber{-1,0,1}));
  cout << m457.print() << endl;

  cout << "-----------------------" << endl;
  cout << "(1 7/5) - (7/5) = (-1 0/1)";
  assert((MixedNumber{1, 7, 5}).subtract(MixedNumber{2, 7, 5}).equals(MixedNumber{-1,0,1}));

  cout << "-----------------------" << endl;
  cout << "(2 1/5) - (1 3/5) = (0 3/5)";
  assert((MixedNumber{2, 1, 5}).subtract(MixedNumber{1, 3, 5}).equals(MixedNumber{0,3,5}));

  cout << "-----------------------" << endl;
  cout << "(3 2/3) - (2 3/5) = (1 1/15)";
  assert((MixedNumber{3, 2, 3}).subtract(MixedNumber{2, 3, 5}).equals(MixedNumber{1,1,15}));

  Fraction invalid = Fraction{1,0};

  return 0;
}

