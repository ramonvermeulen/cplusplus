#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "CLI.hpp"
#include <iostream>

enum player {
  A,
  B
};

void onPlayClick() {
  std::cout << "play" << std::endl;
}

int main() {
  // sf::RenderWindow window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT }, "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close};
  // Menu menu = Menu();

  // while (window.isOpen()) {
  //   sf::Event event;
  //   window.clear(BACKGROUND_COLOR);

  //   menu.draw(window);

  //   window.display();

  //   while (window.pollEvent(event)) {
  //     if (event.type == sf::Event::Closed) {
  //       window.close();
  //     }

  //     if(event.type == event.KeyReleased) {
  //       if(event.key.code == sf::Keyboard::Down) {
  //         menu.moveDown();
  //       }
  //       if(event.key.code == sf::Keyboard::Up) {
  //         menu.moveUp();
  //       }
  //     }
      
  //   }
    
  //   sf::sleep(sf::milliseconds(20));
  // }




  //*------------CLI GAME-------------*//
  Game game = Game();
  CLI cli = CLI(game);

  cli.gameLoop();
  return 0;
}