/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver/test for Question 3 of Assignment 3
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass3/src/q3.cpp
   The program is compiles and run correctly. Produces the correct results.
   See inline comments
**/

#include <iostream>
#include <cassert>
#include "ArrayBag.h"


using namespace std;

void q3(){
  ArrayBag<int> arrayBag;
  arrayBag.add(1);
  arrayBag.add(3);
  arrayBag.add(7);
  arrayBag.add(9);
  arrayBag.add(12);
  arrayBag.add(15);
  cout << "The arraybag has " << arrayBag.getCurrentSize() << " items" << endl;
  bool rc = arrayBag.replace(9, 10);
  cout << "Does the arraybag has item with value 9?  " << arrayBag.contains(9) << endl;
  cout << "Does the arraybag has item with value 10?  " << arrayBag.contains(10) << endl;
  rc = arrayBag.replace(9, 10);
  cout << "Was the attemt to replace 9 with 10 again was succesful? " << rc << endl;

}

int main(){
  q3();
  return 0;
}
