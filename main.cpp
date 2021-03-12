#ifndef MINESBOARD_H__
#define MINESBOARD_H__
enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
#include <iostream>


using namespace std;

void intro()
{
  cout << "Hubert Baron" << endl;
}


struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;

public:
    MinesweeperBoard(int w, int h, GameMode mode);
    int countMines(int row, int col) const;  
    void debug_display() const;
    int getMineCount() const;
};


int MinesweeperBoard::countMines(int row, int col) const
{
  //trzeba napisac funkcje ktora sprawia ze nie mozna wyjsc poza border tablicy (inaczej program dla pól które graniczą z borderem podaje błędne wartości)
  int Mines = 0;
  if(board[row][col].hasMine || !board[row][col].hasMine || board[row][col].hasFlag || !board[row][col].hasFlag || board[row][col].isRevealed || !board[row][col].isRevealed)
  {
    if(board[row-1][col].hasMine)
    Mines = Mines + 1;
    if(board[row-1][col-1].hasMine)
    Mines = Mines + 1;
    if(board[row-1][col+1].hasMine)
    Mines = Mines + 1;
    if(board[row+1][col].hasMine)
    Mines = Mines + 1;
    if(board[row+1][col-1].hasMine)
    Mines = Mines + 1;
    if(board[row+1][col+1].hasMine)
    Mines = Mines + 1;
    if(board[row][col-1].hasMine)
    Mines = Mines + 1;
    if(board[row][col+1].hasMine)
    Mines = Mines + 1;
  }
 return Mines;
}


MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode) : height(h), width(w)
{
  if(mode == EASY) 
  {
    //tu bedzie kiedys instrukcja + wiecej trybow trudnosci
    for (int y = 0; y < height; y++) 
    {
      for (int x = 0; x < width; x++) 
      {
      board[1][1].hasMine = true;
      board[1][2].hasMine = true;
      board[1][0].hasMine = true;
      board[2][1].hasMine = true;
      }
    }
  }
}

void MinesweeperBoard::debug_display() const
{
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            cout << "[";
            if(board[x][y].hasMine)
                cout << "M";
            else
                cout << ".";
            if(board[x][y].isRevealed)
                cout << "o";
            else
                cout << ".";
            if(board[x][y].hasFlag)
                cout << "f";
            else
                cout << ".";
            cout << "]";
        }
        cout << endl;
    }
}



int main()
{
    MinesweeperBoard start(10, 10, EASY);
    //intro();
    start.debug_display();
    cout << start.countMines(1, 1);
}

#endif