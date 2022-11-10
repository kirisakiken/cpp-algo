#pragma once

#include <vector>

namespace leetcode {
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode* vectorToLinkedList(const std::vector<int>& values);

  void releaseMemLinkedList(ListNode* head);
}
