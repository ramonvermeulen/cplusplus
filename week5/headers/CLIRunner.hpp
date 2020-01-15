#ifndef GAME_RUNNER_HPP
#define GAME_RUNNER_HPP

#include <iostream>
#include "CManager.hpp"
#include "Constants.hpp"

class CLIRunner {
  private:
    Game currentGame;
    CManager cManager;
    void undoLastCommandIfAvailable();
  public:
    CLIRunner();
    void start();
    void setGame(Game game) {
      currentGame = game;
    }
    void playRound();
    void printBoard();
    
};


#endif