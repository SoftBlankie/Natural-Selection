#ifndef ENTITY_H
#define ENTITY_H

#include <complex>
#include <random>

class Creature {
  public:
    Creature(int screen_width, int screen_height);
    void show();
    //void move();
    //void update();
    
    sf::CircleShape getShape() const;
  private:
    sf::CircleShape shape;

    std::complex<double> pos;
    std::complex<double> vel;
    std::complex<double> acc;

    bool dead;
    bool isBest;

    double fitness;
};

Creature::Creature(int screen_width, int screen_height) {
  // random pos around outer ring of screen
  double randX, randY;
  if (rand()%2) {
    randX = rand()%(screen_width-10+1)+10;
    if (rand()%2) {
      randY = screen_height-10;
    } else {
      randY = 2;
    }
  } else {
    randY = rand()%(screen_height-10+1)+10;
    if (rand()%2) {
      randX = screen_width-10;
    } else {
      randX = 2;
    }
  }
  pos = std::complex<double>(randX,randY);
  show();
  vel = 0;
  acc = 0;

  dead = false;
  isBest = false;

  fitness = 0;
}

void Creature::show() {
  shape.setRadius(4);
  if (isBest) {
    shape.setFillColor(sf::Color(220,20,60));
  } else {
    shape.setFillColor(sf::Color(255,255,255));
  }
  shape.setPosition(std::real(pos), std::imag(pos));
}

sf::CircleShape Creature::getShape() const {
  return shape;
}

#endif
