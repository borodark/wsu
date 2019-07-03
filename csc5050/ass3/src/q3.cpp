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
#include <vector>



using namespace std;

template<class Item>
void printVector(vector<Item> const &input)
{
  for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << ' ';
	} //	copy(input.begin(),            input.end(),            ostream_iterator<Item>(cout, ", "));
}


void q3(){
  ArrayBag<int> arrayBag;
  arrayBag.add(1);
  arrayBag.add(7);
  arrayBag.add(9);
  arrayBag.add(12);
  arrayBag.add(15);
  arrayBag.add(19);

  cout << "The arraybag has " << arrayBag.getCurrentSize() << " items" << endl;
  vector<int> v = arrayBag.toVector();
  cout << "The array is: " << endl;
  printVector<int>(v);
  cout << endl;
  bool rc = arrayBag.replace(9, 10);
  cout << "Was an attemt to replace 9 with 10 succesful?  -> " << rc << endl;
  cout << "Does the arraybag has item with value 9? -> " << arrayBag.contains(9) << endl;
  cout << "Does the arraybag has item with value 10?  -> " << arrayBag.contains(10) << endl;
  rc = arrayBag.replace(9, 10);
  cout << "Was the second attemt to replace 9 with 10 succesful? -> " << rc << endl;
  v = arrayBag.toVector();
  cout << "Vector out of the array" << endl;
  printVector<int>(v);
  cout << endl;
}

int main(){
  q3();
  return 0;
}
