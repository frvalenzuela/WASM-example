
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Stores the number of rows
// and columns of the matrix
int N, M;
 
// Stores the final generated input
int arr[100][100];
 
// Direction arrays
int dx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dy[9] = { 0, 0, 0, -1, -1, -1, 1, 1, 1 };
 
// Function to check if the
// cell location is valid
bool isValid(int x, int y)
{
    // Returns true if valid
    return (x >= 0 && y >= 0
            && x < N && y < M);
}
 
// Function to generate a valid minesweeper
// matrix of size ROW * COL with P being
// the probability of a cell being a mine
void generateMineField(int ROW, int COL, int P)
{
    // Generates the random
    // number every time
    srand(time(NULL));
 
    int rand_val;
 
    // Stores whether a cell
    // contains a mine or not
    int mines[ROW][COL];
 
    // Iterate through each cell
    // of the matrix mine
    for (int x = 0; x < ROW; x++) {
        for (int y = 0; y < COL; y++) {
            // Generate a random value
            // from the range [0, 100]
            rand_val = rand() % 100;
 
            // If rand_val is less than P
            if (rand_val < P)
 
                // MArk mines[x][y] as True
                mines[x][y] = true;
 
            // Otherwise, mark
            // mines[x][y] as False
            else
                mines[x][y] = false;
        }
    }
 
    cout << "Generated Input:\n";
 
    // Iterate through each cell (x, y)
    for (int x = 0; x < ROW; x++) {
        for (int y = 0; y < COL; y++) {
            arr[x][y] = 0;
 
            // Count the number of mines
            // around the cell (x, y)
            // and store in arr[x][y]
            for (int k = 0; k < 9; k++) {
                // If current adjacent cell is valid
                if (isValid(x + dx[k], y + dy[k])
                    && (mines[x + dx[k]][y + dy[k]]))
                    arr[x][y]++;
            }
 
            // Print the value at
            // the current cell
            cout << arr[x][y] << " ";
        }
        cout << endl;
    }
}
 
// Driver Code
int main()
{
    N = 7, M = 7;
    int P = 20;
 
    // Function call to generate
    // a valid minesweeper matrix
    generateMineField(N, M, 15);
}