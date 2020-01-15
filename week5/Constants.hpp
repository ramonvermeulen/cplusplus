#ifndef _CONSTANTS_HPP
#define _CONSTANTS_HPP

#include <SFML/Graphics.hpp>

extern const unsigned int SCREEN_WIDTH;
extern const unsigned int SCREEN_HEIGHT;
extern const sf::Color FONT_COLOR;
extern const sf::Color ACTIVE_FONT_COLOR;
extern const sf::Color BACKGROUND_COLOR;
enum BoardState {
  Empty,
  X,
  O
};
enum BoardPosition {
  LeftTop,
  Top,
  RightTop,
  LeftMiddle,
  Middle,
  RightMiddle,
  LeftBottom,
  Bottom,
  RightBottom
};

#endif
