#include "MSSFMLView.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MinesweeperBoard.h"
#include "MSTextController.h"
#include <vector>

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : graphicBoard(board)
{
    height = graphicBoard.getBoardHeight();
    width = graphicBoard.getBoardWidth();
}

void MSSFMLView::draw (sf::RenderWindow & win)
{
    GameState state = graphicBoard.getGameState();
    sf::RectangleShape MSboard;
    sf::RectangleShape flag;
    sf::RectangleShape notRevealed;
    sf::RectangleShape empty;
    sf::RectangleShape revealedMine;
    sf::RectangleShape number;

    MSboard.setSize ( sf::Vector2f(width*36.5, height*36.5) ) ; //nazwac zmienne
    MSboard.setFillColor ( sf::Color::White );
    MSboard.setPosition(0, 0);
    win.draw(MSboard);    

    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            if(graphicBoard.hasFlag(row, col))
            {
                //pole flagi
                flag.setSize ( sf::Vector2f(30, 30) ) ; //nazwac zmienne
                flag.setFillColor ( sf::Color::Blue );
                flag.setPosition(height+(35*col), width+(35*row));
                win.draw(flag);
            }
            else
            {
                //pole zasloniete
                notRevealed.setSize ( sf::Vector2f(30, 30) ) ;
                notRevealed.setFillColor ( sf::Color::Black );
                notRevealed.setPosition(height+(35*col), width+(35*row));
                win.draw(notRevealed);
            }
            if (graphicBoard.hasMine(row, col) && graphicBoard.isRevealed(row,col))
            {
                //pole odslonietej miny
                revealedMine.setSize ( sf::Vector2f(30, 30) );
                revealedMine.setFillColor ( sf::Color::Red );
                revealedMine.setPosition(height+(35*col), width+(35*row));
                win.draw(revealedMine);
            }
            else if (graphicBoard.isRevealed(row, col) && !graphicBoard.hasMine(row,col))
            {
                if (graphicBoard.countMines(row, col) == 0)
                {
                    //pole puste
                    empty.setSize ( sf::Vector2f(30, 30) ) ;
                    empty.setFillColor ( sf::Color::Green );
                    empty.setPosition(height+(35*col), width+(35*row));
                    win.draw(empty);
                }
                else
                {
                    //pole numeru do miny
                    number.setSize ( sf::Vector2f(30, 30) );
                    number.setFillColor ( sf::Color::Blue );
                    number.setPosition(height+(35*col), width+(35*row));
                    win.draw(number);
                }
            }
        }

    }
}



/*GameState state = displayableBoard.getGameState();
for (int row = 0; row < height; ++row)
{
    for (int col = 0; col < width; ++col)
    {

        if (!displayableBoard.isRevealed(row,col))
        {
            if(displayableBoard.hasFlag(row, col))
                cout << "[F]"; //pole flagi
            else
                cout << "[?]"; //pole zasloniete
        }
        if (displayableBoard.hasMine(row, col) && displayableBoard.isRevealed(row,col))
        {
            cout << "[BOOM]"; //pole miny
            state = FINISHED_LOSS;
        }
        else if (displayableBoard.isRevealed(row, col) && !displayableBoard.hasMine(row,col))
        {
            if (displayableBoard.countMines(row, col) == 0)
                cout << "[ ]"; //pole odsloniete
            else
                cout << "[" << displayableBoard.countMines(row, col) << "]"; //pole liczby od miny
        }
    }
    cout << endl;
}*/

//NARYSOWAC

//pole zasloniete
//pole odsloniete
//pole miny
//pole flagi
//pole liczby od miny

