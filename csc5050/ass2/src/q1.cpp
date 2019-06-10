/**
   @author: Igor Ostaptchenko igor_ost@wayne.edu AKA borodark@gmail.com
   @src https://github.com/borodark/wsu/blob/master/csc5050/ass2/src/q1.cpp
   This is a driver/test for Question 1 of Assignment 2
   The program is compiles and run correctly. Produces the correct results.
   Works for any size and dimentions of maze: 12 X 12 and 14 X 12 are used in this code.
   The Mazes 1, 2 and 3 has solutions.
   The Maze 4 has no solution.
   The MazePro is the one from assign
**/

#include <iostream>
#include <cassert>

using namespace std;
/*
 * constants to form array and mark state.
 */
const unsigned char PATH = 0;
const unsigned char WALL = 1;
const unsigned char BEEN = 2;
/**
 * Calculate pointer to array element given an array pointer, row and column index and array dimentions.
 *
 * @param maze - pointer to the array head
 * @param row - index in dimention 1
 * @param col - index in dimention 2
 * @param row_len - array size - first dimention.
 * @return a pointer to array element
 */
unsigned char* cellPtr(unsigned char* maze, const int row, const int col, const int row_len) {
  return maze + (row * row_len + col);
}
/**
 * Return the value of the array element given an array pointer,
 * row and column index and array dimentions.
 *
 * @param maze - pointer to the array head
 * @param row - index in dimention 1
 * @param col - index in dimention 2
 * @param row_len - array size - first dimention.
 * @return a value of the array element
 */

unsigned char cell(unsigned char* maze, const int row, const int col, const int row_len){
  unsigned char cell = *(cellPtr(maze,row,col,row_len));
  return cell;
}
/*
  return if the position in the maze is not the edge, or tried already.
  0 notation
*/
bool valid_cell(unsigned char* maze, const int row, const int col, const int maxrows, const int maxcols ) {
  // within the outer walls or at exit
  if (row >= 0 && row < maxrows && col >= 0 && col < maxcols) {
    //  check if cell is not a wall = 1
    //  previously  tried = 2
    unsigned char value = cell(maze, row, col, maxcols);
    return !(value == WALL || value == BEEN); // wall or been
  } else {
    return 0;
  }
}


