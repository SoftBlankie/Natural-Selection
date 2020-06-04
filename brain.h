#ifndef BRAIN_H
#define BRAIN_H

#include <complex>

class Brain {
  public:
    Brain();
  private:
    std::vector<std::complex<double>> directions;
    int step;
};

Brain::Brain() : step(0) {
  // get directions from pathing algorithm
}

#endif
