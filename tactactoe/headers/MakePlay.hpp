#ifndef MAKE_PLAY_HPP
#define MAKE_PLAY_HPP

#include <iostream>
#include "Command.hpp"

class MakePlay: public Command {
  private:
    int position;
  public:
    MakePlay(int pos) {
      position = pos;
    }
    void execute() override {
      game.makePlay(position);
    }
};

#endif