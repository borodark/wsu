#include <string>

using namespace std;

Complex::Complex( int const real, int const imaginary )
  :r(real), i(imaginary){}

int Complex::getR() const {
  return r;
}

void Complex::setR(const int real){
  r = real;
}

int Complex::getI() const {
  return i;
}

void Complex::setI(const int imaginary){
  i = imaginary;
}

string Complex::print()  // print the (a + bi)
{
  return "(" + to_string(getR()) + " + " + to_string(getI()) +  "i)";
}
