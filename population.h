#ifndef POPULATION_H
#define POPULATION_H

#include "entity.h"

class Population {
  public:
    Population(int screen_width, int screen_height, int sizeC, int sizeF);
    void show();
    //void update();

    std::vector<Creature> getCreatures() const;
    std::vector<Food> getFoods() const;
  private:
    std::vector<Creature> creatures;
    std::vector<Food> foods;
    //int bestCreature;
    //double fitnessSum;
    //int gen;
};

Population::Population(int screen_width, int screen_height,
    int sizeC, int sizeF) {
  for (int i = 0; i < sizeC; i++) {
    creatures.push_back(Creature(screen_width, screen_height));
  }
  for (int i = 0; i < sizeF; i++) {
    foods.push_back(Food(screen_width, screen_height));
  }
}

void Population::show() {
  for (auto& creature : creatures) {
    creature.show();
  }
  for (auto& food : foods) {
    food.show();
  }
}

std::vector<Creature> Population::getCreatures() const {
  return creatures;
}

std::vector<Food> Population::getFoods() const {
  return foods;
}

#endif
