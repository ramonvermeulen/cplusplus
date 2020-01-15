#ifndef _CLI_HPP
#define _CLI_HPP

#include "Constants.hpp"
#include "Game.hpp"
#include "MakePlayCommand.hpp"
#include <iostream>

class CLI {
  private:
    Game game;
  public:
    CLI(Game & game);
    void printBoard(std::array<BoardState, 9> & board);
    std::string boardStateToString(BoardState & boardState);
    void playRound();
    void gameLoop();
};

#endif
