#ifndef MSBOARDTEXTCONTROLLER__H_
#define MSBOARDTEXTCONTROLLER__H_

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"


class MSTextController
{
int height;
int width;
MinesweeperBoard& debugBoard;
MSBoardTextView& playerBoard;

public:
MSTextController(MinesweeperBoard& board, MSBoardTextView& view); 
void play();
};

#endif

//OPCJE
//wybierz rozmiar tablicy od 0 do 100;
//wybierz poziom trudnosci
//GRAJ