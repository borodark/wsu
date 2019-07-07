#include <iostream>
#include "MixedNumber.h"
#include "Fraction.h"


void MixedNumber::reduce(){
  iPart += fPart.n/fPart.d;
  fPart = Fraction{fPart.n%fPart.d,fPart.d};
}

MixedNumber::MixedNumber(long long int i, const Fraction& f)
  :iPart(i + f.n/f.d), // TODO handle sign
   fPart(Fraction{f.n%f.d,f.d})
{
  std::cout << "Constructed " << print() << std::endl;
}

MixedNumber::MixedNumber(const Fraction& f)
  :iPart(f.n/f.d),
   fPart(Fraction{abs(f.n)%f.d,f.d}) // call abs - sign is in iPart
{
  std::cout << "Constructed " << print() << std::endl;
}

MixedNumber::MixedNumber(long long int i, long long int numerator, long long int denominator)
  :iPart(((numerator < 0)?(-1):1) * (i + abs(numerator)/denominator)), // figure i part
   fPart(Fraction{((numerator < 0)?abs(numerator):numerator)%denominator, denominator}) // fraction < 1
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
  if(fPart.less(s.fPart)){
    iPart -= 1; // borrow one to keep fraction positive
    fPart.add(Fraction{1,1}); // add one to fraction part
  }
  fPart.subtract(s.fPart);
  reduce();
  return *this;
}
  /** multiply a fraction by this
      @return this to have chain operations. */
MixedNumber& MixedNumber::multiply(const MixedNumber& m){
  // consrtuct, multiply and reduce fractions, handling negatives
  bool negate_this = (iPart < 0) || (fPart.n < 0);
  bool negate_m = (m.iPart < 0) || (m.fPart.n < 0);
  Fraction product = (Fraction{(negate_this?-1:1) * (abs(iPart)*fPart.d + abs(fPart.n)), fPart.d}).
    multiply(Fraction{(negate_m?-1:1) * (abs(m.iPart)*m.fPart.d + abs(m.fPart.n)), m.fPart.d});
  MixedNumber rc = MixedNumber(product);
  iPart = rc.iPart;
  fPart = rc.fPart;
  return *this;
}
  /** divide this by a fraction
      @return this to have chain operations. */
MixedNumber& MixedNumber::divide(const MixedNumber& d){
  // consrtuct, multiply and reduce fractions, handling negatives
  bool negate_this = (iPart < 0) || (fPart.n < 0);
  bool negate_d = (d.iPart < 0) || (d.fPart.n < 0);
  Fraction division = (Fraction{(negate_this?-1:1)*(abs(iPart)*fPart.d + abs(fPart.n)), fPart.d}).
     multiply(Fraction{d.fPart.d, (negate_d?-1:1)*(abs(d.iPart)*d.fPart.d + abs(d.fPart.n))});
     // division is the operation opposed to multiplication
  MixedNumber rc = MixedNumber(division);
  iPart = rc.iPart;
  fPart = rc.fPart;
  return *this;
}
