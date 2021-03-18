#include <iostream>
#include<ctime>
#include "MinesweeperBoard.h"

using namespace std;

int main()
{
    //srand(1);
    //start.toggleFlag(1, 1);
    //start.toggleFlag(2, 2);
    //start.revealField(1, 3);
    //start.showGameState();
    //start.countMines(3, 3);
    //start.hasFlag(3, 3);
    cout << "Hubert Baron" << endl;
    srand(time(NULL));
    MinesweeperBoard start(10, 10, DEBUG);
    start.debug_display();
    start.getFieldInfo(11, 11);
}

