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
    GameState state;
    bool BeforeFirstMove;
    int MineAmount;

public:
    MinesweeperBoard(int w, int h, GameMode mode);
    bool hasFlag(int row, int col) const;
    void debugDisplay() const;
    int countMines(int row, int col) const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    bool getFieldInfo(int row, int col) const;
    GameState getGameState() const;
    GameState showGameState();
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    void createDebugBoard();
};

#endif