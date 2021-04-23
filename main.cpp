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

    MinesweeperBoard board(10, 10, DEBUG);
	  MSSFMLView SFMLview(board); //graficzny
    MSBoardTextView TEXTview(board); //tekstowy
    MSTextController ctrl(board, TEXTview);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
        }
        
        window.clear(); 
        SFMLview.draw(window); //narysowanie
        window.display(); //wyswietlenie

        ctrl.play();
    }
  return 0;
} 
