#include <iostream>
#include "MinesweeperBoard.h"
#include<ctime>

using namespace std;


//konstruktor
MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode, GameState) : height(h), width(w), status(), BeforeFirstMove(true)
{
    status = RUNNING;
    {
        int MineAmount = height * width;
        if(mode == EASY)
        {
            MineAmount = MineAmount * (0.1);
        }
        if(mode == NORMAL)
        {
            MineAmount = MineAmount * (0.2);
        }
        if(mode == HARD)
        {
            MineAmount = MineAmount * (0.3);
        }
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {
                board[x][y].hasMine = false;
            }
        }
        for(int t = 0; t < MineAmount; t++)
        {
            int r1 = rand()%width;
            int r2 = rand()%height;
            while(board[r1][r2].hasMine)
            {
                r1 = rand()%width;
                r2 = rand()%height;
            }
            board[r1][r2].hasMine = true;
        }
    }
}



void MinesweeperBoard::toggleFlag(int row, int col)
{
    if(status == RUNNING && !board[row][col].isRevealed)
    {
        if(board[row][col].hasFlag)
            board[row][col].hasFlag = false;
        if(!board[row][col].hasFlag)
            board[row][col].hasFlag = true;
    }
}



int MinesweeperBoard::countMines(int row, int col) const
{
    int Mines = 0;
    if(row >=1 && board[row-1][col].hasMine)
        Mines = Mines + 1;
    if(row >=1 && col >=1 && board[row-1][col-1].hasMine)
        Mines = Mines + 1;
    if(row >=1 && col < width && board[row-1][col+1].hasMine)
        Mines = Mines + 1;
    if(row < width && board[row+1][col].hasMine)
        Mines = Mines + 1;
    if(row < width && col >=1 && board[row+1][col-1].hasMine)
        Mines = Mines + 1;
    if(row < height && col < width && board[row+1][col+1].hasMine)
        Mines = Mines + 1;
    if(col >=1 && board[row][col-1].hasMine)
        Mines = Mines + 1;
    if(col < width && board[row][col+1].hasMine)
        Mines = Mines + 1;
    return Mines;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if(board[row][col].hasFlag)
        return true;
    if(!board[row][col].hasFlag || board[row][col].isRevealed || col >= 0 || col <= height || row >= 0 || row <= width)
        return false;
    return 0;
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

void MinesweeperBoard::revealField(int row, int col)
{
    if(status == RUNNING && !board[row][col].isRevealed  && !board[row][col].hasFlag)
    {
      if(BeforeFirstMove)
      {
        if(board[row][col].hasMine)
        {
          int r1 = rand()%width; 
          int r2 = rand()%height;
          while(board[r1][r2].hasMine)
          {
              r1 = rand()%width;
              r2 = rand()%height;
          }
          board[row][col].hasMine = false;
          board[r1][r2].hasMine = true;
        }
        BeforeFirstMove = false;
      }
        if(!board[row][col].hasMine)
            board[row][col].isRevealed = true;
        else
        {
            board[row][col].isRevealed = true;
            status = FINISHED_LOSS;
        }
    }
}

//if(r2 >= 0 && r2 <= height && r1 >= 0 && r1 <= width) (w planszy)
//if(r2 < 0 && r2 > height && r1 < 0 && r1 > width) (poza plansza)

GameState MinesweeperBoard::getGameState()
{
    if(status == RUNNING)
    {
        cout << "STATUS GRY: W TRAKCIE";
    }
    if(status == FINISHED_LOSS)
    {
        cout << "STATUS GRY: PRZEGRANA";
    }
    if(status == FINISHED_WIN)
    {
        cout << "STATUS GRY: WYGRANA";
    }
    return status;
}

/*    if(row >=1 && board[row-1][col] || row >=1 && col >=1 && board[row-1][col-1] ||
    
       row >=1 && col < width && board[row-1][col+1] || row < width && board[row+1][col] ||
    
       row < width && col >=1 && board[row+1][col-1] ||row < height && col < width && board[row+1][col+1] ||
    
       col >=1 && board[row][col-1] || col < width && board[row][col+1])
    return true;*/