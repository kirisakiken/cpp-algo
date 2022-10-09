#include "node.h"

namespace leetcode {
  Node::Node() = default;
  Node::Node(int val) : val(val) { }
  Node::Node(int val, std::vector<Node*> children) : val(val), children(children) { }
}
