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
  void print();
};
Towers::Towers(int ofDisks) : disks(ofDisks)
{
  for(int i = 0; i < disks; i++){
    cout << "pushing i = " << i+1 << endl;
    a.push_back(i+1);
  }
  for(int i = 0; i < disks; i++){
    cout << "pushing i = " << disks - i << endl;
    c.push_back(disks-(i));
  }

}// end default constructor
void Towers::print()
{
  for(int i = 0; i < disks ; i++){ // from the top
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
        // cout << "+ "; // TODO print B
        if (b_cur > 0){
          cout << "= ";
          b_cur--;
        } else {
          cout << "  "; // print space
        }
      }
      // if j belongs to C [2*disks .. 3*disks -1]
      else if ((j >= 2*disks) && (j < 3*disks)){ // A
        // cout << "- "; //TODO print C
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
                 unsigned char spare ){
  if (disksLeft == 1) {
    cout << "Moving a disk from " << src << " to "
         << dest << "." << endl;
  } else {
    solveTowers(disksLeft - 1,src, spare, dest);
    solveTowers(1,src, dest, spare);
    solveTowers(disksLeft -1,spare, dest, src);
  }
}





void q1(){
  Towers for2 = Towers{2};
  cout << "for2 has "<< for2.a.at(0) << " at the top"<< endl;
  for2.print();
  cout << "Solving for 2" << endl;
  solveTowers(2, 'A','B','C');

  Towers for10 = Towers{10};
  cout << "for10 has "<< for10.a.at(0) << " at the top"<< endl;
  for10.print();
  cout << "Solving for 3" << endl;
  solveTowers(3, 'A','B','C');
}

int main(){
  q1();
}

