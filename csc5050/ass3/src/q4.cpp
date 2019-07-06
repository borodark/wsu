/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver/test for Question 4 of Assignment 4
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass3/src/q4.cpp
   The program is compiles and run correctly. Produces the correct results.
   See inline comments
**/

#include <iostream>
#include <cassert>
#include "LinkedBag.h"
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

void reverseLoopTest(){
  // q4.2.2
  // keep one occurence
  LinkedBag<int> lb2;
  lb2.add(10);
  lb2.add(210);
  lb2.add(120);
  lb2.add(160);
  lb2.add(104);
  lb2.add(103);
  lb2.add(1220);
  cout << "Reverse with loop!" << endl;
  
  vector<int> v1 = lb2.toVector();
  cout << "The l before is: " << endl;
  printVector<int>(v1);

  // expect 1220 103 104 160 120 210 10 after this
  lb2.reverseLoop();

  vector<int> v = lb2.toVector();
  cout << "The l is after reverse: " << endl;
  printVector<int>(v);
  // me function to check the 1220 is the first - only visual 
}


void reverseRecursionTest(){

  // q4.2.2
  // keep one occurence
  LinkedBag<int> lb2;
  lb2.add(10);
  lb2.add(210);
  lb2.add(120);
  lb2.add(160);
  lb2.add(104);
  lb2.add(103);
  lb2.add(1220);
  cout << "Reverse with recursion!" << endl;
  vector<int> v1 = lb2.toVector();
  cout << "The l before is: " << endl;
  printVector<int>(v1);

  // expect 1220 103 104 160 120 210 10
  lb2.reverseRecursion();
  vector<int> v = lb2.toVector();
  cout << "The l is after reverse: " << endl;
  printVector<int>(v);
  // me function to check the 1220 is the first - only visual 
}

void removeDuplicatesTest(){

  // q4.2 TODO remove duplicates
  // keep one occurence
  LinkedBag<int> lb2;
  lb2.add(10);
  lb2.add(120);
  lb2.add(210);
  lb2.add(120);
  lb2.add(160);
  lb2.add(104);
  lb2.add(120);
  lb2.add(104);
  lb2.add(120);
  lb2.add(104);

  vector<int> v1 = lb2.toVector();
  cout << "The l before is: " << endl;
  printVector<int>(v1);
  // expect 10 120 210 160 104 only
  LinkedBag<int> lb3 = lb2.removeDuplicates();
  vector<int> v = lb3.toVector();
  cout << "The l is: " << endl;
  printVector<int>(v);

  assert(lb3.contains(10));
  assert(lb3.getFrequencyOf(10) == 1);
  assert(lb3.contains(120));
  assert(lb3.getFrequencyOf(120) == 1);
  assert(lb3.contains(210));
  assert(lb3.getFrequencyOf(210) == 1);
  assert(lb3.contains(160));
  assert(lb3.getFrequencyOf(160) == 1);
  assert(lb3.contains(104));
  assert(lb3.getFrequencyOf(104) == 1);
  assert(lb3.getCurrentSize() == 5);
}

int main(){
  reverseLoopTest();
  reverseRecursionTest();
  removeDuplicatesTest();

  return 0;
}

