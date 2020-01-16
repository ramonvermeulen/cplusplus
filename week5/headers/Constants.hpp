#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <SFML/Graphics.hpp>

const int BOARD_WIDTH = 600.0;
const int BOARD_HEIGHT = 600.0;
const sf::Color FONT_COLOR = sf::Color(238, 255, 179);
const sf::Color ACTIVE_FONT_COLOR = sf::Color(254, 147, 140);
const sf::Color BACKGROUND_COLOR = sf::Color(47, 57, 77);
const char EMPTY = '-';
const char O = 'o';
const char X = 'x';
const int MAX = 9;

enum GameState {
  Draw,
  Win,
  Playing
};

enum BP {
  TL,
  T,
  TR,
  ML,
  M,
  MR,
  BL,
  B,
  BR
};

enum GUIGameState {
  Menu,
  InGame
};


#endif
