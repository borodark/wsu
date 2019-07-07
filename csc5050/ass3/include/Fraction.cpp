#include <iostream>
#include "Fraction.h"

Fraction::Fraction(long long int n, long long int d) // construct only valid fractions
  :n(n),
   d(d)
{
  if (d == 0)
    throw std::invalid_argument("Invalid denominator! Can't be zero AKA 0 or \"0\" ... ");
  else
    reduceToLowestTerms();
}

std::string Fraction::print() const  // print the n/b
{
  return std::to_string(n) + "/" + std::to_string(d);
}

long long int Fraction::greatestCommonDivizor(long long int num,long long int den){
  if (den == 0) 
    return num;
  return greatestCommonDivizor(den, num % den);
}

void Fraction::reduceToLowestTerms(){
  long long int gcd = greatestCommonDivizor(n, d);
  std::cout << n << "/" << d << " has gcd of " << gcd;
  if (gcd < 0){ // deal with negative gcd
    gcd *= -1; // n keeps negtive sign from here
  }
  d=d/gcd;
  n=n/gcd;
  std::cout << " is  reduced to " << print() << std::endl;

}

bool Fraction::equals(const Fraction& another) const {
  return (another.d == d && another.n == n); 
}

  /** Adds a fraction to this
      @return this to have chain operations. */
Fraction& Fraction::add(const Fraction& a){
  // 1/2 + 1/3 = 3/6 + 2/6 = 5/6
  std::cout << n << "/" << d << " + " << a.n << "/" << a.d << " = ";
  n = n * a.d + a.n * d;
  d = d * a.d;
  reduceToLowestTerms();
  return *this;
}
  /** subtract a fraction to this
      @return this to have chain operations. */
Fraction& Fraction::subtract(const Fraction& s){
  std::cout << n << "/" << d << " - " << s.n << "/" << s.d << " = ";
  n = n * s.d - s.n * d;
  d = d * s.d;
  reduceToLowestTerms();
  return *this;
}
  /** multiply a fraction by this
      @return this to have chain operations. */
Fraction& Fraction::multiply(const Fraction& multiplier){
  std::cout << n << "/" << d << " * " << multiplier.n << "/" << multiplier.d << " = ";
  n = n * multiplier.n;
  d = d * multiplier.d;
  reduceToLowestTerms();
  return *this;
}
  /** divide this by a fraction
      @return this to have chain operations. */
Fraction& Fraction::divide(const Fraction& divisor){
  std::cout << n << "/" << d << " / " << divisor.n << "/" << divisor.d << " = ";
  n = n * divisor.d;
  d = d * divisor.n;
  reduceToLowestTerms();
  return *this;
}
