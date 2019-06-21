#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

#include "entity.h"

class Natural {
  public:
    Natural();

    void handleInputEvents();

    void run();
    void draw();
  private:
    std::string title;
    int screen_width;
    int screen_height;
    sf::RenderWindow window;
    bool isFullscreen;

    Creature creature;
};

Natural::Natural() : screen_width(1440), screen_height(900),
  creature(screen_width, screen_height){
  title = "Natural Selection";
  window.create(sf::VideoMode(screen_width,screen_height,32), title, sf::Style::Fullscreen);
  window.setFramerateLimit(100);
  isFullscreen = true;

  //creature = Creature(screen_width, screen_height);
}

void Natural::handleInputEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Escape) {
          window.close();
        } else if (event.key.code == sf::Keyboard::F) {
          if (isFullscreen) {
            window.create(sf::VideoMode(screen_width,screen_height,32), title, sf::Style::Default);
            isFullscreen = false;
          } else {
            window.create(sf::VideoMode(screen_width,screen_height,32), title, sf::Style::Fullscreen);
            isFullscreen = true;
          }
        }
        break;
      default:
        break;
    }
  }
}

void Natural::run() {
  while (window.isOpen()) {
    handleInputEvents();
    draw();
  }
}

void Natural::draw() {
  window.clear(sf::Color::Black);

  creature.show();
  window.draw(creature.getShape());

  window.display();
}

int main() {
  srand(time(NULL));
  Natural natural;
  natural.run();
  return 0;
}
