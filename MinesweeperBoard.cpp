#include <iostream>
#include "MinesweeperBoard.h"

using namespace std;


//konstruktor
MinesweeperBoard::MinesweeperBoard(int h, int w, GameMode mode) : height(h), width(w), state(), MineAmount(), BeforeFirstMove(true), board(w,h)
//done
{
    MineAmount = 0;
    state = RUNNING;
    {
        MineAmount = width * height;
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


void MinesweeperBoard::toggleFlag(int row, int col) //done
{
    if(state == RUNNING && !board[row][col].isRevealed)
    {
        if(board[row][col].hasFlag)
            board[row][col].hasFlag = false;
        if(!board[row][col].hasFlag)
            board[row][col].hasFlag = true;
    }
}


//do poprawienia, row < 0 || row > height || col < 0 || col > width
int MinesweeperBoard::countMines(int boardRow, int boardCol) const
{
    int Mines = 0;

    if (boardRow < 0 || boardRow > height || boardCol < 0 || boardCol > width ||
        !board[boardRow][boardCol].isRevealed)
        return -1;

    for (int row = -1; row <= 1; ++row)
    {
        for (int col = -1; col <= 1; ++col)
        {
            if (((boardRow + row) >= 0 && (boardRow + row) < height) &&
                ((boardCol + col) >= 0 && (boardCol + col) < width) &&
                board[boardRow + row][boardCol + col].hasMine)
                Mines++;
        }
    }
    return Mines;
}

bool MinesweeperBoard::hasFlag(int row, int col) const //done
{
    if(board[row][col].hasFlag)
        return true;
    //if(!board[row][col].hasFlag || board[row][col].isRevealed || row >= 0 || row <= height || col >= 0 || col <= width)
    else
        return false;
    return 0;
}

void MinesweeperBoard::debugDisplay() const //done
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

bool MinesweeperBoard::WinCondition() //done
{
    int safeField = 0;
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if(!board[row][col].hasMine && board[row][col].isRevealed)
                safeField++;
        }
    }
    if(safeField + MineAmount == width * height)
        return true;
    return false;
}

void MinesweeperBoard::revealField(int row, int col) //done
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
    if(WinCondition())
        state = FINISHED_WIN;
}


char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if (row < 0 || row > height || col < 0 || col > width)
        return '#';

    if (board[row][col].isRevealed && board[row][col].hasMine)
        return 'x';

    if (!board[row][col].isRevealed && board[row][col].hasFlag)
        return 'F';

    if (!board[row][col].isRevealed && !board[row][col].hasFlag)
        return '_';

    if (board[row][col].isRevealed)
        return '0' + countMines(row, col);
    return ' ';
}


void MinesweeperBoard::createDebugBoard() //done
{
    MineAmount = 0;
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            board[row][col].hasMine=false;
            if (row == col || row == 0 || (col == 0 && row % 2 == 0))
            {
                board[row][col].hasMine = true;
                MineAmount++;
            }
        }
    }
}


GameState MinesweeperBoard::getGameState() const //done
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

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if (board[row][col].isRevealed)
        return true;
    return false;
}

bool MinesweeperBoard::hasMine(int row, int col) const
{
    if (board[row][col].hasMine)
        return true;
    return false;
}

GameState MinesweeperBoard::showGameState() //additional
{
    if(state == RUNNING)
        cout << "W TRAKCIE " << endl;
    if(state == FINISHED_LOSS)
        cout << "PRZEGRANA " << endl;
    if(state == FINISHED_WIN)
        cout << "WYGRANA " << endl;
}

