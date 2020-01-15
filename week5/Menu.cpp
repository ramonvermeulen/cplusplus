#include "Menu.hpp"
#include <iostream>

Menu::Menu() {
  if(!font.loadFromFile("./assets/fonts/samantha.ttf")) {
    /* handle error */
  }
    menuOptions[0].setFillColor(ACTIVE_FONT_COLOR);
    menuOptions[0].setFont(font);
    menuOptions[0].setString("Play");
    menuOptions[0].setCharacterSize(50);
    menuOptions[0].setPosition(sf::Vector2f(SCREEN_WIDTH / 2, 100));
    sf::FloatRect textRect = menuOptions[0].getLocalBounds();
    menuOptions[0].setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);

    menuOptions[1].setFillColor(FONT_COLOR);
    menuOptions[1].setFont(font);
    menuOptions[1].setString("About");
    menuOptions[1].setCharacterSize(50);
    menuOptions[1].setPosition(sf::Vector2f(SCREEN_WIDTH / 2, 300));
    textRect = menuOptions[1].getLocalBounds();
    menuOptions[1].setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);

    menuOptions[2].setFillColor(FONT_COLOR);
    menuOptions[2].setFont(font);
    menuOptions[2].setString("Exit");
    menuOptions[2].setCharacterSize(50);
    menuOptions[2].setPosition(sf::Vector2f(SCREEN_WIDTH / 2, 500));
    textRect = menuOptions[2].getLocalBounds();
    menuOptions[2].setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
}

void Menu::draw(sf::RenderWindow & window) {
  for (int i = 0; i < MAX_NUMBER_OF_MENU_ITEMS; i++) {
    window.draw(menuOptions[i]);
  }
}

void Menu::moveUp() {
  if(selectedItemIndex - 1 >= 0) {
    menuOptions[selectedItemIndex].setFillColor(FONT_COLOR);
    selectedItemIndex--;
    menuOptions[selectedItemIndex].setFillColor(ACTIVE_FONT_COLOR);
  }
}

void Menu::moveDown() {
  if(selectedItemIndex + 1 < MAX_NUMBER_OF_MENU_ITEMS) {
    menuOptions[selectedItemIndex].setFillColor(FONT_COLOR);
    selectedItemIndex++;
    menuOptions[selectedItemIndex].setFillColor(ACTIVE_FONT_COLOR);
  }
}
