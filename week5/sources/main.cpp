#include <SFML/Graphics.hpp>
#include <iostream>
#include "../headers/CLIRunner.hpp"
#include "../headers/GUIRunner.hpp"


enum Mode {
  CLI,
  GUI
};

void printTicTacToeArt() {
  std::cout << " _   _      _             _             " << std::endl;
  std::cout << "| | (_)    | |           | |            " << std::endl;
  std::cout << "| |_ _  ___| |_ __ _  ___| |_ ___   ___ " << std::endl;
  std::cout << "| __| |/ __| __/ _` |/ __| __/ _ \\ / _ \\" << std::endl;
  std::cout << "| |_| | (__| || (_| | (__| || (_) |  __/" << std::endl;
  std::cout << " \\__|_|\\___|\\__\\__,_|\\___|\\__\\___/ \\___|" << std::endl;
  std::cout << std::endl;
  std::cout << "Welcome to TicTacToe in C++ by Ramon" << std::endl;
}

Mode askForPlayMode() {
  int mode;
  std::cout << "Do you want to play in [0] CLI or [1] GUI mode?:" << std::endl;
  std::cin >> mode;
  if (mode != Mode::CLI && mode != Mode::GUI) {
    std::cin.clear();
    std::cin.ignore(250, '\n');
    std::cout << "Wrong input, please try again..." << std::endl;
    return askForPlayMode();
  }
  return static_cast<Mode>(mode);
}

int main() {
  Game game = Game();
  printTicTacToeArt();
  Mode mode = askForPlayMode();

  if (mode == Mode::CLI) {
    CLIRunner cliRunner;
    cliRunner.setGame(game);
    cliRunner.start();
  }

  if (mode == Mode::GUI) {
    GUIRunner guiRunner;
    guiRunner.setGame(game);
    guiRunner.start();
  }
  
  return 0;
}