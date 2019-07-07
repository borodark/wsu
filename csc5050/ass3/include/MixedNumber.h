#include <iostream>
#include <string>
#include "Fraction.h"
#ifndef _MIXED_NUMBER
#define _MIXED_NUMBER

class MixedNumber
{
 private:
  long long int iPart; // Integer part
  Fraction fPart; // Fractional part

 public:
	explicit MixedNumber(long long int i, const Fraction& f); // 
  explicit MixedNumber(const Fraction& f); // 
  /** Adds a fraction to this
      @return this to have chain operations. */
  MixedNumber& add(const MixedNumber& a);
  /** subtract a fraction to this
      @return this to have chain operations. */
  MixedNumber& subtract(const MixedNumber& s);
  /** multiply a fraction by this
      @return this to have chain operations. */
  MixedNumber& multiply(const MixedNumber& m);
  /** divide this by a fraction
      @return this to have chain operations. */
  MixedNumber& divide(const MixedNumber& d);

  bool equals(const MixedNumber& d) const;
  std::string print() const;
};
#include "MixedNumber.cpp"
#endif
