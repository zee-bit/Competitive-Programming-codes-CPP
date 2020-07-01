//--------------------------------------------------
//Placing Queens column-wise
//--------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;
#define N 4

void printBoard(int board[N][N]) {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) 
         cout << board[i][j] << " ";
      cout<<"\n";
   }
   cout<<"\n";
}

bool isValid(int board[N][N], int row, int col) {
   for (int i = 0; i < col; i++) //check whether there is queen in the left or not
      if (board[row][i])
         return false;
   for (int i=row, j=col; i>=0 && j>=0; i--, j--)
      if (board[i][j]) //check whether there is queen in the left upper diagonal or not
         return false;
   for (int i=row, j=col; j>=0 && i<N; i++, j--)
      if (board[i][j]) //check whether there is queen in the left lower diagonal or not
         return false;
   return true;
}

bool solveNQueen(int board[N][N], int col) {
   if (col == N) { //when N queens are placed successfully
      printBoard(board);
      return true;
   }
   for (int i = 0; i < N; i++) { //for each row, check placing of queen is possible or not
      if (isValid(board, i, col) ) {
         board[i][col] = 1; //if validate, place the queen at place (i, col)
         if ( solveNQueen(board, col + 1)) //Go for the other columns recursively
            return true;
         board[i][col] = 0; //When no place is vacant remove that queen
      }
   }
   return false; //when no possible order is found
}

void checkSolution() {
   int board[N][N];
   memset(board, 0, sizeof(board));

   if ( solveNQueen(board, 0) == false ) { //starting from 0th column
      cout << "Solution does not exist";
      return ;
   }
   return ;
}

int main() {
   checkSolution();
   return 0;
}

//-------------------------------------------------
//Placing Queens Row-wise
//-------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;

// N x N chessboard
#define N 8

// Function to check if two queens threaten each other or not
bool isSafe(char mat[][N], int r, int c)
{
   // return false if two queens share the same column
   for (int i = 0; i < r; i++)
      if (mat[i][c] == 'Q')
         return false;

   // return false if two queens share the same \ diagonal
   for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
      if (mat[i][j] == 'Q')
         return false;

   // return false if two queens share the same / diagonal
   for (int i = r, j = c; i >= 0 && j < N; i--, j++)
      if (mat[i][j] == 'Q')
         return false;

   return true;
}

void nQueen(char mat[][N], int r)
{
   // if N queens are placed successfully, print the solution
   if (r == N)
   {
      for (int i = 0; i < N; i++) 
      {
         for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
         cout << endl;
      }
      cout << endl;
      
      return;
   }

   // place Queen at every square in current row r
   // and recur for each valid movement   
   for (int i = 0; i < N; i++) 
   {
      // if no two queens threaten each other
      if (isSafe(mat, r, i)) 
      {
         // place queen on current square
         mat[r][i] = 'Q';

         // recur for next row
         nQueen(mat, r + 1);

         // backtrack and remove queen from current square
         mat[r][i] = '-';
      }
   }
}

int main()
{
   // mat[][] keeps track of position of Queens in current configuration
   char mat[N][N];

   // initalize mat[][] by '-'
   memset(mat, '-', sizeof mat);

   nQueen(mat, 0);

   return 0;
}