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
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void debug_display() const;
    int getMineCount() const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    GameState getGameState();
};

#endif