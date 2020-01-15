#ifndef _MAKE_PLAY_COMMAND_HPP
#define _MAKE_PLAY_COMMAND_HPP

#include "Command.hpp"
#include "Constants.hpp"
#include "Game.hpp"

class MakePlayCommand : public Command {
  private:
    Game* _game;
    BoardState _player;
    BoardPosition _boardPosition;
  public:
    MakePlayCommand(Game * game, BoardState player, BoardPosition boardPosition);
    virtual void execute() override;
    virtual ~MakePlayCommand() override;
};

#endif
