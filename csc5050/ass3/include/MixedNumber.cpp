#include <iostream>
#include "MixedNumber.h"
#include "Fraction.h"


void MixedNumber::reduce(){
  iPart += fPart.n/fPart.d;
  fPart = Fraction{fPart.n%fPart.d,fPart.d};
}

MixedNumber::MixedNumber(long long int i, const Fraction& f)
  :iPart(i + f.n/f.d),
   fPart(Fraction{f.n%f.d,f.d})
{
  std::cout << "Constructed " << print() << std::endl;
}

MixedNumber::MixedNumber(const Fraction& f)
  :iPart(f.n/f.d),
   fPart(Fraction{f.n%f.d,f.d})
{
  std::cout << "Constructed " << print() << std::endl;
}

MixedNumber::MixedNumber(long long int i, long long int numerator, long long int denominator)
  :iPart(i),
   fPart(Fraction{numerator, denominator})
{
  std::cout << "Constructed "<< print() << std::endl;
}

std::string MixedNumber::print() const {
  return std::to_string(iPart)+" " + fPart.print();
}


bool MixedNumber::equals(const MixedNumber& another) const {
  return (another.iPart == iPart && another.fPart.equals(another.fPart)); 
}

  /** Adds a fraction to this
      @return this to have chain operations. */
MixedNumber& MixedNumber::add(const MixedNumber& a){
  iPart += a.iPart;
  fPart.add(a.fPart);
  // std::cout << print() << " + " << a.print() << " = ";
  reduce();
  return *this;
}
  /** subtract a fraction to this
      @return this to have chain operations. */
MixedNumber& MixedNumber::subtract(const MixedNumber& s){
  iPart -= s.iPart;
  if(fPart.greater(s.fPart)){
    // no need to borrow 1 from iPart before subrtracttion
    fPart.subtract(s.fPart);
  } else {
    iPart -= 1; // borrow one to keep fraction positive
    fPart.add(Fraction{1,1}); // add one to fraction part
    fPart.subtract(s.fPart);
  }
  // std::cout << print() << " + " << a.print() << " = ";
  reduce();
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
