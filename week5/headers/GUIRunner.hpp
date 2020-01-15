#ifndef GUI_RUNNER_HPP
#define GUI_RUNNER_HPP

#include <SFML/Graphics.hpp>
#include "CManager.hpp"
#include "Constants.hpp"

class GUIRunner {
  private:
    Game currentGame;
    CManager cManager;
    void undoLastCommandIfAvailable();
  public:
    GUIRunner();
    void start();
    void setGame(Game game) {
      currentGame = game;
    }
};

#endif