/*
  print the maze state
*/
void print_maze(unsigned char* maze, const char walls, const char background, const char been, const int nrows, const int ncols ){
  for(int i = 0; i < nrows; i++){
    for(int j = 0; j < ncols; j++){
      unsigned char cel = cell(maze, i, j, ncols);
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
  traverse the array, modifies values, mark seen spots with `unsigned char` of value 2.
  * @param maze - pointer to the array head
  * @param row - index in dimention 1
  * @param col - index in dimention 2
  * @param maxrows - array size - first dimention.
  * @param maxcols - array size - second dimention.
  * @param steps - to track recursion depth and treat the special way the start point, that is the edge of maze
*/
bool solve(unsigned char* maze, const int row, const int col, const int maxrows, const int maxcols, int steps ) {
  bool done = 0;
  unsigned char* cellP = cellPtr(maze,row,col,maxcols);
  if (valid_cell(maze, row, col, maxrows, maxcols)){
    *cellP = BEEN; // this cell has been tried
    cout << " At  " << row << ":" << col <<endl;
    if (steps > 1 && ((row == 0 || col == 0 || row == maxrows-1 || col == maxcols-1) ||
                      ((row == 0 || col == 0 || row == maxrows-1 || col == maxcols-1)
                       && *cellP == BEEN)))
      // at exits with more then one step
      {  // the maze is solved or we hit the wall or we had been here
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
  // print_maze(maze, '#',' ', '.', maxrows, maxcols);
  // cout << " Steps is: " <<  steps << " Cell value:" << *cellP <<endl;
  //   printf("\nPress enter key to see next move\n"); //displays and asks user to see the next move on maze
  // getchar(); 
  return done;
}

void test(unsigned char *mazePtr)
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

void test_print(unsigned char *mazePtr, int rows, int cols){
  print_maze(mazePtr, '#',' ', '.', rows, cols);
  //cout << " maze cell value size: " << sizeof((&mazePtr)[0][0])  << endl;
}


void q1(){
  // 0 - path
  // 1 - walls
  // 2 - to mark as been during execution
  unsigned char maze1[12][12] =
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

  unsigned char maze2[12][12] =
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

  unsigned char maze3[14][12] =
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

  unsigned char maze4[14][12] =
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
  unsigned char mazePro1[12][12] =
    {     {1,1,1,1,1,1,1,1,1,1,1,1},
          {1,0,0,0,0,0,0,1,0,0,0,1},
          {1,1,1,1,1,1,0,1,1,1,0,1},
          {1,0,0,0,0,0,0,0,0,1,0,1},
          {1,1,0,1,0,1,0,1,0,1,0,1},
          {1,0,0,1,0,1,0,1,0,1,0,1},
          {1,1,1,1,0,1,0,1,0,1,0,1},
          {1,0,0,0,0,1,1,1,0,1,0,0},// <- exit/enter
          {1,1,1,0,1,0,0,0,0,1,0,1}, 
          {0,0,1,0,1,0,1,1,1,1,0,1},
          //^ <- exit/enter
          {1,0,0,0,1,0,0,0,0,0,0,1},
          {1,1,1,1,1,1,1,1,1,1,1,1}};

  unsigned char mazePro2[12][12] =
    {     {1,1,1,1,1,1,1,1,1,1,1,1},
          {1,0,0,0,0,0,0,1,0,0,0,1},
          {1,1,1,1,1,1,0,1,1,1,0,1},
          {1,0,0,0,0,0,0,0,0,1,0,1},
          {1,1,0,1,0,1,0,1,0,1,0,1},
          {1,0,0,1,0,1,0,1,0,1,0,1},
          {1,1,1,1,0,1,0,1,0,1,0,1},
          {1,0,0,0,0,1,1,1,0,1,0,0},// <- exit/enter
          {1,1,1,0,1,0,0,0,0,1,0,1},
          {0,0,1,0,1,0,1,1,1,1,0,1},
          //^ <- exit/enter
          {1,0,0,0,1,0,0,0,0,0,0,1},
          {1,1,1,1,1,1,1,1,1,1,1,1}};


  cout << endl;
  cout << "+ q1 ++++++++++" << endl;
  int   steps = 0;
  unsigned char *mazePtr1 = &maze1[0][0];
  cout  << endl << "The Maze 1 size:"  << sizeof(maze1) << endl;
  test_print(mazePtr1,12,12);
  unsigned char *mazePtr2 = &maze2[0][0];
  cout  << endl << "The Maze 2 size:"  << sizeof(maze2) << endl;
  test_print(mazePtr2,12,12);
  unsigned char *mazePtr3 = &maze3[0][0];
  cout << endl << "The Maze 3 size:"  << sizeof(maze3) << endl;
  test_print(mazePtr3,14,12);
  unsigned char *mazePtr4 = &maze4[0][0];
  cout << endl << "The Maze 4 size:"  << sizeof(maze4) << endl;
  test_print(mazePtr4,14,12);
  // enter at the right
  if (solve(mazePtr1, 9, 11, 12,12, steps)){
    cout << "The maze 1 has A solution" << endl;
  } else {
    cout << "The maze 1 has NO solution" << endl;
  }
  test_print(mazePtr1,12,12);
  steps = 0;

  // enter on the left
  if (solve(mazePtr2, 6, 0, 12,12, steps)){
    cout << "The maze 2 has A solution" << endl;
  } else {
    cout << "The maze 2 has NO solution" << endl;
  }
  test_print(mazePtr2,12,12);
  steps = 0;
  // MAZE 4
  // enter on the left
  if (solve(mazePtr3, 6, 0, 14,12, steps)){
    cout << "The maze 3 has A solution" << endl;
  } else {
    cout << "The maze 3 has NO solution" << endl;
  }
  test_print(mazePtr3,14,12);

  // MAZE 4
  steps = 0;
  // enter on the left
  if (solve(mazePtr4, 6, 0, 14, 12, steps)){
    cout << "The maze 4 has A solution" << endl;
  } else {
    cout << "The maze 4 has NO solution" << endl;
  }
  test_print(mazePtr4,14,12);

  unsigned char *mazePtrP1 = &mazePro1[0][0];
  cout << endl << "The Maze PRO 1 size:"  << sizeof(mazePro1) << endl;
  test_print(mazePtrP1,12,12);
  if (solve(mazePtrP1, 9, 0, 12, 12, steps)){
    cout << "The maze PRO has A solution entering from the left" << endl;
  } else {
    cout << "The maze PRO has NO solution entering from the left" << endl;
  }
  test_print(mazePtrP1,12,12);


  // enter from the right
  unsigned char *mazePtrP2 = &mazePro2[0][0];
  cout << endl << "The Maze PRO 2 size:"  << sizeof(mazePro2) << endl;
  test_print(mazePtrP2,12,12);
  if (solve(mazePtrP2, 7, 11, 12, 12, steps)){
    cout << "The maze PRO has A solution entering from the right" << endl;
  } else {
    cout << "The maze PRO has NO solution entering from the right" << endl;
  }
  test_print(mazePtrP2,12,12);

}
int main(){
  q1();

}

