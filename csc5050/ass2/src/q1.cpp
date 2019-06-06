/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   This is a driver/test for Question 1 of Assignment 2
**/

#include <iostream>
#include <cassert>

using namespace std;

const short PATH = 0;
const short WALL = 1;
const short BEEN = 2;

short* cellPtr(short* maze, const int row, const int col, const int row_len) {
  return maze + (row * row_len + col);
}

short cell(short* maze, const int row, const int col, const int row_len){
  short cell = *(cellPtr(maze,row,col,row_len));
  return cell;
}
/*
  return if the position in the maze is not the edge, or tried already, exit or entrance?
  0 notation
*/
bool valid_cell(short* maze, const int row, const int col, const int maxrows, const int maxcols ) {
  // within the outer walls or at exit
  if (row >= 0 && row < maxrows && col >= 0 && col < maxcols) {
    //  check if cell is not a wall = 1
    //  previously  tried = 2
    short value = cell(maze, row, col, maxcols);
    return !(value == WALL || value == BEEN); // wall or been
  } else {
    return 0;
  }
}


/*
  print the maze state
*/
void print_maze(short* maze, const char walls, const char background, const char been, const int nrows, const int ncols ){
  for(int i = 0; i < nrows; i++){
    for(int j = 0; j < ncols; j++){
      short cel = cell(maze, i, j, ncols);
      // 0 - background
      // 1 - walls
      // 2 - been
      cout << ((cel == 0)?background:((cel == 1)?walls:been));
    }
    cout << endl;
  }
  cout << endl;
}
/*
  traverse the array 
*/
bool solve(short* maze, const int row, const int col, const int maxrows, const int maxcols, int steps ) {
  bool done = 0;
  short* cellP = cellPtr(maze,row,col,maxcols);
  if (valid_cell(maze, row, col, maxrows, maxcols)){
    *cellP = BEEN; // this cell has been tried
    cout << " At  " << row << ":" << col <<endl;
    if (steps > 1 && ((row == 0 || col == 0 || row == maxrows-1 || col == maxcols-1) ||
                      ((row == 0 || col == 0 || row == maxrows-1 || col == maxcols-1)
                       && *cellP == BEEN)))
      // at exits with more then one step
      {  // the maze is solved
        //print_maze(maze, '0',' ', '.', maxrows, maxcols);

        done = 1;
      }
    else
      {
        done = solve(maze,row,col+1,maxrows, maxcols, steps++);  // right
        if (!done)
          done = solve(maze,row+1,col,maxrows, maxcols, steps++); // down

        if (!done)
          done = solve(maze,row-1,col,maxrows, maxcols, steps++); // up
        if (!done)
          done = solve(maze,row,col-1,maxrows, maxcols, steps++);   // left
      }
  }
  print_maze(maze, '0',' ', '.', maxrows, maxcols);
  // cout << " Steps is: " <<  steps << " Cell value:" << *cellP <<endl;
  //   printf("\nPress enter key to see next move\n"); //displays and asks user to see the next move on maze
  // getchar(); 

  return done;
}

void test(short *mazePtr)
{
  // cout << " Maze size: " << sizeof(maze) << " and " << sizeof(maze[1][1]) << endl;
  // tests
  cout << " The 0,0 is not valid cause it's the wall? " << valid_cell(mazePtr, 0, 0,12,12)<< endl;
  cout << " The 2,1 is valid cause it's the path? " << valid_cell(mazePtr, 2, 1,12,12)<< endl;
  cout << " The 1,1 is no valid cause it's been? " << valid_cell(mazePtr, 1, 1,12,12)<< endl;
  cout << " The 2,0 is no valid cause it's been? " << valid_cell(mazePtr, 2, 0,12,12)<< endl;
  cout << " The 9,11 is valid cause it' the exit? " << valid_cell(mazePtr,9,11,12,12) << endl;
  cout << " The 13,13 is no valid cause it's out of bounds? " << valid_cell(mazePtr,13,13,12,12)<< endl;
  cout << " The 0,13 is no valid cause it's out of bounds? " << valid_cell(mazePtr,0,13,12,12)<< endl;
  cout << " The 15,0 is no valid cause it's out of bounds? " << valid_cell(mazePtr,15,0,12,12)<< endl;
 
}

void test_print(short *mazePtr, int rows, int cols){
  print_maze(mazePtr, '0',' ', '.', rows, cols);
}


