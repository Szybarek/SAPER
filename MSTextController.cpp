#include<iostream>
#include "MSTextController.h"

using namespace std;

MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view) : debugBoard(board), playerBoard(view)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
}

void MSTextController::play()
{

        cout<< endl;
        cout << "debug view" << endl; //do testow
        debugBoard.debugDisplay(); //do testow
        cout << endl;
        cout << "user view" << endl;
        playerBoard.display();
        cout << endl;
        cout << "STATUS GRY: " << debugBoard.showGameState();
        //gra sie skonczyla
       /* if(debugBoard.getGameState() != RUNNING)
        {
            break;
        }*/
        char choice;
        int row;
        int col;
        cout << endl;
        cout << "Co chcesz zrobic? Flaga (f), odsloniecie pola (r)" << endl;
        cin >> choice;
        //flaga
        if(choice == 'f')
        {
            cout << "Podaj rzad oraz kolumne na ktorych chcesz postawic flage, (koordynaty maja byc rozdzielone spacja)" << endl;
            cin >> row >> col;
            debugBoard.toggleFlag(row, col);
        }
        //reveal
        if(choice == 'r')
        {
            cout << "Podaj rzad oraz kolumne pola ktore chcesz odslonic, (koordynaty maja byc rozdzielone spacja)" << endl;
            cin >> row >> col;
            debugBoard.revealField(row, col);
        }
  }


