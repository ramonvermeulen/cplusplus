#include "Game.hpp"
#include <iostream>

Game::Game() {
  std::cout << "CONSTRUCTOR" << std::endl;
  currentPlayer = BoardState::X;
  commands = std::vector<Command*>{};
  board = std::array<BoardState, 9>{};
}

void Game::addCommand(Command * command) {
  commands.push_back(command);
}

bool Game::isGameOver() {
  bool isGameOver = false;

  return isGameOver;
}

void Game::clearBoard() {
  board = {}; 
}


void Game::makePlay(BoardState player, BoardPosition boardPosition) {
  if (board[boardPosition] == BoardState::Empty) {
    std::cout << "JUP" << std::endl;
    board[boardPosition] = player;
    if(currentPlayer == BoardState::O) {
      currentPlayer = BoardState::X;
    } else {
      currentPlayer = BoardState::O;
    }
  }
}

std::array<BoardState, 9> & Game::getBoardState() {
  clearBoard();
  std::for_each(commands.begin(), commands.end(), [](Command * command){
    command -> execute();
  });
  return board;
}

BoardState Game::getCurrentPlayer() {
  return currentPlayer;
}