void q1(){
  // 0 - path
  // 1 - walls
  // 2 - to mark as been during execution
  short maze1[12][12] =
    {     {1,1,1,1,1,1,1,1,0,1,1,1},
          //               ^ entrence/exit 
          {1,0,1,1,1,1,0,0,0,0,1,1},
          {1,0,0,1,1,1,0,1,1,0,1,1},
          {1,1,0,1,1,1,0,1,0,0,0,1},
          {1,0,0,0,1,1,0,1,1,1,0,1},
          {1,1,1,0,1,1,0,0,0,1,0,1},
          {1,0,0,0,1,0,1,1,0,1,1,1},
          {1,1,1,0,1,1,1,1,0,0,1,1},
          {1,0,1,0,0,0,1,1,1,0,1,1},
          {1,0,0,0,0,0,1,0,1,0,0,0}, // <- exit/enter
          {1,0,1,0,0,0,0,0,0,0,1,1},
          {1,1,1,1,1,1,1,1,1,1,1,1}};

  short maze2[12][12] =
    {     {1,1,1,1,1,1,1,1,1,1,1,1},
          {1,0,1,1,1,1,0,0,0,0,1,1},
          {1,0,0,1,1,1,0,1,1,0,1,1},
          {1,1,0,1,1,1,0,1,0,0,0,1},
          {1,0,0,0,1,1,0,1,1,1,0,1},
          {1,1,1,0,1,1,0,0,0,1,0,1},
          {0,0,0,0,1,0,1,1,0,1,1,1},
       //  ^ <- exit/enter
          {1,1,1,0,1,1,1,1,0,0,1,1},
          {1,0,1,0,0,0,1,1,1,0,1,1},
          {1,0,0,0,0,0,1,0,1,0,0,0}, // <- exit/enter
          {1,0,1,0,0,0,0,0,0,0,1,1},
          {1,1,1,1,1,1,1,1,1,1,1,1}};

  short maze3[14][12] =
    {     {1,1,1,1,1,1,1,1,1,1,1,1},
          {1,0,1,1,1,1,0,0,0,0,1,1},
          {1,0,0,1,1,1,0,1,1,0,1,1},
          {1,1,0,1,1,1,0,1,0,0,0,1},
          {1,0,0,0,1,1,0,1,1,1,0,1},
          {1,1,1,0,1,1,0,0,0,1,0,1},
          {0,0,0,0,1,0,1,1,0,1,1,1},
          //  ^ <- exit/enter
          {1,1,1,0,1,1,1,1,0,0,1,1},
          {1,0,1,0,0,0,1,1,1,0,1,1},
          {1,0,0,0,0,0,1,0,1,0,0,0}, // <- exit/enter
          {1,0,1,0,0,0,0,0,0,0,1,1},
          {1,0,0,0,0,0,1,0,1,0,0,1},
          {1,0,1,0,1,0,1,0,0,0,1,1},
          {1,1,1,1,1,1,1,1,1,1,1,1}
    };

  short maze4[14][12] =
    {     {1,1,1,1,1,1,1,1,1,1,1,1},
          {1,0,1,1,1,1,0,0,0,0,1,1},
          {1,0,0,1,1,1,0,1,1,0,1,1},
          {1,1,0,1,1,1,0,1,0,0,0,1},
          {1,0,0,0,1,1,0,1,1,1,0,1},
          {1,1,1,0,1,1,0,0,0,1,0,1},
          {0,0,0,0,1,0,1,1,0,1,1,1},
          //  ^ <- exit/enter
          {1,1,1,0,1,1,1,1,0,0,1,1},
          {1,0,1,0,0,0,1,1,1,0,1,1},
          {1,0,0,0,0,0,1,0,1,0,0,1},
          {1,0,1,0,0,0,0,0,0,0,1,1},
          {1,0,0,0,0,0,1,0,1,0,0,1},
          {1,0,1,0,1,0,1,0,0,0,1,1},
          {1,1,1,1,1,1,1,1,1,1,1,1}
    };
  
  cout << endl;
  cout << "+ q1 ++++++++++" << endl;
  int   steps = 0;
  short *mazePtr1 = &maze1[0][0];
  cout  << endl << "The Maze 1:" << endl;
  test_print(mazePtr1,12,12);
  short *mazePtr2 = &maze2[0][0];
  cout  << endl << "The Maze 2:" << endl;
  test_print(mazePtr2,12,12);
  short *mazePtr3 = &maze3[0][0];
  cout  << endl << "The Maze 3:" << endl;
  test_print(mazePtr3,14,12);
  short *mazePtr4 = &maze4[0][0];
  cout  << endl << "The Maze 4:" << endl;
  test_print(mazePtr4,14,12);
  // enter at the right
  if (solve(mazePtr1, 9, 11, 12,12, steps)){
    cout << "The maze 1 has A solution" << endl;
  } else {
    cout << "The maze 1 has NO solution" << endl;
  }
  steps = 0;

  // enter on the left
  if (solve(mazePtr2, 6, 0, 12,12, steps)){
    cout << "The maze 2 has A solution" << endl;
  } else {
    cout << "The maze 2 has NO solution" << endl;
  }
  steps = 0;
  // MAZE 4
  // enter on the left
  if (solve(mazePtr3, 6, 0, 14,12, steps)){
    cout << "The maze 3 has solution" << endl;
  } else {
    cout << "The maze 3 has NO solution" << endl;
  }
  // MAZE 4
  steps = 0;
  // enter on the left
   if (solve(mazePtr4, 6, 0, 14, 12, steps)){
    cout << "The maze 4 has solution" << endl;
  } else {
    cout << "The maze 4 has NO solution" << endl;
  }


}
int main(){
  q1();

}

