#include "Employee.h"

using namespace std;

Employee::Employee(string fn, string ln, int ms)
  :first_name(fn),
   last_name(ln),
   monthly_salary(ms)
{
  if (monthly_salary < 0){
    monthly_salary = 0;
  }
}

string Employee::getFirstName() const {
  return first_name;
}
string Employee::getLastName() const {
  return last_name;
}
int Employee::getMonthlySalary() const {
  return monthly_salary;
}
void Employee::setFirstName(const string fn){
  first_name = fn;
}
void Employee::setLastName(const string ln){
  last_name = ln;
}
void Employee::setMonthlySalary(const int ms){
  monthly_salary = ms;
}
