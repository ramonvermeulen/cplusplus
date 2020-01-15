#include "../headers/Game.hpp"

Game::Game() {
  resetBoard();
}

char Game::getNextPlayer() {
  if(currentPlayer == O) return X;
  if(currentPlayer == X) return O;
  return EMPTY;
}

void Game::resetBoard() {
  for (int c = 0; c < MAX; c++) {
    board[c] = EMPTY;
  }
}

void Game::makePlay(int position) {
  if (board[position] == EMPTY) {
    board[position] = currentPlayer;
    if (currentPlayer == X) currentPlayer = O;
    else if (currentPlayer == O) currentPlayer = X;
  }
}

bool Game::checkWinScenario(BP A, BP B, BP C) {
  if(board[A] == board[B] && board[B] == board[C] 
  && board[A] != EMPTY && board[B] != EMPTY && board[C] != EMPTY) return true;
  return false;
}

GameState Game::checkGameState() {
  if(checkWinScenario(TL, T, TR)) return Win;
  if(checkWinScenario(ML, M, MR)) return Win;
  if(checkWinScenario(BL, B, BR)) return Win;
  if(checkWinScenario(TL, M, BR)) return Win;
  if(checkWinScenario(TR, M, BL)) return Win;
  if(checkWinScenario(TL, ML, BL)) return Win;
  if(checkWinScenario(T, M, B)) return Win;
  if(checkWinScenario(TR, MR, BR)) return Win;
  
  for (int i = 0; i < MAX; i++) {
    if(board[i] == EMPTY) {
      return Playing;
    }
  }
  return Draw;
}
