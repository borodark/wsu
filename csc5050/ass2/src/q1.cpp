/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver/test for Question 1 of Assignment 2
**/

#include <iostream>
#include <cassert>

using namespace std;
/*
  print the maze state
 */
void print_maze(const short* maze, const char walls, const char background, const char been, const int nrows, const int ncols ){
  for(int i = 0; i < nrows; i++){
    for(int j = 0; j < ncols; j++){
      short cell = *(maze + (i * nrows + j));
      // 0 - background
      // 1 - walls
      // 2 - been
      cout << ((cell == 0)?background:((cell == 1)?walls:been));
      //cout << cell;
    }
    cout << endl;
  }
  cout << endl;
}

void q1(){

  short maze[12][12] = 
    {     {1,1,1,1,1,1,1,1,0,1,1,1},
          {1,0,1,1,1,1,0,0,0,0,1,1},
          {2,0,0,1,1,1,0,1,1,0,1,1},
          {1,1,0,1,1,1,0,1,0,0,0,1},
          {1,0,0,0,1,1,0,1,1,1,0,1},
          {1,1,1,0,1,1,0,0,0,1,0,1},
          {1,0,0,0,1,0,1,1,0,1,1,1},
          {1,1,1,0,1,1,1,1,0,0,1,1},
          {1,0,1,0,0,0,1,1,1,0,1,1},
          {1,0,0,0,0,0,1,0,1,0,0,1},
          {1,0,1,0,0,0,0,0,0,0,1,1},
          {1,1,1,1,1,1,1,1,1,1,1,1}};

  cout << endl;
  cout << "+ q1 ++++++++++" << endl;
  cout << " Maze size: " << sizeof(maze) << " and " << sizeof(maze[1][1]) << endl;
  const short *mazePtr = &maze[0][0];
 
  print_maze(mazePtr, 'o',' ', '.', 12,12);

}

int main(){
  q1();

}

