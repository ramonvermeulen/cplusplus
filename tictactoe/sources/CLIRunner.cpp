#include "../headers/CLIRunner.hpp"

CLIRunner::CLIRunner() {

}

void CLIRunner::undoLastCommandIfAvailable() {
  Game undoGame;
  if(!cManager.undo(undoGame)) {
    std::cout << "No more commands to undo!" << std::endl;
    return;
  }
  setGame(undoGame);
}

void CLIRunner::start() {
  GameState currentState = currentGame.checkGameState();
  while(currentState == GameState::Playing) {
    playRound();
    printBoard();
    currentState = currentGame.checkGameState();
  }
  if (currentState == GameState::Draw) {
    std::cout << "DRAW!!! You are both to smart for this game." << std::endl;
  }
  if (currentState == GameState::Win) {
    std::cout << "WINNER!!! Congratulations player " << currentGame.getNextPlayer() << "!" << std::endl;
  }
}

void CLIRunner::playRound() {
  int positionToPlay;
  std::cout << "It is player " << currentGame.getCurrentPlayer() << " it's turn." << std::endl;
  std::cout << "Please pick a board position number between [1-9] to play or 0 revert" << std::endl;
  std::cin >> positionToPlay;
  if (std::cin.fail() || positionToPlay > 9 || positionToPlay < 1) {
    if(positionToPlay == 0) {
      undoLastCommandIfAvailable();
      return;
    }
    std::cin.clear();
    std::cin.ignore(250, '\n');
    std::cout << "Wrong input, please try again..." << std::endl;
    return playRound();
  }
  setGame(cManager.makePlay(currentGame, positionToPlay - 1));
}

void CLIRunner::printBoard() {
  int c = 0;
  std::cout << std::endl;
  for (int i = 0; i < MAX; i++) {
    std::cout << currentGame.getBoard()[i];
    if (c % 3 == 2) std::cout << std::endl;
    c++;
  }
  std::cout << std::endl;
}