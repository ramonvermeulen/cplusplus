#include "../headers/CManager.hpp"

Game CManager::processCommand(Command *command, Game &game) {
  command->setGame(game);
  command->execute();
  commands.push(command);
  return command->getGame();
}

Game CManager::makePlay(Game &game, int position) {
  Command *command = new MakePlay(position);
  return processCommand(command, game);
}

bool CManager::undo(Game &game) {
  if (commands.empty()) {
    return false;
  }
  Command *command = commands.top();
  command->undo();
  game = command->getGame();
  commands.pop();
  return true;
}