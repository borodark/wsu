#include <iostream>
#include <cassert>
#include "Complex.h"
#include "Complex.cpp"
#include "read_number.cpp"


using namespace std;


void q4(){
  cout << endl;
  cout << "+ q4 ++++++++++" << endl;
  cout << " Creating an instanse of the Complex Number class" << endl;
  // std::cout << bold_on << "bold" << bold_off << " non-bold" << std::endl; 
  cout << "Please enter the " << bold_on << "Real" << bold_off<< " part: " << endl;
  int r = read_number();
  cout << "Please enter the " << bold_on << "Imaginary" << bold_off << " part, or 0 to exit" << endl;
  int i = read_number();
  cout << endl;
  Complex aComplex{r,i};
  cout << "a Complex is " << aComplex.print() << endl;
}

int main(){
  q4();
  return 0;
}
