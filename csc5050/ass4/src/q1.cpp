/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass4/src/q1.cpp
   This is a driver/test for Question 1 of Assignment 4
   The program is compiles and run correctly. Produces the correct results.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;
//show the movement of the disks
void printMove(char fromPeg, char toPeg, int disk) {
  cout << " Move the disk " << disk << " from " << fromPeg << " to " <<  toPeg << endl;
}

void moveDisksBetweenTwoPoles(stack<int>* src,
                              stack<int>* dest,
                              char s,
                              char d){
  int srcTopDisk = (src->size()>0)?src->top():0;
  if(srcTopDisk>0)
    src->pop();
  int destTopDisk = (dest->size()>0)?dest->top():0;
  if (destTopDisk > 0) // check if the 
    dest->pop();
  // When src is empty
  if (srcTopDisk == 0) {
    src->push(destTopDisk);
    printMove(d, s, destTopDisk);
  }
  // When dest pole is empty
  else if (destTopDisk == 0){
    dest->push(srcTopDisk);
    printMove(s, d, srcTopDisk);
  }
  // When top disk of src > top disk of dest
  else if (srcTopDisk > destTopDisk) {
    src->push(srcTopDisk);
    src->push(destTopDisk);
    printMove(d, s, destTopDisk);
  }
  // When top disk of src < top disk of dest
  else
    {
      dest->push(destTopDisk);
      dest->push(srcTopDisk);
      printMove(s, d, srcTopDisk);
    }
}

//
void solveTowers(int disks,
                    stack<int>* src, stack<int>* dest, stack<int>* spare){

  int i, total_moves = pow(2, disks) - 1;
  char s = 'a', d = 'b', sp = 'c';
  cout << " total moves: " << total_moves << endl;
  //If number of disks is even, then interchange
  //destination pole and spare pole
  if (disks % 2 == 0) {
    char temp = d;
    d = sp;
    sp = temp;
  }
  for (i = 1; i <= total_moves; i++) {
    if (i % 3 == 1)
      moveDisksBetweenTwoPoles(src, dest, s, d);
    else if (i % 3 == 2)
      moveDisksBetweenTwoPoles(src, spare, s, sp);
    else if (i % 3 == 0)
      moveDisksBetweenTwoPoles(spare, dest, sp, d);
  }
}

/** state */
class Towers {
private:

public:
  Towers(int disks);
  int disks;
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
    break;
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
    break;
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
  //this->print();
}
void Towers::print()
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
  const int a_pos = disks/2;
  const int b_pos = a_pos + disks;
  const int c_pos = b_pos + disks ;
  for(int j = 0 ; j < disks * 3 ; j++){
    if(j == a_pos){
      cout << "A-";
    }
    else if(j == b_pos){
      cout << "B-";
    }
    else if(j == c_pos){
      cout << "C-";
    }
    else
      cout << "--";
  }
  cout << endl;

};

void solve(unsigned char disksLeft,
                 unsigned char src,
                 unsigned char dest,
                 unsigned char spare,
                 Towers* state){
  if (disksLeft == 1) {
    // cout << "Moving a disk from " << src << " to " << dest << "." << endl;
    state->move(src, dest);
    // state->print();
  } else {
    solve(disksLeft - 1,src, spare, dest, state);
    solve(1,src, dest, spare, state);
    solve(disksLeft -1,spare, dest, src, state);
  }
}

void q1_recursive(){

  Towers for2 = Towers{2};
  for2.print();
  cout << "Solving for 2" << endl;
  solve(for2.disks, 'a','b','c', &for2);
  for2.print();

  Towers for3 = Towers{3};
  for3.print();
  cout << "Solving for 3" << endl;
  solve(for3.disks, 'a','b','c', &for3);
  for3.print();

  Towers for10 = Towers{10};
  for10.print();
  cout << "Solving for 10" << endl;
  solve(for10.disks, 'a','b','c', &for10);
  for10.print();
}

stack<int>* populate(int disks){
  stack<int>* a =  new stack<int>;
  cout << "pushing "<< disks << " disks ... " << endl;
  for(int i = disks; i > 0; i--){
    cout << "pushing i = " << i << endl;
    a->push(i);
  }
  return a;
}

void q1_iter2(){
  stack<int>* a = populate(2);
  stack<int>* b = new stack<int>;
  stack<int>* c = new stack<int>;
  cout << "Solving for 2" << endl;
  solveTowers(2, a, b, c);
  cout << "Done!!!" << endl;
  cout << "a size " << a->size() << endl;
  cout << "2 is even the destination is c" << endl;
  cout << "b size " << b->size() << endl;
  cout << "c size " << c->size() << endl;
  cout << "printing c " << endl;
  for(int i = c->size(); i>0 ; i-- ){
    cout << c->top() << endl;
    c->pop();
  }
}
void q1_iter10(){
  stack<int>* a = populate(10);
  stack<int>* b = new stack<int>;
  stack<int>* c = new stack<int>;
  cout << "Solving for 10" << endl;
  solveTowers(10, a, b, c);
  cout << "Done!!!" << endl;
  cout << "a size " << a->size() << endl;
  cout << "10 is even the destination is c" << endl;
  cout << "b size " << b->size() << endl;
  cout << "c size " << c->size() << endl;
  cout << "printing c " << endl;
  for(int i = c->size(); i>0 ; i-- ){
    cout << c->top() << endl;
    c->pop();
  }
}

void q1_iter3(){
  stack<int>* a = populate(3);
  stack<int>* b = new stack<int>;
  stack<int>* c = new stack<int>;
  cout << "Solving for 3" << endl;
  solveTowers(3, a, b, c);
  cout << "Done!!!" << endl;
  cout << "a size " << a->size() << endl;
  cout << "b size " << b->size() << endl;
  cout << "c size " << c->size() << endl;
  cout << "printing b " << endl;
  for(int i = b->size(); i>0 ; i-- ){
    cout << b->top() << endl;
    b->pop();
  }
}


int main(){
  q1_recursive();
  q1_iter2();
  q1_iter3();
  q1_iter10();
}

