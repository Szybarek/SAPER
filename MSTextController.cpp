#include<iostream>
#include "MSTextController.h"
#include "MSSFMLView.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"


#include "MinesweeperBoard.h"
#include "MSTextController.h"

#include <vector>

using namespace std;

MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view) : debugBoard(board), playerBoard(view)
{
    height = board.getBoardHeight();
    width = board.getBoardWidth();
}

void MSTextController::play(sf::RenderWindow & win, MinesweeperBoard& board)
{
    sf::Event event;
    int x, y;
    x=sf::Mouse::getPosition().x;
    y=sf::Mouse::getPosition().y;
    while (win.pollEvent(event)) //sprawdzenie eventu
    {
        if( sf::Event::Closed)
        {
            win.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {

                for (int row = 0; row < height; ++row)
                {
                    for (int col = 0; col < width; ++col)
                    {
                        if(x > 35*row && x < 35*(row+1) && y > 35*(col+1) && y < 35*(col+2))
                            board.revealField(col, row);
                    }
                }
            }
            else if(event.mouseButton.button == sf::Mouse::Right)
            {

                for (int row = 0; row < height; ++row)
                {
                    for (int col = 0; col < width; ++col)
                    {
                        if(x > 35*row && x < 35*(row+1) && y > 35*(col+1) && y < 35*(col+2))
                            board.toggleFlag(col, row);
                    }
                }
            }
        }
    }
}
    

/*
        cout<< endl;
        cout << "debug view" << endl; //do testow
        debugBoard.debugDisplay(); //do testow
        cout << endl;
        cout << "user view" << endl;
        playerBoard.display();
        cout << endl;
        cout << "STATUS GRY: " << debugBoard.showGameState();
        //gra sie skonczyla
       /* if(debugBoard.getGameState() != RUNNING)
        {
            break;
        } //
        char choice;
        int row;
        int col;
        cout << endl;
        cout << "Co chcesz zrobic? Flaga (f), odsloniecie pola (r)" << endl;
        cin >> choice;
        //flaga
        if(choice == 'f')
        {
            cout << "Podaj rzad oraz kolumne na ktorych chcesz postawic flage, (koordynaty maja byc rozdzielone spacja)" << endl;
            cin >> row >> col;
            debugBoard.toggleFlag(row, col);
        }
        //reveal
        if(choice == 'r')
        {
            cout << "Podaj rzad oraz kolumne pola ktore chcesz odslonic, (koordynaty maja byc rozdzielone spacja)" << endl;
            cin >> row >> col;
            debugBoard.revealField(row, col);
        }*/
