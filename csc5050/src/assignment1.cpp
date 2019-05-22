#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Employee{

public:

  explicit Employee(string fn, string ln, int ms)
    :first_name(fn),
     last_name(ln),
     monthly_salary(ms)
  {
    if (monthly_salary < 0){
      monthly_salary = 0;
    }
  }
  string getFirstName() const {
    return first_name;
  }
  string getLastName() const {
    return last_name;
  }
  int getMonthlySalary() const {
    return monthly_salary;
  }
  void setFirstName(const string fn){
    first_name = fn;
  }
  void setLastName(const string ln){
    last_name = ln;
  }
  void setMonthlySalary(const int ms){
    monthly_salary = ms;
  }

private:
  string first_name;
  string last_name;
  int monthly_salary;

};


void q1(){
  Employee emp1{"Igor", "Osten", 200000};
  cout << "Welcome, the new emp1, making staggering " << emp1.getMonthlySalary() << "!" << endl;
  assert(emp1.getFirstName() == "Igor");
  Employee emp2{"Igor", "Osten1", -1000};
  cout << "Welcome, the new emp2, making staggering " << emp2.getMonthlySalary() << "!" << endl;
  assert(emp2.getMonthlySalary() == 0);
  emp2.setMonthlySalary(1000000);
  cout << "HR mistake is fixed! emp2 is now making " << emp2.getMonthlySalary() << "!" << endl;
  cout << "Promotions are coming!" << endl;
  emp1.setMonthlySalary(emp1.getMonthlySalary() * 1.1);
  assert(emp1.getMonthlySalary() == 220000);
  emp2.setMonthlySalary(emp2.getMonthlySalary() * 1.1);
  assert(emp2.getMonthlySalary() == 1100000);
  cout << "The emp1 is now making " << emp1.getMonthlySalary() << "!" << endl;
  cout << "The emp2 is now making " << emp2.getMonthlySalary() << "!" << endl;

}

int main(){
  q1();
  return 0;
}

