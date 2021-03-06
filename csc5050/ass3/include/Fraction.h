#include <iostream>
#include <string>

#ifndef _FRACTION
#define _FRACTION

class Fraction
{
  friend class MixedNumber;

 private:
  long long int n; // numerator
  long long int d; // denominator
  // Reduces this
  void reduceToLowestTerms();
  long long int greatestCommonDivizor(long long int x,long long int y);

 public:
	explicit Fraction(long long int n, long long int d); // construct only valid fractions
  /** Adds a fraction to this
      @return this to have chain operations. */
  Fraction& add(const Fraction& a);
  /** subtract a fraction to this
      @return this to have chain operations. */
  Fraction& subtract(const Fraction& s);
  /** multiply a fraction by this
      @return this to have chain operations. */
  Fraction& multiply(const Fraction& m);
  /** divide this by a fraction
      @return this to have chain operations. */
  Fraction& divide(const Fraction& d);

  bool equals(const Fraction& d) const;

  bool less(const Fraction& d) const;

  std::string print() const;
};
#include "Fraction.cpp"
#endif
