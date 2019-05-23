
namespace question2
{
  unsigned long long fact(int n) {
    if (n == 0)
      return 1; // n > 0, so n-1 >= 0.
    else
      return n * fact(n - 1); // n * (n-1)! is n!
  }
}

