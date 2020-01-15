#include "CLI.hpp"

CLI::CLI(Game & game) {
  std::cout << "CLI" << std::endl;
  game = game;
}

void CLI::printBoard(std::array<BoardState, 9> & board) {
  int c = 0;
  std::cout << "=========" << std::endl;
  std::for_each(board.begin(), board.end(), [&c, this](BoardState bs) {
    std::string representation = boardStateToString(bs);
    std::cout << representation;
    if (c % 3 == 2) std::cout << std::endl;
    c++;
  });
  std::cout << "=========" << std::endl;
}

std::string CLI::boardStateToString(BoardState & bs) {
  std::string representation;
  if (bs == BoardState::Empty) representation = " - ";
  if (bs == BoardState::X) representation = " X ";
  if (bs == BoardState::O) representation = " O ";
  return representation;
}

void CLI::playRound() {
  int unCheckedPosition;
  BoardState current = game.getCurrentPlayer();
  std::cout << "It is player " << boardStateToString(current) << " it's turn." << std::endl;
  std::cout << "Please pick a board position between [1-9] to play" << std::endl;
  std::cin >> unCheckedPosition;
  if (std::cin.fail() || unCheckedPosition > 9 || unCheckedPosition < 1) {
    std::cin.clear();
    std::cin.ignore(250, '\n');
    std::cout << "Wrong input, please try again..." << std::endl;
    return playRound();
  }
  Command* command = new MakePlayCommand(&game, current, static_cast<BoardPosition>(unCheckedPosition - 1));
  game.addCommand(command);
  printBoard(game.getBoardState());
}

void CLI::gameLoop() {
  while (true) {
    if(!game.isGameOver()) {
      playRound();
    }
  }
}

