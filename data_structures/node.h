#pragma once

#include <vector>

namespace leetcode {
  class Node {
   public:
    int val;
    std::vector<Node*> children;
    Node();
    explicit Node(int val);
    Node(int val, std::vector<Node*> children);
  };
}
