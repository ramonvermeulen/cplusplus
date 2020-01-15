#ifndef _GUI_MENU_HPP
#define _GUI_MENU_HPP

#define MAX_NUMBER_OF_MENU_ITEMS 3

#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class GUIMenu {
  private:
    int selectedItemIndex = 0;
    sf::Font font;
    sf::Text menuOptions[MAX_NUMBER_OF_MENU_ITEMS];
  public:
    GUIMenu();
    void draw(sf::RenderWindow & window);
    void moveUp();
    void moveDown();
    void handleInput();
};

#endif
