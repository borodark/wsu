/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass4/src/q1.cpp
   This is a driver/test for Question 1 of Assignment 4
   The program is compiles and run correctly. Produces the correct results.
**/

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/** state */

class Towers {
private:
  int disks;
public:
  Towers(int disks);
  vector<int> a = vector<int>();
  vector<int> b = vector<int>();
  vector<int> c = vector<int>();
  void move(unsigned char from, unsigned char to);
  void print();
};
Towers::Towers(int ofDisks) : disks(ofDisks)
{
  cout << "pushing "<< disks << " disks ... " << endl;
  for(int i = disks; i > 0; i--){
    // for(int i = 0; i < disks; i++){
    cout << "pushing i = " << i << endl;
    a.push_back(i);
  }
}// end default constructor

void Towers::move(unsigned char from, unsigned char to)
{
  vector<int>* f;
  switch(from) {
  case 'a' :
    f = &a;
    break;       // and exits the switch
  case 'b' :
    f = &b;
    break;
  case 'c' :
    f = &c;
    break;
  }
  vector<int>* t;
  switch(to) {
  case 'a' :
    t = &a;
    break;       // and exits the switch
  case 'b' :
    t = &b;
    break;
  case 'c' :
    t = &c;
    break;
  }
  int value = f->back();
  f->pop_back();
  cout << "moving " << value << " from " << from <<" to " << to << endl;
  t->push_back(value);
}
void Towers::print() // TODO this is ugly! there must be a recursive way 
{
  //for(int i = 0;  i < disks ; i++){ // from the top
  for(int i = disks - 1;  i >=0; i--){ // from the bottom
    int a_cur = (a.empty()?0:(i>a.size()?0:a.at(i)));
    int b_cur = (b.empty()?0:(i>b.size()?0:b.at(i)));
    int c_cur = (c.empty()?0:(i>c.size()?0:c.at(i)));
    // if j belongs to A [0..disks-1]
    for(int j = 0 ; j < disks * 3 + 2 ; j++){
      if ((j >= 0) && (j < disks)){ // A
        if (a_cur > 0){
          cout << "= ";
          a_cur--;
        } else {
          cout << "  "; // print space
        }
      }
      // if j belongs to B [disks..2*disks-1]
      else if ((j >= disks) && (j < 2*disks)){ // A
        if (b_cur > 0){
          cout << "= ";
          b_cur--;
        } else {
          cout << "  "; // print space
        }
      }
      // if j belongs to C [2*disks .. 3*disks -1]
      else if ((j >= 2*disks) && (j < 3*disks)){ // A
        if (c_cur > 0){
          cout << "= ";
          c_cur--;
        } else {
          cout << "  "; // print space
        }
      }
      else
        cout << "  "; // print space
    }
    cout << endl;
  }
  cout << endl;
};

void solveTowers(unsigned char disksLeft,
                 unsigned char src,
                 unsigned char dest,
                 unsigned char spare,
                 Towers* state){
  if (disksLeft == 1) {
    cout << "Moving a disk from " << src << " to "
         << dest << "." << endl;
    state->move(src, dest);
  } else {
    solveTowers(disksLeft - 1,src, spare, dest, state);
    solveTowers(1,src, dest, spare, state);
    solveTowers(disksLeft -1,spare, dest, src, state);
  }
}

void q1(){

  Towers for2 = Towers{2};
  for2.print();
  cout << "Solving for 2" << endl;
  solveTowers(2, 'a','b','c', &for2);
  for2.print();

  Towers for3 = Towers{3};
  for3.print();
  cout << "Solving for 3" << endl;
  solveTowers(3, 'a','b','c', &for3);
  for3.print();

  Towers for10 = Towers{10};
  for10.print();
  cout << "Solving for 10" << endl;
  solveTowers(10, 'a','b','c', &for10);
  for10.print();
}

int main(){
  q1();
}

