#ifndef _GAME_HPP
#define _GAME_HPP

#include "Constants.hpp"
#include "Command.hpp"

class Game {
  private:
    std::vector<Command*> commands;
    std::array<BoardState, 9> board;
    BoardState currentPlayer;
  public:
    Game();
    void addCommand(Command * command);
    bool isGameOver();
    void clearBoard();
    void makePlay(BoardState boardState, BoardPosition boardPosition);
    BoardState getCurrentPlayer();
    std::array<BoardState, 9> & getBoardState();
};

#endif
