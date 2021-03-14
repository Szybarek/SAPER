#ifndef MINESBOARD_H__
#define MINESBOARD_H__
enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
#include <iostream>
#include<ctime>


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
    int status;

public:
    MinesweeperBoard(int w, int h, GameMode mode);
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void debug_display() const;
    int getMineCount() const;
    void toggleFlag(int row, int col, GameState status);
    void revealField(int row, int col, GameState status);
    GameState getGameState() const;
};

void MinesweeperBoard::toggleFlag(int row, int col, GameState status)
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
    if(!board[row][col].hasFlag || board[row][col].isRevealed /* || + wyjscie poza tablice*/)
        return false;
    return 0;
}

MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode) : height(h), width(w)
{
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
        srand(time(NULL));
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

void MinesweeperBoard::revealField(int row, int col, GameState status)
{
    if(status == RUNNING && !board[row][col].isRevealed  && !board[row][col].hasFlag)
    {
        if(!board[row][col].hasMine)
            board[row][col].isRevealed = true;
        if(board[row][col].hasMine)
        {
            //-jezeli jest to pierwsza akcja gracza to mina zawsze znajduje sie w innym miejscu (dodac)
            board[row][col].isRevealed = true;
            status = FINISHED_LOSS;
        }
    }
}

GameState Minesweeper::getGameState()
{
    if(status == RUNNING)
    {
        if(status ==)
    }
}

int main()
{
    MinesweeperBoard start(10, 10, HARD);
    intro();

    start.toggleFlag(4, 4, RUNNING);
    cout << "Liczba min dookola tego pola: " << start.countMines(4, 4) << endl;
    cout << "Liczba flag na tym polu: " << start.hasFlag(4, 4) << endl;
    start.revealField(2, 2, RUNNING);
    start.debug_display();
    getGameState();
    {
        if(RUNNING)
        {

        }
    }
}

#endif

/*board[1][1].hasMine = true;
board[1][2].hasMine = true;
board[1][0].hasMine = true;
board[2][1].hasMine = true;
board[2][1].hasFlag = true;*/