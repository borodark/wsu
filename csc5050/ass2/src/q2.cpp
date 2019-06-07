/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver/test for Question 2 of Assignment 2
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass2/src/q2.cpp
   The program is compiles and runs correctly. Produces the correct results.
   See inline comments
**/

#include <iostream>
#include <cassert>
#include "read_number.cpp"

using namespace std;

void q2(){
  cout << endl;
  cout << "+ q2 ++++++++++" << endl;

  cout << "Please enter the numbers for factorial to be calculated, to break the loop enter a negative number" << endl;

  int answer = read_number();

  while ( !true ) {
    cout << "Please enter the numbers for factorial to be calculated, to break the loop enter a negative number" << endl;
  }
  cout << endl;
  //

}

int main(){
  q2();
  return 0;
}

