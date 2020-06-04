#ifndef PATHFIND_H
#define PATHFIND_H

#include <complex>
#include <algorithm>

struct Node {
    Node();
    Node parent;
    std::complex<double> position;

    double g, h, f;
};

Node::Node(Node parent, std::complex<double> position) : g(0), h(0), f(0) {
  this.parent = parent;
  this.position = position;
}

std::vector<std::complex<double>> pathfind(grid, start, end) {
  start_node = Node(NULL, start);
  end_node = Node(NULL, end);

  std::vector<Node> open_list;
  std::vector<Node> closed_list;

  open_list.push_back(start_node);

  while (open_list) {
    Node current_node = open_list[0];
    current_index = 0;
    for (int i = 0; i < open_list.size(); i++) {
      if (open_list[i].f < current_node.f) {
        current_node = open_list[i];
        current_index = i;
      }
    }

    open_list.erase(open_list.begin()+current_index-1);
    closed_list.push_back(current_node);

    if (current_node = end_node) {
      std::vector<std::complex<double>> path;
      Node current = current_node;
      while (current) {
        path.push_back(current.position);
        current = current.parent;
      }
      std::reverse(path.begin(), path.end());
      return path;
    }

    std::vector<Node> children;


  }
}

#endif
