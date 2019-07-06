/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver/test for Question 4 of Assignment 4
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass3/src/q4.cpp
   The program is compiles and run correctly. Produces the correct results.
   See inline comments
**/

#include <iostream>
#include <cassert>
using namespace std;

/**
   This function, called Ackermann’s function, is of interest because it grows rapidly with respect to the sizes of m and n.
   What is Acker (1, 2)?
   Implement the function in C++ and do a box trace of Acker (1, 2).
*/

long long int acker(long long int m, long long int n) {
  if (m == 0){
    cout << "m is 0 returning n + 1 ..." << endl;
    return n + 1;
  }
  else if (n == 0){ 
    cout << "n is 0 returning acker(m - 1,1) ..." << endl;
    return acker(m - 1,1); 
  } else {
    cout << "n is " << n << " m is " << m << " ..." << endl;
    return acker(m - 1, acker(m,n-1));
  }
}



int main(){
  cout << "What is Acker (1, 2)?" << endl;
  long long int a1 = acker(1, 2);
  cout << "The Acker (1, 2) is: "<< a1 << endl;
  cout << "What is Acker (2, 2)?" << endl;
  long long int a2 = acker(2, 2);
  cout << "The Acker (2, 2) is: " << a2 << endl;
  cout << "What is Acker (2, 5)? It is: " << endl;
  long long int a3 = acker(2, 5);
  cout << "The Acker (2, 5) is: " << a3 << endl;
  cout << "What is Acker (3, 7)? It is: " << endl;
  long long int a4 = acker(3, 7);
  cout << "The Acker (3, 7) is: " << a4 << endl;
  return 0;
}

