#include "MakePlayCommand.hpp"
#include <iostream>

MakePlayCommand::MakePlayCommand(Game * game, BoardState player, BoardPosition boardPosition) : Command(),
  _game{game}
{
  _player = player;
  _boardPosition = boardPosition;
}

MakePlayCommand::~MakePlayCommand() {
  delete _game;
}

void MakePlayCommand::execute() {
  std::cout << _player << " " << _boardPosition << std::endl;
  _game -> makePlay(_player, _boardPosition);
}
