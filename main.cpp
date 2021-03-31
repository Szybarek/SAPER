#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

using namespace std;

int main()
{
    srand(1);
    cout << "Hubert Baron" << endl;
    cout << endl;

    //zmiana mapy
    //srand(time(NULL));

    //konstruktor
    MinesweeperBoard board(3, 3, NORMAL);
    MSBoardTextView view(board);
    MSTextController ctrl(board, view);
    //cout << "informacja o polu: " << board.getFieldInfo(0, 0) << endl;
    //cout << "STATUS GRY: " << board.showGameState();
    cout << endl; 
    //wyswietlenie tablicy dla uzytkownika
    //view.display();
    ctrl.play();
    

    //status gry
    //cout << "STATUS GRY: " << board.showGameState() <<endl;
    //cout << "ilosc min dookola danego pola (0,0): " << board.countMines(0, 0) << endl;
    //cout << "czy na tym polu jest flaga?: " << board.hasFlag(0, 1) << endl;
    
}

