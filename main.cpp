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

    void debug_display() const;
};



MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode) : height(h), width(w)
{
    if(mode == EASY) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                board[x][y].hasMine = false;
                board[x][y].hasFlag = false;
                board[x][y].isRevealed = false;
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
    MinesweeperBoard start(10,20,EASY);
    intro();
    start.debug_display();
    cout << endl;
    return 0;
}

#endif