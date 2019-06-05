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
  int i1 = read_number();
  cout << "Please enter the " << bold_on << "Imaginary" << bold_off << " part, or 0 to exit" << endl;
  int i2 = read_number();
  while (i2 != 0){
    if ((i1 % i2) == 0){
      cout << "the first is a multiple of the second!" << endl;
    } else {
      cout << "the first is NOT a multiple of the second!" << endl;
    }
    cout << endl;
    cout << "Please enter integer one" << endl;
    i1 = read_number();
    cout << "Please enter integer two or 0 to exit" << endl;
    i2 = read_number();
  }
}

int main(){
  q4();
  return 0;
}
