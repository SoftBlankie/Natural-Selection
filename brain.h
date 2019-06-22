#ifndef BRAIN_H
#define BRAIN_H

#include <complex>

class Brain {
  public:
    Brain();
  private:
    std::vector<std::complex<double>> directions;
};

Brain::Brain() {
  // get directions from A* algorithm
}

#endif
