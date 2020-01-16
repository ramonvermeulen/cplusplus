#include "../headers/GUIRunner.hpp"

void GUIRunner::undoLastCommandIfAvailable() {
  Game undoGame;
  if(!cManager.undo(undoGame)) {
    // no more commands to undo //
    return;
  }
  setGame(undoGame);
}

void GUIRunner::start() {
  sf::RenderWindow window{ sf::VideoMode{ BOARD_WIDTH, BOARD_HEIGHT + 100 }, "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close};

  while (window.isOpen()) {
    sf::Event event;
    window.clear(BACKGROUND_COLOR);

    drawBoard(window);
    drawBoardState(window);
    window.display();

    while (window.pollEvent(event)) {
      handleMouseInput(window, event);
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    GameState currentState = currentGame.checkGameState();

    if (currentState == GameState::Win) {
      std::cout << std::endl;
      std::cout << "DRAW!!! You are both too smart for this game." << std::endl;
      break;
    } else if (currentState == GameState::Draw) {
      std::cout << std::endl;
      std::cout << "WINNER!!! Congratulations player " << currentGame.getNextPlayer() << "!" << std::endl;
      break;
    }
    
    sf::sleep(sf::milliseconds(10));
  }
}

void GUIRunner::drawBoard(sf::RenderWindow & window) {
  sf::RectangleShape leftVerticalLine;
  sf::RectangleShape rightVerticalLine;
  sf::RectangleShape topHorizontalLine;
  sf::RectangleShape middleHorizontalLine;
  sf::RectangleShape bottomHorizontalLine;
  sf::Text text;

  leftVerticalLine.setSize(sf::Vector2f{ 10, BOARD_HEIGHT });
  leftVerticalLine.setOrigin(sf::Vector2f{ 10, BOARD_HEIGHT });
  leftVerticalLine.setPosition(sf::Vector2f{ 200, BOARD_HEIGHT });
  leftVerticalLine.setFillColor(sf::Color::Red);

  rightVerticalLine.setSize(sf::Vector2f{ 10, BOARD_HEIGHT });
  rightVerticalLine.setOrigin(sf::Vector2f{ 10, BOARD_HEIGHT });
  rightVerticalLine.setPosition(sf::Vector2f{ 400, BOARD_HEIGHT });
  rightVerticalLine.setFillColor(sf::Color::Red);

  topHorizontalLine.setSize(sf::Vector2f{ BOARD_WIDTH, 10});
  topHorizontalLine.setOrigin(sf::Vector2f{ BOARD_WIDTH, 10 });
  topHorizontalLine.setPosition(sf::Vector2f{ BOARD_WIDTH, 200 });
  topHorizontalLine.setFillColor(sf::Color::Red);

  middleHorizontalLine.setSize(sf::Vector2f{ BOARD_WIDTH, 10});
  middleHorizontalLine.setOrigin(sf::Vector2f{ BOARD_WIDTH, 10 });
  middleHorizontalLine.setPosition(sf::Vector2f{ BOARD_WIDTH, 400 });
  middleHorizontalLine.setFillColor(sf::Color::Red);

  bottomHorizontalLine.setSize(sf::Vector2f{ BOARD_WIDTH, 10});
  bottomHorizontalLine.setOrigin(sf::Vector2f{ BOARD_WIDTH, 10 });
  bottomHorizontalLine.setPosition(sf::Vector2f{ BOARD_WIDTH, 600 });
  bottomHorizontalLine.setFillColor(sf::Color::Red);

  font.loadFromFile("./assets/fonts/samantha.ttf");
  text.setFont(font);
  text.setString("UNDO");
  text.setFillColor(sf::Color::Blue);
  text.setCharacterSize(80);
  text.setPosition(sf::Vector2f{300, 650});
  sf::FloatRect textRect = text.getLocalBounds();
  text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);

  window.draw(leftVerticalLine);
  window.draw(rightVerticalLine);
  window.draw(topHorizontalLine);
  window.draw(middleHorizontalLine);
  window.draw(bottomHorizontalLine);
  window.draw(text);
}

void GUIRunner::drawBoardState(sf::RenderWindow & window) {
  for (int i = 0; i < MAX; i++) {
    char state = currentGame.getBoard()[i];
    if(state != EMPTY) {
      if (static_cast<BP>(i) == BP::TL) drawSquareOrCircle(sf::Vector2f{0, 0}, state, window);
      if (static_cast<BP>(i) == BP::T) drawSquareOrCircle(sf::Vector2f{200, 0}, state, window);
      if (static_cast<BP>(i) == BP::TR) drawSquareOrCircle(sf::Vector2f{400, 0}, state, window);
      if (static_cast<BP>(i) == BP::ML) drawSquareOrCircle(sf::Vector2f{0, 200}, state, window);
      if (static_cast<BP>(i) == BP::M) drawSquareOrCircle(sf::Vector2f{200, 200}, state, window);
      if (static_cast<BP>(i) == BP::MR) drawSquareOrCircle(sf::Vector2f{400, 200}, state, window);
      if (static_cast<BP>(i) == BP::BL) drawSquareOrCircle(sf::Vector2f{0, 400}, state, window);
      if (static_cast<BP>(i) == BP::B) drawSquareOrCircle(sf::Vector2f{200, 400}, state, window);
      if (static_cast<BP>(i) == BP::BR) drawSquareOrCircle(sf::Vector2f{400, 400}, state, window);
    }
  }
}

void GUIRunner::drawSquareOrCircle(const sf::Vector2f & position, char state, sf::RenderWindow & window) {
  if (state == O) {
    sf::CircleShape circle;
    circle.setPosition(sf::Vector2f{position.x + 50, position.y + 50});
    circle.setRadius(50);
    circle.setFillColor(sf::Color::Green);
    window.draw(circle);
  } else if (state == X) {
    sf::RectangleShape square;
    square.setPosition(sf::Vector2f{position.x + 50, position.y + 50});
    square.setSize(sf::Vector2f{100, 100});
    square.setFillColor(sf::Color::Blue);
    window.draw(square);
  }
}

void GUIRunner::handleMouseInput(sf::RenderWindow & window, sf::Event & event) {
  if(event.type == sf::Event::MouseButtonReleased) {
    sf::Vector2i position = sf::Mouse::getPosition(window);

    if(position.y > 0 && position.y < 200) {
      if (position.x < 200) setGame(cManager.makePlay(currentGame, BP::TL));
      if (position.x > 200 && position.x < 400) setGame(cManager.makePlay(currentGame, BP::T));
      if (position.x > 400 && position.x < 600) setGame(cManager.makePlay(currentGame, BP::TR));
    } else if (position.y > 200 && position.y < 400) {
      if (position.x < 200) setGame(cManager.makePlay(currentGame, BP::ML));
      if (position.x > 200 && position.x < 400) setGame(cManager.makePlay(currentGame, BP::M));
      if (position.x > 400 && position.x < 600) setGame(cManager.makePlay(currentGame, BP::MR));
    } else if (position.y > 400 && position.y < 600) {
      if (position.x < 200) setGame(cManager.makePlay(currentGame, BP::BL));
      if (position.x > 200 && position.x < 400) setGame(cManager.makePlay(currentGame, BP::B));
      if (position.x > 400 && position.x < 600) setGame(cManager.makePlay(currentGame, BP::BR));
    } else if (position.y < 700 && position.x > 0 && position.x < 600) {
      undoLastCommandIfAvailable();
    }
  }
}