/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver/test for Question 3 of Assignment 4
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass4/src/q3.cpp
   The program is compiles and run correctly. Produces the correct results.
   See inline comments
**/

#include <iostream>
#include <cassert>
// #include "Node.h"
// #include "Profile.h"
#include "TheFaceBooks.h"
using namespace std;

void q3(){

  TheFaceBooks fb = TheFaceBooks{};
  Profile buzz = Profile{"buzz", "(:-)]", single};
  cout << buzz.print() << endl;

  Node buzzFB = Node{&buzz};

  Profile trexx = Profile{"T-Rexx", "8-0", rel};
  Node trexxFB = Node{&trexx};


  Profile woody = Profile{"woody", "=);-l", single};
  Node woodyFB = Node{&woody};

  woodyFB.addFriend(&buzzFB);
  woodyFB.addFriend(&trexxFB);
  cout << woodyFB.print() << endl;
}

int main(){
   q3();
  return 0;
}

