#ifndef GAME_HPP
#define GAME_HPP

#include "Constants.hpp"

class Game {
  private:
    char currentPlayer = X;
    char board[MAX];
    bool checkWinScenario(BP A, BP B, BP C);
  public:
    Game();
    void makePlay(int position);
    void resetBoard();
    GameState checkGameState();
    char getNextPlayer();
    char getCurrentPlayer() {
      return currentPlayer;
    }
    char * getBoard() {
      return board;
    }
};

#endif