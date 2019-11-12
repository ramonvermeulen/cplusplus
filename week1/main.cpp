#include <SFML/Graphics.hpp>
#include "ball.hpp"

sf::Vector2f Vector2i_to_Vector2f(const sf::Vector2i & target) {
    return sf::Vector2f(
        static_cast<float>(target.x),
        static_cast<float>(target.y)
    );
}

void handle_event(sf::RenderWindow & window, ball & my_ball) {
    sf::Event event;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        my_ball.move(sf::Vector2f{ -2.5, 0 });
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        my_ball.move(sf::Vector2f{ +2.5, 0 });
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        my_ball.move(sf::Vector2f{ 0, -2.5 });
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        my_ball.move(sf::Vector2f{ 0, +2.5 });                
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        my_ball.jump(Vector2i_to_Vector2f(sf::Mouse::getPosition(window)));
    }
    
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window"};
    ball my_ball{ sf::Vector2f{ 320.0, 240.0 }, 5.0 };

    while( window.isOpen() ) {
        handle_event(window, my_ball);

        window.clear();
        my_ball.draw(window);
        window.display();

        sf::sleep(sf::milliseconds(20));
    }
    return 0;
}