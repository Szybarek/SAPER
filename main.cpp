#include <iostream>
#include<ctime>
#include "MinesweeperBoard.h"

using namespace std;

int main()
{
    srand(1);
    cout << "Hubert Baron" << endl;
    //srand(time(NULL));

    //konstruktor
    MinesweeperBoard start(2, 2, HARD);

    //wyswietlenie flagi na danym polu
    //start.toggleFlag(4, 5);

    //odsłonięcie danego pola
    start.revealField(1, 1);
    start.revealField(0, 0);
    start.revealField(0, 1);
    
    
    //wyswietlenie calej tablicy
    start.debugDisplay();

    //cout << "ilosc min dookola danego pola (2,2): " << start.countMines(2, 2) << endl;
    cout << "Status gry: " << start.showGameState();
    //cout << "czy na tym polu jest flaga?: " << start.hasFlag(4, 5) << endl;
    //cout << "informacja o polu: " << start.getFieldInfo(4, 5) << endl;
    
}

