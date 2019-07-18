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

  Profile* buzzPtr = fb.createProfile("buzz", "(:-)]", single);
  cout << buzzPtr->print() << endl;


  Node* buzzFBPtr = fb.joinTFB(buzzPtr);

  Profile* trexx = fb.createProfile("T-Rexx", "8-0", rel);
  Node* trexxFB = fb.joinTFB(trexx);

  Profile* woody = fb.createProfile("woody", "=);-l", single);
  // Node* woodyFB = Node{&woody};

  cout << fb.printMembers() << endl;

  cout << fb.printProfiles() << endl;

  cout << "Woody is deleting his profile!!!" << endl;

  fb.deleteProfile(woody);

  cout << fb.printProfiles() << endl;

  cout << "WOODY LEFT OMG!!!" << endl;
  cout << ":-(" << endl;
  cout << ":-(" << endl;
  cout << ":-(" << endl;
  cout << "Woody? Come back! Please!!!" << endl;
  woody = fb.createProfile("woody", "=);-l", single);
  cout << fb.printProfiles() << endl;
  cout << "He is back!!!" << endl;
  cout << ":-)" << endl;
  
  //  woodyFB.addFriend(&buzzFB);
  //woodyFB.addFriend(&trexxFB);
  //cout << woodyFB.print() << endl;
}

int main(){
   q3();
  return 0;
}

