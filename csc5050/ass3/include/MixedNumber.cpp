#include <iostream>
#include "MixedNumber.h"
#include "Fraction.h"


MixedNumber::MixedNumber(long long int i, const Fraction& f)
  :iPart(i + f.n/f.d),
   fPart(Fraction{f.n%f.d,f.d})
{
  std::cout << print() << std::endl;
}

MixedNumber::MixedNumber(const Fraction& f)
  :iPart(f.n/f.d),
   fPart(Fraction{f.n%f.d,f.d})
{
  std::cout << print() << std::endl;
}

std::string MixedNumber::print() const {
  return "MixedNumber is " + std::to_string(iPart) +  " and " + fPart.print();
}


bool MixedNumber::equals(const MixedNumber& another) const {
  return (another.iPart == iPart && another.fPart.equals(another.fPart)); 
}

  /** Adds a fraction to this
      @return this to have chain operations. */
MixedNumber& MixedNumber::add(const MixedNumber& a){
  // std::cout << n << "/" << d << " + " << a.n << "/" << a.d << " = ";
  // TODO implement!!!
  return *this;
}
  /** subtract a fraction to this
      @return this to have chain operations. */
MixedNumber& MixedNumber::subtract(const MixedNumber& s){
  // std::cout << n << "/" << d << " - " << s.n << "/" << s.d << " = ";
  // TODO implement!!!
  return *this;
}
  /** multiply a fraction by this
      @return this to have chain operations. */
MixedNumber& MixedNumber::multiply(const MixedNumber& multiplier){
  // std::cout << n << "/" << d << " * " << multiplier.n << "/" << multiplier.d << " = ";
  // TODO implement!!!
  return *this;
}
  /** divide this by a fraction
      @return this to have chain operations. */
MixedNumber& MixedNumber::divide(const MixedNumber& divisor){
  // std::cout << n << "/" << d << " / " << divisor.n << "/" << divisor.d << " = ";
  // TODO implement!!!
  return *this;
}
