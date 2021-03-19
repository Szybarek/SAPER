#include <iostream>
#include<ctime>
#include "MinesweeperBoard.h"

using namespace std;

int main()
{
    //srand(1);
    cout << "Hubert Baron" << endl;
    srand(time(NULL));

    //konstruktor
    MinesweeperBoard start(3, 4, EASY);

    //wyswietlenie flagi na danym polu
    start.toggleFlag(1, 2);

    //odsłonięcie danego pola
    start.revealField(1, 0);
    
    //wyswietlenie calej tablicy
    start.debugDisplay();


    cout << "informacja o polu: " << start.getFieldInfo(0, 0) << endl;
    cout << "ilosc min dookola danego pola (3,3): " << start.countMines(3, 3) << endl;
    cout << "Status gry: " << start.showGameState() << endl;
    cout << "czy na tym polu jest flaga?" << start.hasFlag(3, 3) << endl;
    
    
}

