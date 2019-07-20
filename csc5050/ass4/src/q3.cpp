/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver/test for Question 3 of Assignment 4
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass4/src/q3.cpp
   The program is compiles and run correctly. Produces the correct results.
   See inline comments
**/

#include <iostream>
#include <cassert>
#include "TheFaceBooks.h"
using namespace std;

void q3(){

  TheFaceBooks fb = TheFaceBooks{};

  Profile* buzzPtr = fb.createProfile("buzz", "|(:-)]|", single);
  cout << buzzPtr->print() << endl;


  TFBMember* buzzFBPtr = fb.joinTFB(buzzPtr);

  Profile* trexx = fb.createProfile("T-Rexx", "| 8-0 |", rel);
  TFBMember* trexxFB = fb.joinTFB(trexx);

  Profile* woody = fb.createProfile("woody", "|=);-l|", single);
  // TFBMember* woodyFB = TFBMember{&woody};

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
  woody = fb.createProfile("woody", "|=);-l|", single);
  cout << fb.printProfiles() << endl;
  cout << "He is back!!!" << endl;
  cout << ":-)" << endl;

  cout << "Woody joins TFB!!!" << endl;
  TFBMember* woodyFB = fb.joinTFB(woody);
  cout << fb.printProfiles() << endl;

  cout << fb.printMembers() << endl;
  fb.beFriend(woodyFB,trexxFB);
  // TODO implement search
  cout << "Woody is in frends with buzz and trexx!!!" << endl;
  fb.beFriend(woodyFB, buzzFBPtr);
  cout << woodyFB->print() << endl;
  woody->setName("Woody, The Sherriffffff");
  woody->setPicture("|=}:-)|");
  cout << "Woody got a job, a new hat and smiling!!" << endl;
  cout << woodyFB->print() << endl;
  //
  cout << "Seen Woody\'s new picture? Let's find him by the picture?" << endl;
  list<TFBMember*> woodies = fb.search("|=}:-)|");
  assert(woodies.size() == 1);
  cout << "Search by picture Works! ...Here is the Woody:" << endl;
  TFBMember* newFoundWoody = woodies.front();
  cout << newFoundWoody->print() << endl;
  cout << "All are in frends with Woody!!!" << endl;
  cout << buzzFBPtr->print() << endl;
  cout << trexxFB->print() << endl;

  cout << "Woody is leaving TFB!!!" << endl;

  fb.leaveTFB(woodyFB);

  cout << fb.printProfiles() << endl;
  cout << fb.printMembers() << endl;

  cout << "WOODY LEFT TFB!!!" << endl;
  cout << "No! Let's find him by name?" << endl;
  woodies = fb.search("Woody");
  assert(woodies.size() == 0);
  cout << "No! He was last known as Woody, The Sherriffffff" << endl;
  woodies = fb.search("Woody, The Sherriffffff");
  assert(woodies.size() == 0);
  cout << "Still no sign of him! - He may have left for good..." << endl;
  cout << "Woody is deleting his profile!!!" << endl;

  fb.deleteProfile(woody);

  cout << fb.printProfiles() << endl;

  cout << "WOODY LEFT OMG!!! This time it is final ;-) ... Perhaps that search by picture is creepy after all." << endl;

}

int main(){
   q3();
  return 0;
}

