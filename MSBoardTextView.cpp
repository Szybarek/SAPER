#include <iostream>
#include "MSBoardTextView.h"

using namespace std;

//konstruktor
MSBoardTextView::MSBoardTextView(MinesweeperBoard& board) : displayableBoard(board)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
    state = board.getGameState();
}

void MSBoardTextView::display()
{
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {

            if (!displayableBoard.isRevealed(row,col))
            {
                if(displayableBoard.hasFlag(row, col))
                    cout << "[F]";
                else
                    cout << "[?]";
            }
            if (displayableBoard.hasMine(row, col) && displayableBoard.isRevealed(row,col))
            {
                cout << "[BOOM]";
                state = FINISHED_LOSS;
            }
            else if (displayableBoard.isRevealed(row, col) && !displayableBoard.hasMine(row,col))
            {
                if (displayableBoard.countMines(row, col) == 0)
                    cout << "[ ]";
                else
                    cout << "[" << displayableBoard.countMines(row, col) << "]";
            }
        }
        cout << endl;
    }
}


/*void MSBoardTextView::display()
{
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            cout << "[";
            if(displayableBoard.hasMine(row,col))
                cout << "";
            if(displayableBoard.isRevealed(row,col))
                cout << " ";
            else
                cout << "?";
            if(displayableBoard.hasFlag(row,col))
                cout << "F";
            else
                cout << "";
            cout << "]";
        }
        cout << endl;
    }
}

void MSBoardTextView::display()
{
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            cout << "[";
            if(displayableBoard.hasMine(row,col))
                cout << "";
            if(displayableBoard.isRevealed(row,col))
                cout << " ";
            else
                cout << "?";
            if(displayableBoard.hasFlag(row,col))
                cout << "F";
            else
                cout << "";
            cout << "]";
        }
        cout << endl;
    }
}

*/



