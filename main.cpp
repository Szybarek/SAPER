#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "HUBERT BARON - SAPER"); //rozmiar okna
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1); //1-ta sama mapa, 0-losowa mapa

    MinesweeperBoard board(5, 5, HARD); //rozmiar planszy i poziom trudnosci
    MSSFMLView SFMLview(board);
    MSBoardTextView TEXTview(board);
    MSTextController ctrl(board, TEXTview);
    while (window.isOpen())
    {
        window.clear(); //czyszczenie
        SFMLview.draw(window); //narysowanie
        window.display(); //wyswietlenie
        ctrl.play(window, board); //granie
    }
    return 0;
} 


