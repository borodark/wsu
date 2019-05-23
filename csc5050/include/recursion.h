
namespace question2
{
  long double fact_r(long double n) {
    if (n == 0)
      return 1.0; // n > 0, so n-1 >= 0.
    else
      return n * fact_r(n - 1); // n * (n-1)! is n!
  }

  long double fact_w(long long n)
  {
    long double fact=1.0;
    if( n > 1 )
      for(unsigned long long k=2; k<=n; k++)
        fact = fact*k;

    return fact;
  }
}

