#include <iostream>
#include <cassert>
#include "recursion.h"

using namespace std;

void q2(){
  cout << endl;
  cout << "+ q2.a ++++++++++" << endl;
  cout << "The factorial of 100 is " << fact_r(100) << "." << endl;
  cout << "The factorial of 10 is " << fact_r(10) << "." << endl;
  cout << "The factorial of 4 is " << fact_r(4) << "." << endl;

  cout << "Please enter the numbers for factorial to be calculated, to break the loop enter a negative number" << endl;

  int factorial_of = read_number();

  while ( factorial_of >= 0 ) {
    long double rc = fact_r(factorial_of);
    cout << "The factorial of " << factorial_of << " is " << rc << endl ;
    cout << "Please enter the numbers for factorial to be calculated, to break the loop enter a negative number" << endl;
    factorial_of = read_number();
  }
  cout << endl;
  cout << "+ q2.b ++++++++++" << endl;
  //
  cout << "Please enter the desired accuracy of e (i.e., the number of terms in the summation). To break the loop enter a negative number" << endl;

  int precision = read_number();
  while ( precision >= 0 ) {
    cout.precision(precision+1);
    cout << "The e with " << precision << " terms is " << euler_e(precision) << endl;
    precision = read_number();
  }

  //
  cout << endl;
  cout << "+ q2.c ++++++++++" << endl;
  //
  cout << "Please enter the desired accuracy for e ^ X (i.e., the number of terms in the summation). To break the loop enter a negative number" << endl;
  precision = read_number();
  while ( precision >= 0 ) {
    cout.precision(precision);
    cout << "Please enter the X for e ^ X. To break the loop enter a negative number" << endl;
    int x = read_number();
    while ( x >= 0 ) {
      cout << "The e ^ " << x << " with " << precision << " terms is " << e_pow(x,precision) << endl;
      cout << "Please enter the X for e ^ X. To break the loop enter a negative number" << endl;
      x = read_number();
    }
  cout << "Please enter the desired accuracy for e ^ X (i.e., the number of terms in the summation). To break the loop enter a negative number" << endl;
    precision = read_number();
  }


}

int main(){
q2();
return 0;
}

