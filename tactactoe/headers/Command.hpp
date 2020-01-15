#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "Game.hpp"
#include <iostream>

class Command {
  private:
    Game previousGame;
  protected:
    Game game;
  public:
    Game getGame() {
      return game;
    }
    void setGame(Game & incomingGame) {
      game = incomingGame;
      previousGame = incomingGame;
    }
    virtual void execute() = 0;
    void undo() {
      game = previousGame;
    }
};

#endif