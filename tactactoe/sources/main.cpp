#include "../headers/GameRunner.hpp"

int main() {
  GameRunner gameRunner;
  Game game = Game();
  gameRunner.setGame(game);
  gameRunner.start();
  return 0;
}