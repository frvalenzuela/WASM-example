// A Backtracking program in
// C++ to solve Sudoku problem
#include <cstdint>
#include <cstddef>
#include <iostream>
#include <cstring>
#include <emscripten.h>
using namespace std;
 
// UNASSIGNED is used for empty
// cells in sudoku grid
#define UNASSIGNED 0
 
// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9
 
uint32_t **grid = NULL;

// This function finds an entry in grid
// that is still unassigned
bool FindUnassignedLocation(uint32_t **grid,
                            int& row, int& col);
 
// Checks whether it will be legal
// to assign num to the given row, col
bool isSafe(uint32_t **grid, int row,
            int col, int num);
 
/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
extern "C" {
  EMSCRIPTEN_KEEPALIVE
  bool SolveSudoku(uint32_t **grid)
  {
      int row, col;
  
      // If there is no unassigned location,
      // we are done
      if (!FindUnassignedLocation(grid, row, col))
          // success!
          return true;
  
      // Consider digits 1 to 9
      for (int num = 1; num <= 9; num++)
      {
          
          // Check if looks promising
          if (isSafe(grid, row, col, num))
          {
              
              // Make tentative assignment
              grid[row][col] = num;
  
              // Return, if success
              if (SolveSudoku(grid))
                  return true;
  
              // Failure, unmake & try again
              grid[row][col] = UNASSIGNED;
          }
      }
      
      // This triggers backtracking
      return false;
  }
}

 
/* Searches the grid to find an entry that is
still unassigned. If found, the reference
parameters row, col will be set the location
that is unassigned, and true is returned.
If no unassigned entries remain, false is returned. */
bool FindUnassignedLocation(uint32_t **grid,
                            int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
 
/* Returns a boolean which indicates whether
an assigned entry in the specified row matches
the given number. */
bool UsedInRow(uint32_t **grid, int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether
an assigned entry in the specified column
matches the given number. */
bool UsedInCol(uint32_t **grid, int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether
an assigned entry within the specified 3x3 box
matches the given number. */
bool UsedInBox(uint32_t **grid, int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] ==
                                       num)
                return true;
    return false;
}
 
/* Returns a boolean which indicates whether
it will be legal to assign num to the given
row, col location. */
bool isSafe(uint32_t **grid, int row,
            int col, int num)
{
    /* Check if 'num' is not already placed in
    current row, current column
    and current 3x3 box */
    return !UsedInRow(grid, row, num)
           && !UsedInCol(grid, col, num)
           && !UsedInBox(grid, row - row % 3,
                         col - col % 3, num)
           && grid[row][col] == UNASSIGNED;
}
 
/* A utility function to print grid */
void printGrid(uint32_t **grid)
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}
 
// Driver Code
int main()
{
	uint32_t **grid = (uint32_t**)calloc(N, sizeof(*grid));
	for(int i = 0; i < N; i++)
		grid[i] = (uint32_t*)calloc(N, sizeof(*grid[i]));

	grid[0][0] = 1;
	grid[0][4] = 9;
    if (SolveSudoku(grid) == true)
        printGrid(grid);
    else
        cout << "No solution exists";
 
    return 0;
}
 
// This is code is contributed by rathbhupendra