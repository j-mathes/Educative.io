#include <iostream>
using namespace std;

void printBoard(int** board, int x, int y) 
{
  for (int i = 0; i < x; i++) 
  { 
    for (int j = 0; j < y; j++) 
    { 
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

void makeBoard(int x, int y) 
{
  int** board;
  board = new int* [x];

  for (int i = 0; i < x; i++) 
  {
    board[i] = new int[y];
  }

  for (int i = 0; i < x; i++) 
  { 
    for (int j = 0; j < y; j++) 
    { 
      board[i][j] = 1;
    }
  }

  printBoard(board, x, y);
}
