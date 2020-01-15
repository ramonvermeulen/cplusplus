#include "../headers/GUIRunner.hpp"
#include "../headers/GUIMenu.hpp"

GUIRunner::GUIRunner() {

}

void GUIRunner::undoLastCommandIfAvailable() {
  Game undoGame;
  if(!cManager.undo(undoGame)) {
    // no more commands to undo //
    return;
  }
  setGame(undoGame);
}

void GUIRunner::start() {
  sf::RenderWindow window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT }, "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close};
  GUIMenu menu = GUIMenu();

  while (window.isOpen()) {
    sf::Event event;
    window.clear(BACKGROUND_COLOR);

    menu.draw(window);

    window.display();

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if(event.type == event.KeyReleased) {
        if(event.key.code == sf::Keyboard::Down) {
          menu.moveDown();
        }
        if(event.key.code == sf::Keyboard::Up) {
          menu.moveUp();
        }
      }
      
    }
    
    sf::sleep(sf::milliseconds(20));
  }
}
