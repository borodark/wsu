#include <iostream>
#include <cassert>
#include "Complex.h"
#include "Complex.cpp"
#include "read_number.cpp"


using namespace std;


void q4(){
  cout << endl;
  cout << "+ q4 ++++++++++" << endl;
  cout << " Creating an instanse of the Complex Number class with default no Argument constructor:" << endl;
  Complex aComplex;
  cout << "a Complex is " << aComplex.print() << endl;
  //
  cout << endl;
  cout << " Creating an instanse of the Complex Number class" << endl;
  cout << "Please enter the " << bold_on << "Real" << bold_off<< " part: " << endl;
  int r = read_number();
  cout << "Please enter the " << bold_on << "Imaginary" << bold_off << " part, or 0 to exit" << endl;
  int i = read_number();
  cout << endl;
  Complex bComplex{r,i};
  cout << "a Complex is " << bComplex.print() << endl;
  //
  cout << endl;
  cout << "Adding first one to the second one " << endl;

  cout << "The " << bold_on << "Summ" << bold_off << " of two Complexes is " << bold_on << aComplex.add(bComplex).print() << bold_off << endl;
  //
  cout << endl;
  Complex cComplex{6,7};
  cout << "Another Complex is " << bold_on << bComplex.print() << bold_off << endl;
  //
  cout << endl;
  cout << "Let's " << bold_on << "Subtrack" << bold_off << " the " << bold_on << cComplex.print() << bold_off << " from the " << bold_on << bComplex.print() << bold_off << endl;
  Complex rc = bComplex.subtract(cComplex);
  cout << "The " << bold_on << "differense" << bold_off << " of two is " << rc.print() << endl;

}

int main(){
  q4();
  return 0;
}
