enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

#ifndef MINESBOARD_H__
#define MINESBOARD_H__


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
    GameState status;
    bool BeforeFirstMove;

    MinesweeperBoard(int w, int h, GameMode mode, GameState s);
    int countMines(int col, int row) const;
    bool hasFlag(int col, int row) const;
    void debug_display() const;
    int getMineCount() const;
    void toggleFlag(int col, int row);
    void revealField(int col, int row);
    GameState getGameState();
};

#endif