/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver and the implememtation of Palindrom as an answer Question 3 of Assignment 2
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass2/src/q3.cpp
   The program is compiles and run correctly. Produces the correct results.
**/

#include <iostream>
#include <cassert>
#include "read_number.cpp"

using namespace std;

/**
   negatives are not palindromes.
   if the last digit of the number is 0 then the first digit of the number
   also needs to be 0. <=> 0 is the only number that is the palindrome with 0at the end.
**/
bool is_palindrome(int x) {
  if(x < 0 || (x % 10 == 0 && x != 0)) {
    return false;
  }

  int revertedNumber = 0;
  while(x > revertedNumber) {
    revertedNumber = revertedNumber * 10 + x % 10;
    x /= 10;
  }
  return x == revertedNumber || x == revertedNumber/10;
}



void q3(){
  cout << endl;
  cout << "+ q3 ++++++++++" << endl;

  cout << "Please enter the numbers for palindrome check, to break the loop enter a negative number" << endl;
  int palindrome_of = read_number();

  while ( palindrome_of >= 0 ) {
    cout << "The palindrome is " << endl ;
    cout << "Please enter the numbers for factorial to be calculated, to break the loop enter a negative number" << endl;
    palindrome_of= read_number();
  }

}

int main(){
  q3();
  return 0;
}

