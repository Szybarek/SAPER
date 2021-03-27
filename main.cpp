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
    MinesweeperBoard board(3, 3, HARD);
    MSBoardTextView view(board);
    MSTextController ctrl(board, view);
    //odsłonięcie danego pola
    /*board.revealField(0, 0);
    board.revealField(1, 0);
    board.revealField(2, 0);
    board.revealField(2, 1);
    board.revealField(1, 2);
    board.revealField(2, 2);*/
    //board.revealField(0, 2); //wygrana
    //board.revealField(0, 1); //przegrana

    //wyswietlenie flagi na danym polu
    //board.toggleFlag(1, 1);
    //board.revealField(1, 1); // mina nie wybuchnie gdyz postawilismy tam flage


    //wyswietlenie surowej tablicy


    //wyswietlenie tablicy dla uzytkownika
    //view.display();
    ctrl.play();
    

    //status gry
    //cout << "STATUS GRY: " << board.showGameState() <<endl;

    //cout << "ilosc min dookola danego pola (0,0): " << board.countMines(0, 0) << endl;
    //cout << "czy na tym polu jest flaga?: " << board.hasFlag(0, 1) << endl;
    //cout << "informacja o polu: " << board.getFieldInfo(1, 1) << endl;
}

