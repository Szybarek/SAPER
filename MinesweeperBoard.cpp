#include <iostream>
#include "MinesweeperBoard.h"
#include<ctime>

using namespace std;


//konstruktor
MinesweeperBoard::MinesweeperBoard(int h, int w, GameMode mode) : height(h), width(w), state(), MineAmount(), BeforeFirstMove(true)
{  
    MineAmount = 0;
    state = RUNNING;
    {
        int MineAmount = width * height;
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
        for(int x = 0; x < height; x++)
        {
            for(int y = 0; y < width; y++)
            {
                board[x][y].hasMine = false;
            }
        }
        for(int t = 0; t < MineAmount; t++)
        {
            int r1 = rand()%height;
            int r2 = rand()%width;
            while(board[r1][r2].hasMine)
            {
                r1 = rand()%height;
                r2 = rand()%width;
            }
            board[r1][r2].hasMine = true;
        }
    }
            if(mode == DEBUG)
        {
            createDebugBoard();
        }
}
 


void MinesweeperBoard::toggleFlag(int row, int col)
{
    if(state == RUNNING && !board[row][col].isRevealed)
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
    if(row >=1 && col < height && board[row-1][col+1].hasMine)
        Mines = Mines + 1;
    if(row < height && board[row+1][col].hasMine)
        Mines = Mines + 1;
    if(row < height && col >=1 && board[row+1][col-1].hasMine)
        Mines = Mines + 1;
    if(row < width && col < height && board[row+1][col+1].hasMine)
        Mines = Mines + 1;
    if(col >=1 && board[row][col-1].hasMine)
        Mines = Mines + 1;
    if(row < height && board[row][col+1].hasMine)
        Mines = Mines + 1;
    return Mines;
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if(board[row][col].hasFlag)
        return true;
    if(!board[row][col].hasFlag || board[row][col].isRevealed || row >= 0 || row <= height || col >= 0 || col <= width)
        return false;
    return 0;
}

void MinesweeperBoard::debugDisplay() const
{
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            cout << "[";
            if(board[row][col].hasMine)
                cout << "M";
            else
                cout << ".";
            if(board[row][col].isRevealed)
                cout << "o";
            else
                cout << ".";
            if(board[row][col].hasFlag)
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
    if(state == RUNNING && !board[row][col].isRevealed  && !board[row][col].hasFlag)
    {
        if(BeforeFirstMove)
        {
            if(board[row][col].hasMine)
            {
                int r1 = rand()%height;
                int r2 = rand()%width;
                while(board[r1][r2].hasMine)
                {
                    r1 = rand()%height;
                    r2 = rand()%width;
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
            state = FINISHED_LOSS;
        }
    }
    //+ warunek na wygrana
}


bool MinesweeperBoard::getFieldInfo(int row, int col)  const
{
    if(row < 0 || row > height || col < 0 || col > width)
    {
        return '#';
    }
    if(!board[row][col].isRevealed && board[row][col].hasFlag)
    {
        return 'F';
    }
    if(!board[row][col].isRevealed && !board[row][col].hasFlag)
    {
        return '_';
    }
    if(board[row][col].isRevealed && board[row][col].hasMine)
    {
        return 'x';
    }
    /*if(getMineCount == 0)
    {
        return ' ';
    }
*/
  return 0;
}

void MinesweeperBoard::createDebugBoard()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
        board[col][row].hasMine=false;
            if (row == col || row == 0 || (col == 0 && row % 2 == 0))
                board[col][row].hasMine = true;
        }
    }
    //+
}


GameState MinesweeperBoard::getGameState() const
{
    return state;
}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getMineCount() const
{
return MineAmount;
}




GameState MinesweeperBoard::showGameState()
{
    if(state == RUNNING)
    {
        cout << "W TRAKCIE " << endl;
    }
    if(state == FINISHED_LOSS)
    {
        cout << "PRZEGRANA " << endl;
    }
    if(state == FINISHED_WIN)
    {
        cout << "WYGRANA " << endl;
    }
    return state;
}

