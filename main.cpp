#include <iostream>
#include<ctime>
#include "MinesweeperBoard.h"

using namespace std;

int main()
{
    cout << "Hubert Baron" << endl;
    srand(time(NULL));
    //srand(1);

    MinesweeperBoard start(4, 4, HARD, RUNNING);
    start.toggleFlag(1, 1);
    start.toggleFlag(1, 2);
    start.revealField(1, 3);
    start.debug_display();
    cout << "Liczba min dookola tego pola: " << start.countMines(3, 3) << endl;
    cout << "Liczba flag na tym polu: " << start.hasFlag(3, 3) << endl;
    start.getGameState();
}

