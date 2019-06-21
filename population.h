#ifndef POPULATION_H
#define POPULATION_H

#include "entity.h"

class Population {
  public:
    Population(int screen_width, int screen_height, int size);
    void show();
    //void update();

    std::vector<Creature> getCreatures() const;
  private:
    std::vector<Creature> creatures;
    //int bestCreature;
    //double fitnessSum;
    //int gen;
};

Population::Population(int screen_width, int screen_height, int size) {
  for (int i = 0; i < size; i++) {
    creatures.push_back(Creature(screen_width, screen_height));
  }
}

void Population::show() {
  for (auto& creature : creatures) {
    creature.show();
  }
}

std::vector<Creature> Population::getCreatures() const {
  return creatures;
}

#endif
