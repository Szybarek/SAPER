#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "HUBERT BARON - SAPER");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);

    MinesweeperBoard board(5, 5, HARD);
	  MSSFMLView SFMLview(board); //graficzny
    MSBoardTextView TEXTview(board); //tekstowy
    MSTextController ctrl(board, TEXTview);
    while (window.isOpen())
    {
     
          window.clear(); 
          SFMLview.draw(window); //narysowanie
          window.display(); //wyswietlenie
          ctrl.play(window, board);
    }
  return 0;
} 


