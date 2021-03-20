#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

using namespace std;

int main()
{
    srand(1);
    cout << "Hubert Baron" << endl;
    cout << endl;

    //zmiana mapy
    //srand(time(NULL));

    //konstruktor
    MinesweeperBoard start(3, 3, HARD);
    MSBoardTextView view(start);

    //odsłonięcie danego pola
    start.revealField(0, 0);
    start.revealField(1, 0);
    start.revealField(2, 0);
    start.revealField(2, 1);
    start.revealField(1, 2);
    start.revealField(0, 1);
    start.revealField(2, 2);
    
    //wyswietlenie flagi na danym polu
    start.toggleFlag(0, 1);
    start.toggleFlag(1, 1);
    //cout << "ilosc min dookola danego pola (2,2): " << start.countMines(2, 2) << endl;
    //cout << "Status gry: " << start.showGameState();
    //cout << "czy na tym polu jest flaga?: " << start.hasFlag(4, 5) << endl;
    //cout << "informacja o polu: " << start.getFieldInfo(4, 5) << endl;
    
    //wyswietlenie surowej tablicy
    cout << "debug view" <<endl;
    start.debugDisplay();
    //wyswietlenie tablicy dla uzytkownika
    cout << "user view" <<endl;
    view.display();
    
    cout <<endl;
    cout << "STATUS GRY: " << start.showGameState();
}

