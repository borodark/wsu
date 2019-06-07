/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a Class implememtation for Complex type used in answering Question 4 of Assignment 2
   @src
   The program is compiles and run correctly. Produces the correct results.
**/
#include <string>

using namespace std;

Complex::Complex( int const real, int const imaginary )
  :r(real), i(imaginary){}

int Complex::getR() const {
  return r;
}

int Complex::getI() const {
  return i;
}

string Complex::print() const  // print the (a + bi)
{
  return "(" + to_string(getR()) + " + " + to_string(getI()) +  "i)";
}

/**
   Produces new instace of the class adding the given argument to this.
 **/
const Complex Complex::add(const Complex toAdd){
  int ourR = getR();
  int theirsR = toAdd.getR();

  int ourI = getI();
  int theirsI = toAdd.getI();
  Complex rc{ (ourR + theirsR), (ourI + theirsI) };
  return rc;
}
/**
   Produces new instace of the class subtracting the given argument from this.
**/

const Complex Complex::subtract(const Complex toSubtrack){
  int ourR = getR();
  int theirsR = toSubtrack.getR();

  int ourI = getI();
  int theirsI = toSubtrack.getI();
  Complex rc{ (ourR - theirsR), (ourI - theirsI) };
  return rc;
}
