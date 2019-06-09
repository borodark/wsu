/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver/test and implementation for Question 2 of Assignment 2
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass2/src/q2.cpp
   The program is compiles and runs correctly. Produces the correct results.
   See inline comments
**/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <tuple>
#include "read_number.cpp"


using namespace std;
static string ERROR  = "No. Please try again.";
static string SUCCESS  = "Very good!";
static string HOW_MUCH_IS = "How much is ";
static string TIMES = " times ";
static string PLS_ENTER = "Please enter the result and press enter! Use CTRL+C to quit!";

tuple<int,int,int> exersice(){
  int r = rand() % 10; // left
  int l = rand() % 10; // right
  int p = r * l; // product
  tuple<int,int,int> rc (l,r,p);
  return rc;
}

void q2(){
  // show instructions
  cout << endl;
  cout << "+ q2 ++++++++++" << endl;
  cout << "This is a game to learn" << bold_on << "Multiplication"<< bold_off << endl;
  cout << "The system will show the exersise, you will enter the answer!"  << endl;
  cout <<" For example: " << endl;
  cout << bold_on << "How much is 6 times 7?"<< bold_off << endl;
  cout << endl;
  cout << "You enter 42 and press " << bold_on << "Enter" << bold_off  << endl;
  // init vars
  int answer = 0;
  int r = 0;
  int l = 0;
  int rc =0;
  while(true){ // continue till CTRL+C
    tie (l,r,rc) = exersice(); // receive and unpack triple with the task
    cout << HOW_MUCH_IS << bold_on << r <<  bold_off << TIMES << bold_on << l <<  bold_off << " ?" << endl;
    cout << PLS_ENTER << endl;
    answer = read_number();
    while ( answer != rc) { // repeat till correct answer is entered
      cout << bold_on << ERROR <<  bold_off << endl << endl;
      cout << HOW_MUCH_IS << bold_on << r <<  bold_off << TIMES << bold_on << l <<  bold_off << " ?" << endl;
      cout << PLS_ENTER << endl;
      answer = read_number();
    }
    cout << bold_on << SUCCESS << bold_off << endl << endl;
  }
  cout << endl;
}

int main(){
  q2();
  return 0;
}

