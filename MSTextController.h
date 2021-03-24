#ifndef MSTEXTCONTROLLER__H_
#define MSTEXTCONTROLLER__H_

#include "MinesweeperBoard.h"


class MSTextController
{
MinesweeperBoard& debugPlay;
MinesweeperTextView& play;

public:
MSTextController(MSBoardTextView& view, MinesweeperBoard& board); 
//OPCJE
//wybierz rozmiar tablicy od 0 do 100;
//wybierz poziom trudnosci
//GRAJ
void play();
};

#endif