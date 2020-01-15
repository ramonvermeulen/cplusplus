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
    std::cout << "     _                    " << std::endl;
    std::cout << "    | |                   " << std::endl;
    std::cout << "  __| |_ __ __ ___      __" << std::endl;
    std::cout << " / _` | '__/ _` \\ \\ /\\ / /" << std::endl;
    std::cout << "| (_| | | | (_| |\\ V  V / " << std::endl;
    std::cout << " \\__,_|_|  \\__,_| \\_/\\_/  " << std::endl;
    std::cout << std::endl;
    std::cout << "DRAW!!! You are both too smart for this game." << std::endl;
    std::cout << std::endl << std::endl;
  }
  if (currentState == GameState::Win) {
    std::cout << "             ___________" << std::endl;
    std::cout << "            '._==_==_=_.'" << std::endl;
    std::cout << "            .-\\:      /-." << std::endl;
    std::cout << "           | (|:.     |) |" << std::endl;
    std::cout << "            '-|:.     |-'" << std::endl;
    std::cout << "              \\::.    /" << std::endl;
    std::cout << "               '::. .'" << std::endl;
    std::cout << "                 ) (" << std::endl;
    std::cout << "               _.' '._" << std::endl;
    std::cout << "              `\"\"\"\"\"\"\"`" << std::endl;
    std::cout << std::endl;
    std::cout << "WINNER!!! Congratulations player " << currentGame.getNextPlayer() << "!" << std::endl;
    std::cout << std::endl << std::endl;
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
  std::cout << std::endl;
  std::cout << "|||||||||||" << std::endl;
  for (int i = 0; i < MAX; i++) {
    if (c % 3 == 0) std::cout << "|";
    std::cout << "|" << currentGame.getBoard()[i] << "|";
    if (c % 3 == 2) std::cout << "|" << std::endl;
    c++;
  }
  std::cout << "|||||||||||" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

}