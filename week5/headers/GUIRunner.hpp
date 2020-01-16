#ifndef GUI_RUNNER_HPP
#define GUI_RUNNER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "CManager.hpp"
#include "Constants.hpp"

class GUIRunner {
  private:
    Game currentGame;
    CManager cManager;
    void undoLastCommandIfAvailable();
    sf::Font font;
  public:
    GUIRunner() {};
    void start();
    void setGame(Game game) {
      currentGame = game;
    }
    void drawBoard(sf::RenderWindow & window);
    void drawBoardState(sf::RenderWindow & window);
    void drawSquareOrCircle(const sf::Vector2f & position, char state, sf::RenderWindow & window);
    void handleMouseInput(sf::RenderWindow & window, sf::Event & event);
};

#endif