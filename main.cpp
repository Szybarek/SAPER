#include <iostream>
#include<ctime>
#include "MinesweeperBoard.h"

using namespace std;

int main()
{
    cout << "Hubert Baron" << endl;
    srand(time(NULL));
    //srand(1);

    MinesweeperBoard start(10, 10, HARD, RUNNING);
    start.toggleFlag(1, 5);
    start.toggleFlag(1, 7);
    start.revealField(5, 5);
    start.debug_display();
    cout << "Liczba min dookola tego pola: " << start.countMines(4, 4) << endl;
    cout << "Liczba flag na tym polu: " << start.hasFlag(4, 4) << endl;
    start.getGameState();
}

