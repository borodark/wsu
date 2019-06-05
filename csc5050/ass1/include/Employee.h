#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

class Employee{

 public:
  explicit Employee(string fn, string ln, int ms);
  string getFirstName() const;
  string getLastName() const;
  int getMonthlySalary() const;
  void setFirstName(const string fn);
  void setLastName(const string ln);
  void setMonthlySalary(const int ms);

 private:
  string first_name;
  string last_name;
  int monthly_salary;

};

#endif
