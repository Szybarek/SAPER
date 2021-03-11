#include <iostream>

using namespace std;

void intro()
{
  cout << "Hubert Baron" << endl; 
}


 struct Field
{
 bool hasMine;
 bool hasFlag;
 bool isRevealed;
};

class MinesweaperBoard
{
  Field board[100][100];
  int width;
  int height;

  public:
  MinesweaperBoard();
  void debug_display() const;
};


//wartosc poczatkowych pol na nie ma miny, nie ma flagi, pole zakryte
MinesweaperBoard::MinesweaperBoard() : width(10), height(10)
{
 for(int y = 0; y < height; y++)
 {
   for(int x = 0; x < width; x++)
   {
    board[x][y].hasMine = false;
    board[x][y].hasFlag = false;
    board[x][y].isRevealed = false;
   }
 }
 board[1][5].hasMine = true;
 board[2][6].hasFlag = true;
 board[2][7].hasFlag = true;
 board[3][6].isRevealed = true;
}

void MinesweaperBoard::debug_display() const 
{
 for(int y = 0; y < height; y++)
 {
   for(int x = 0; x < width; x++)
   {
      cout << "[";
      if(board[x][y].hasMine)
        cout << "M";
      else
       cout << ".";
        if(board[x][y].isRevealed)
        cout << "o";
      else
       cout << ".";
         if(board[x][y].hasFlag)
        cout << "f";
      else
       cout << ".";
       cout << "]";
   }
   cout << endl;
 }
}



int main() 
{
  MinesweaperBoard start;
  intro();
  start.debug_display();
  return 0;
}