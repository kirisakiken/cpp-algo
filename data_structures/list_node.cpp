#include "list_node.h"

namespace leetcode {
  ListNode* vectorToLinkedList(const std::vector<int>& values) {
    ListNode* next = nullptr;
    for (int i = values.size() - 1; i >= 0; --i) {
      ListNode* node = new ListNode(values[i], next);
      next = node;
    }

    return next;
  }

  void releaseMemLinkedList(ListNode* head) {
    ListNode* current = head;
    ListNode* next = nullptr;
    while (current != nullptr) {
      next = current->next;
      delete current;
      current = next;
    }
  }
}

