#include<cmath>

namespace question2
{
  long double fact_r(long double n) {
    if (n == 0)
      return 1.0; // n > 0, so n-1 >= 0.
    else
      return n * fact_r(n - 1); // n * (n-1)! is n!
  }

  long double e_pow(long x, int number_of_terms) {
    unsigned int n = 1;
    double long epowx = 1.0;
    while( n <= number_of_terms ){
      epowx += pow(x,n)/fact_r(n);
      n++;
    }
    return epowx;
  }

  long double euler_e(int number_of_terms) {
    unsigned int n = 1;
    double long e = 1.0;
    while( n <= number_of_terms ) {
      e += 1/fact_r(n);
      n++;
    }
    return e;
  }
}

