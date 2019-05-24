#include <iostream>
#include <cassert>
#include "Employee.h"
#include "recursion.h"

using namespace std;

int read_number(){
  int rc;
  cin >> rc;
  while(1){
    if(cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "You have entered wrong input, numbers only, please!" << endl;
        cin >> rc;
      }
    if(!cin.fail())
      break;
    }
  return rc;
}

void q1(){
  cout << endl;
  cout << "+ q1 ++++++++++" << endl;

  Employee emp1{"Igor", "Osten1", 200000};
  cout << "Welcome, the new emp1, making staggering " << emp1.getMonthlySalary() << "." << endl;
  assert(emp1.getFirstName() == "Igor");
  Employee emp2{"Igor", "Osten2", -1000};
  cout << "Welcome, the new emp2, making staggering " << emp2.getMonthlySalary() << "." << endl;
  assert(emp2.getMonthlySalary() == 0);
  emp2.setMonthlySalary(1000000);
  cout << "HR mistake is fixed! emp2 is now making " << emp2.getMonthlySalary() << "." << endl;
  cout << "Promotions are coming!" << endl;
  emp1.setMonthlySalary(emp1.getMonthlySalary() * 1.1);
  assert(emp1.getMonthlySalary() == 220000);
  emp2.setMonthlySalary(emp2.getMonthlySalary() * 1.1);
  assert(emp2.getMonthlySalary() == 1100000);
  cout << "The " << emp1.getLastName() << " is now making " << emp1.getMonthlySalary() << "." << endl;
  cout << "The " << emp2.getLastName() << " is now making " << emp2.getMonthlySalary() << "." << endl;
  cout << endl;
}

void q2(){
  cout << endl;
  cout << "+ q2.a ++++++++++" << endl;
  cout << "The factorial of 100 is " << question2::fact_r(100) << "." << endl;
  cout << "The factorial of 10 is " << question2::fact_r(10) << "." << endl;
  cout << "The factorial of 4 is " << question2::fact_r(4) << "." << endl;

  cout << "Please enter the numbers for factorial to be calculated, to break the loop enter a negative number" << endl;

  int factorial_of = read_number();

  while ( factorial_of >= 0 ) {
    long double rc = question2::fact_r(factorial_of);
    cout << "The factorial of " << factorial_of << " is " << rc << endl ;
    cout << "Please enter the numbers for factorial to be calculated, to break the loop enter a negative number" << endl;
    factorial_of = read_number();
  }
  cout << endl;
  cout << "+ q2.b ++++++++++" << endl;
  //
  cout << "Please enter the desired accuracy of e (i.e., the number of terms in the summation). To break the loop enter a negative number" << endl;

  int precision = read_number();
  while ( precision >= 0 ) {
    cout.precision(precision+1);
    cout << "The e with " << precision << " terms is " << question2::euler_e(precision) << endl;
    precision = read_number();
  }

  //
  cout << endl;
  cout << "+ q2.c ++++++++++" << endl;
  //
  cout << "Please enter the desired accuracy for e ^ X (i.e., the number of terms in the summation). To break the loop enter a negative number" << endl;
  precision = read_number();
  while ( precision >= 0 ) {
    cout.precision(precision);
    cout << "Please enter the X for e ^ X. To break the loop enter a negative number" << endl;
    int x = read_number();
    while ( x >= 0 ) {
      cout << "The e ^ " << x << " with " << precision << " terms is " << question2::e_pow(x,precision) << endl;
      cout << "Please enter the X for e ^ X. To break the loop enter a negative number" << endl;
      x = read_number();
    }
  cout << "Please enter the desired accuracy for e ^ X (i.e., the number of terms in the summation). To break the loop enter a negative number" << endl;
    precision = read_number();
  }


}

int main(){
  q1();
  q2();
  return 0;
}

