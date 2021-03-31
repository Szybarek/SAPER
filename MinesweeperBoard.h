#ifndef MINESBOARD_H__
#define MINESBOARD_H__

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

#include "Array2D.h"

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
    //Field board[100][100];
    Array2D<Field> board;
    int width;
    int height;
    GameState state;
    bool BeforeFirstMove;
    int MineAmount;

public:
    bool hasMine(int row, int col) const; //d
    bool isRevealed(int row, int col) const; //d
    MinesweeperBoard(int w, int h, GameMode mode); //d
    bool hasFlag(int row, int col) const; //d
    void debugDisplay() const; //d
    int countMines(int row, int col) const; //d
    void toggleFlag(int row, int col); //d
    void revealField(int row, int col); //d
    char getFieldInfo(int row, int col) const; //d
    GameState getGameState() const; //nd
    GameState showGameState(); //d
    int getBoardWidth() const; //d
    int getBoardHeight() const; //d
    int getMineCount() const; //d
    void createDebugBoard(); //d
    bool WinCondition(); //d
};

#endif