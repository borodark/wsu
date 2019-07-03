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
  cout << endl;
}

template<class Item>
void mergeBags(ArrayBag<Item> const &b1, ArrayBag<Item> const &b2)
{
  int newsize = b1.getCurrentSize() + b2.getCurrentSize();
  ArrayBag<Item> target{newsize};
  vector<Item> v1 = b1.toVector();
  vector<Item> v2 = b2.toVector();
  for (Item const &element: v1) {
    cout << "adding v1 item: " << element << endl;
    target.add(element);
  }
  for (Item const &element: v2) {
    cout << "adding v2 item: " << element << endl;
    target.add(element);
  }
  cout << "size of the target is: " << target.getCurrentSize() << endl;
  cout << "the target is: " << endl;
  printVector(target.toVector());
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
  // q3.3 
  ArrayBag<int> ab2;
  ab2.add(10);
  ab2.add(210);
  ab2.add(120);
  ab2.add(160);
  ab2.add(104);
  // 5 elements
  mergeBags<int>(arrayBag, ab2);
}

int main(){
  q3();
  return 0;
}

