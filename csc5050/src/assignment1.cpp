#include <iostream>
#include <string>

using namespace std;

class Employee{

public:

  explicit Employee(string fn, string ln, int ms)
    :first_name(fn),
     last_name(ln),
     monthly_salary(ms)
  {
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


int main(){
  std::cout << "HAHAHA";
  Employee emp1{"Igor", "Osten", 220000};
  cout << "Welcome, the new emp1 \n" << emp1.getMonthlySalary() << "!" << endl;
  return 0;
}

