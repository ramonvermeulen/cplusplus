#ifndef C_MANAGER_HPP
#define C_MANAGER_HPP

#include <stack>

#include "Command.hpp"
#include "MakePlay.hpp"

class CManager {
  private:
    std::stack<Command *> commands;
    Game processCommand(Command *command, Game &game);
  public:
    CManager();
    Game makePlay(Game &game, int position);
    bool undo(Game &game);
};

#endif