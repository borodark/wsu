#include<cmath>
#include <iostream>
#include <limits>

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

ostream& bold_on(ostream& os)
{
  return os << "\e[1m";
}

ostream& bold_off(ostream& os)
{
  return os << "\e[0m";
}
