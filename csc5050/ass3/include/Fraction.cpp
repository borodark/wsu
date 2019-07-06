#include <iostream>
#include "Fraction.h"

Fraction::Fraction(long long int n, long long int d) // construct only valid fractions
  :n(n),
   d(d)
{
  if (d == 0)
    throw std::invalid_argument("Invalid denominator! Can't be zero 0 ... ");

  }

std::string Fraction::print() const  // print the n/b
{
  return std::to_string(n) + "/" + std::to_string(d);
}

Fraction& Fraction::reduceToLowestTerms(){
  return *this; //TODO IMPLEMENT
}

bool Fraction::equals(const Fraction& another){
  return false; //TODO IMPLEMENT
}

  /** Adds a fraction to this
      @return this to have chain operations. */
Fraction& Fraction::add(const Fraction& a){
  return *this; //TODO IMPLEMENT
}
  /** subtract a fraction to this
      @return this to have chain operations. */
Fraction& Fraction::subtract(const Fraction& s){
  return *this; //TODO IMPLEMENT
}
  /** multiply a fraction by this
      @return this to have chain operations. */
Fraction& Fraction::multiply(const Fraction& m){
  return *this; //TODO IMPLEMENT
}
  /** divide this by a fraction
      @return this to have chain operations. */
Fraction& Fraction::divide(const Fraction& d){
  return *this; //TODO IMPLEMENT
}
