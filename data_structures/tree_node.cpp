//
// Created by omen on 9.10.2022.
//

#include "tree_node.h"

namespace leetcode {
  TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) { }
  TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
  TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) { }
}
