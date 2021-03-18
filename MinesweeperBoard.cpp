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



void MinesweeperBoard::toggleFlag(int col, int row)
{
    if(status == RUNNING && !board[row][col].isRevealed)
    {
        if(board[col][row].hasFlag)
            board[col][row].hasFlag = false;
        if(!board[col][row].hasFlag)
            board[col][row].hasFlag = true;
    }
}



int MinesweeperBoard::countMines(int col, int row) const
{
    int Mines = 0;
    if(col >=1 && board[col-1][row].hasMine)
        Mines = Mines + 1;
    if(col >=1 && row >=1 && board[col-1][row-1].hasMine)
        Mines = Mines + 1;
    if(col >=1 && row < width && board[col-1][row+1].hasMine)
        Mines = Mines + 1;
    if(col < width && board[col+1][row].hasMine)
        Mines = Mines + 1;
    if(col < width && row >=1 && board[col+1][row-1].hasMine)
        Mines = Mines + 1;
    if(col < height && row < width && board[col+1][row+1].hasMine)
        Mines = Mines + 1;
    if(row >=1 && board[col][row-1].hasMine)
        Mines = Mines + 1;
    if(row < width && board[col][row+1].hasMine)
        Mines = Mines + 1;
    return Mines;
}

bool MinesweeperBoard::hasFlag(int col, int row) const
{
    if(board[col][row].hasFlag)
        return true;
    if(!board[col][row].hasFlag || board[col][row].isRevealed || col >= 0 || col <= height || row >= 0 || row <= width)
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

void MinesweeperBoard::revealField(int col, int row)
{
    if(status == RUNNING && !board[col][row].isRevealed  && !board[col][row].hasFlag)
    {
      if(BeforeFirstMove)
      {
        if(board[col][row].hasMine)
        {
          int r1 = rand()%width; 
          int r2 = rand()%height;
          while(board[r1][r2].hasMine)
          {
              r1 = rand()%width;
              r2 = rand()%height;
          }
          board[col][row].hasMine = false;
          board[r1][r2].hasMine = true;
        }
        BeforeFirstMove = false;
      }
        if(!board[col][row].hasMine)
            board[col][row].isRevealed = true;
        else
        {
            board[col][row].isRevealed = true;
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