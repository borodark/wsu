#include <iostream>
#include <string>

#ifndef _FRACTION
#define _FRACTION

class Fraction
{
 private:
  long long int n; // numerator
  long long int d; // denominator
  // Reduces this
  Fraction& reduceToLowestTerms();
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

  bool equals(const Fraction& d);
  std::string print() const;
};
#include "Fraction.cpp"
#endif
