#include <iostream>
#include "recursion.h"

//using read_number();

void q4(){
  cout << endl;
  cout << "+ q4 ++++++++++" << endl;
  cout << "Please enter integer one" << endl;
  int i1 = read_number();
  cout << "Please enter integer two or 0 to exit" << endl;
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
