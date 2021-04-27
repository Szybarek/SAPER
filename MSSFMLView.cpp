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
};


void MSSFMLView::draw (sf::RenderWindow & win)
{
    GameState state = graphicBoard.getGameState();
    sf::RectangleShape MSboard;
    sf::CircleShape triangle(15, 3);
    sf::RectangleShape flag;
    sf::RectangleShape notRevealed;
    sf::RectangleShape empty;
    sf::RectangleShape revealedMine;
    sf::RectangleShape number1;
    sf::RectangleShape number2;
    sf::RectangleShape number3;
    sf::RectangleShape number4;
    sf::RectangleShape number5;
    sf::RectangleShape number6;
    sf::RectangleShape number7;
    sf::RectangleShape number8;

    sf::Font font;
    sf::Text txt1;
    if(!font.loadFromFile("../resources/Roman SD.ttf"))
    {
        std::cout << "blad podczas wczytywania czcionki";
    }
    txt1.setFont(font);

    MSboard.setSize ( sf::Vector2f(width*36.5, height*36.5) ) ; //nazwac zmienne
    MSboard.setFillColor (sf::Color(150, 150, 150));
    MSboard.setPosition(0, 0);
    win.draw(MSboard);

    sf::Event event;
    int x=event.mouseButton.x;
    int y=event.mouseButton.y;

    while (win.pollEvent(event)) //sprawdzenie eventu
    {
        if( sf::Event::Closed)
        {
            win.close();
        }
        
        if
                (event.mouseButton.button == sf::Mouse::Right)
        {
            std::cout << "the right button was pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            //graphicBoard.toggleFlag(x, y);
        }
        else if (event.mouseButton.button == sf::Mouse::Left)
        {
            std::cout << "the left button was pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            //graphicBoard.revealField(x, y);
        }
    }

    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {

            if(graphicBoard.getGameState() == FINISHED_WIN)
            {
                txt1.setFont(font);
                txt1.setString("YOU WIN!");
                txt1.setCharacterSize(50);
                txt1.setFillColor(sf::Color::Red);
                txt1.setPosition(400, 300);
                txt1.setStyle(sf::Text::Regular);
                win.draw(txt1);
            }
            if(graphicBoard.getGameState() == FINISHED_LOSS)
            {
                txt1.setFont(font);
                txt1.setString("YOU LOSE!");
                txt1.setCharacterSize(50);
                txt1.setFillColor(sf::Color::Red);
                txt1.setPosition(400, 300);
                txt1.setStyle(sf::Text::Regular);
                win.draw(txt1);
            }
            if(graphicBoard.hasFlag(row, col))
            {
                //pole flagi
                flag.setSize ( sf::Vector2f(30, 30) );
                flag.setFillColor ( sf::Color::Blue );
                flag.setPosition(height+(35*col), width+(35*row));
                triangle.setFillColor ( sf::Color::Red );
                triangle.setPosition(height+(35*col), width+(35*row));
                win.draw(flag);
                win.draw(triangle);
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
                sf::CircleShape bomb(15);
                bomb.setFillColor (sf::Color::Black);
                bomb.setPosition(height+(35*col), width+(35*row));
                win.draw(revealedMine);
                win.draw(bomb);
            }
            else if (graphicBoard.isRevealed(row, col) && !graphicBoard.hasMine(row,col))
            {
                if (graphicBoard.countMines(row, col) == 0)
                {
                    //pole puste
                    empty.setSize ( sf::Vector2f(30, 30) ) ;
                    empty.setFillColor ( sf::Color(128, 137, 148) );
                    empty.setPosition(height+(35*col), width+(35*row));
                    win.draw(empty);
                }
                if (graphicBoard.countMines(row, col) == 1)
                {
                    //pole 1
                    number1.setSize ( sf::Vector2f(30, 30) ) ;
                    number1.setFillColor (sf::Color(128, 137, 148));
                    number1.setPosition(height+(35*col), width+(35*row));
                    txt1.setFont(font);
                    txt1.setString("1");
                    txt1.setCharacterSize(26);
                    txt1.setFillColor(sf::Color::Blue);
                    txt1.setPosition(height+(35*col) + 7.5, width+(35*row));
                    txt1.setStyle(sf::Text::Regular);
                    win.draw(number1);
                    win.draw(txt1);
                }
                if (graphicBoard.countMines(row, col) == 2)
                {
                    //pole 2
                    number2.setSize ( sf::Vector2f(30, 30) ) ;
                    number2.setFillColor (sf::Color(128, 137, 148));
                    number2.setPosition(height+(35*col), width+(35*row));
                    txt1.setFont(font);
                    txt1.setString("2");
                    txt1.setCharacterSize(26);
                    txt1.setFillColor(sf::Color::Green);
                    txt1.setPosition(height+(35*col) + 7.5, width+(35*row));
                    txt1.setStyle(sf::Text::Regular);
                    win.draw(number2);
                    win.draw(txt1);
                }
                if (graphicBoard.countMines(row, col) == 3)
                {
                    //pole 3
                    number3.setSize ( sf::Vector2f(30, 30) ) ;
                    number3.setFillColor (sf::Color(128, 137, 148));
                    number3.setPosition(height+(35*col), width+(35*row));
                    txt1.setFont(font);
                    txt1.setString("3");
                    txt1.setCharacterSize(26);
                    txt1.setFillColor(sf::Color::Red);
                    txt1.setPosition(height+(35*col) + 7.5, width+(35*row));
                    txt1.setStyle(sf::Text::Regular);
                    win.draw(number3);
                    win.draw(txt1);
                }
                if (graphicBoard.countMines(row, col) == 4)
                {
                    //pole 4
                    number4.setSize ( sf::Vector2f(30, 30) ) ;
                    number4.setFillColor (sf::Color(128, 137, 148));
                    number4.setPosition(height+(35*col), width+(35*row));
                    txt1.setFont(font);
                    txt1.setString("4");
                    txt1.setCharacterSize(26);
                    txt1.setFillColor(sf::Color(1, 0, 102));
                    txt1.setPosition(height+(35*col) + 7.5, width+(35*row));
                    txt1.setStyle(sf::Text::Regular);
                    win.draw(number4);
                    win.draw(txt1);
                }
                if (graphicBoard.countMines(row, col) == 5)
                {
                    //pole 5
                    number5.setSize ( sf::Vector2f(30, 30) ) ;
                    number5.setFillColor (sf::Color(128, 137, 148));
                    number5.setPosition(height+(35*col), width+(35*row));
                    txt1.setFont(font);
                    txt1.setString("5");
                    txt1.setCharacterSize(26);
                    txt1.setFillColor(sf::Color(114, 0, 5));
                    txt1.setPosition(height+(35*col) + 7.5, width+(35*row));
                    txt1.setStyle(sf::Text::Regular);
                    win.draw(number5);
                    win.draw(txt1);
                }
                if (graphicBoard.countMines(row, col) == 6)
                {
                    //pole 6
                    number6.setSize ( sf::Vector2f(30, 30) ) ;
                    number6.setFillColor (sf::Color(128, 137, 148));
                    number6.setPosition(height+(35*col), width+(35*row));
                    txt1.setFont(font);
                    txt1.setString("6");
                    txt1.setCharacterSize(26);
                    txt1.setFillColor(sf::Color(71, 162, 151));
                    txt1.setPosition(height+(35*col) + 7.5, width+(35*row));
                    txt1.setStyle(sf::Text::Regular);
                    win.draw(number6);
                    win.draw(txt1);
                }
                if (graphicBoard.countMines(row, col) == 7)
                {
                    //pole 7
                    number7.setSize ( sf::Vector2f(30, 30) ) ;
                    number7.setFillColor (sf::Color(128, 137, 148));
                    number7.setPosition(height+(35*col), width+(35*row));
                    txt1.setFont(font);
                    txt1.setString("7");
                    txt1.setCharacterSize(26);
                    txt1.setFillColor(sf::Color(1, 2, 2));
                    txt1.setPosition(height+(35*col) + 7.5, width+(35*row));
                    txt1.setStyle(sf::Text::Regular);
                    win.draw(number7);
                    win.draw(txt1);
                }
                if (graphicBoard.countMines(row, col) == 8)
                {
                    //pole 8
                    number8.setSize ( sf::Vector2f(30, 30) ) ;
                    number8.setFillColor (sf::Color(128, 137, 148));
                    number8.setPosition(height+(35*col), width+(35*row));
                    txt1.setFont(font);
                    txt1.setString("8");
                    txt1.setCharacterSize(26);
                    txt1.setFillColor(sf::Color::Blue);
                    txt1.setPosition(height+(35*col) + 7.5, width+(35*row));
                    txt1.setStyle(sf::Text::Regular);
                    win.draw(number8);
                    win.draw(txt1);
                }
            }
        }

    }
}

/*void Event(sf::RenderWindow & win)
{
 sf::Event event;
  while (win.pollEvent(event))
{
  if( sf::Event::Closed)
  {
            win.close();
  }
     if
    (event.mouseButton.button == sf::Mouse::Right)
    {
        std::cout << "the right button was pressed" << std::endl;
        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
        break;

    }
}       
}
*/

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
/*
                else
                {
                    //pole numeru do miny
                    number.setSize ( sf::Vector2f(30, 30) );
                    number.setFillColor ( sf::Color::Blue );
                    number.setPosition(height+(35*col), width+(35*row));
                    if(graphicBoard.countMines(row, col) == 1)
                    {
                    sf::RectangleShape number1;
                    number1.setSize ( sf::Vector2f(30, 30) );
                    number1.setFillColor ( sf::Color::Red );
                    number1.setPosition(height+(35*col), width+(35*row));
                    win.draw(number1);
                    }
                    win.draw(number);
                }
                */