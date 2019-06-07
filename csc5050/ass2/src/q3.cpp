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
bool a_palindrome(int x) {
  if(x < 0 || (x % 10 == 0 && x != 0)) {
    return 0;
  }

  int revertedX = 0;
  while(x > revertedX) {
    revertedX = revertedX * 10 + x % 10;
    x /= 10;
  }
  return x == revertedX || x == revertedX/10;
}



void q3(){
  cout << endl;
  cout << "+ q3 ++++++++++" << endl;

  cout << "Please enter a numbers for palindrome check, or a " << bold_on << "Negative" << bold_off << " number to " << bold_on << "Exit" << bold_off << endl;
  int palindrome_of = read_number();

  while ( palindrome_of >= 0 ) {
    bool isP = a_palindrome(palindrome_of);
    string rc = isP?"IS A":"IS NOT A";
    cout << "The "<< palindrome_of << " "<< bold_on << rc  << bold_off << "  palindrome!"<< endl;
    cout << "Please enter a numbers for palindrome check, or a " << bold_on << "Negative" << bold_off << " number to " << bold_on << "Exit" << bold_off << endl;
    palindrome_of= read_number();
  }

}

int main(){
  q3();
  return 0;
} 

