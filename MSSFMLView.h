#ifndef MSSFMLVIEW_H
#define MSSFMLVIEW_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"


class MSSFMLView
{
    int height;
    int width;
    MinesweeperBoard & graphicBoard;
public:

    explicit MSSFMLView(MinesweeperBoard &board);
    void draw (sf::RenderWindow & win);
};

#endif