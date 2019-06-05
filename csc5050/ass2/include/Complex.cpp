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

string Complex::print() const  // print the (a + bi)
{
  return "(" + to_string(getR()) + " + " + to_string(getI()) +  "i)";
}

const Complex Complex::add(const Complex toAdd){
  int ourR = getR();
  int theirsR = toAdd.getR();

  int ourI = getI();
  int theirsI = toAdd.getI();
  Complex rc{ (ourR + theirsR), (ourI + theirsI) };
  return rc;
}

const Complex Complex::subtract(const Complex toSubtrack){
  int ourR = getR();
  int theirsR = toSubtrack.getR();

  int ourI = getI();
  int theirsI = toSubtrack.getI();
  Complex rc{ (ourR - theirsR), (ourI - theirsI) };
  return rc;
}
