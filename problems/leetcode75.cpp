#include "leetcode75.h"
#include <map>
#include <unordered_set>

namespace leetcode75 {
  std::vector<int> runningSum(const std::vector<int>& nums) {
    std::vector<int> result;

    result.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      result.push_back(nums[i] + result[i - 1]);
    }

    return result;
  }

  int pivotIndex(const std::vector<int>& nums) {
    int leftSum = 0;
    int sum = 0;
    for (int value : nums)
      sum += value;

    for (int i = 0; i < nums.size(); ++i) {
      if (leftSum == (sum - leftSum - nums[i]))
        return i;

      leftSum += nums[i];
    }

    return -1;
  }

  bool isIsomorphic(const std::string& s, const std::string& t) {
    if (s.length() != t.length())
      return false;

    std::map<char, char> map;
    for (int i = 0; i < s.length(); ++i) {
      if (map.find(s[i]) == map.end()) {
        // traverse map to see if value already exists
        for (const auto& v : map) {
          if (v.second == t[i])
            return false;
        }

        map[s[i]] = t[i];
      }

      if (map[s[i]] != t[i])
        return false;
    }

    return true;
  }

  bool isSubsequence(const std::string& s, std::string t) {
    if (s.length() > t.length())
      return false;

    auto index = s.begin();
    auto it = t.begin();

    while (it != t.end()) {
      if (*it != *index) {
        it = t.erase(it);
      } else {
        ++it;

        if (index == s.end())
          break;

        ++index;
      }
    }

    return s == t;
  }

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr && list2 == nullptr)
      return nullptr;
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;

    ListNode* head = list1->val < list2->val
        ? list1
        : list2;

    ListNode* nextA;
    ListNode* nextB;
    if (head == list1) {
      nextA = head->next;
      nextB = list2;
    } else {
      nextA = list1;
      nextB = head->next;
    }

    ListNode* current = head;
    while (nextA != nullptr && nextB != nullptr) {
      if (nextA->val < nextB->val) {
        current->next = nextA;
        current = current->next;
        nextA = current->next;
      } else {
        current->next = nextB;
        current = current->next;
        nextB = current->next;
      }
    }

    if (nextA != nullptr)
      current->next = nextA;

    if (nextB != nullptr)
      current->next = nextB;

    return head;
  }

  ListNode* reverseList(ListNode* head) {
    ListNode* previous = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
      next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }

    return previous;
  }

  ListNode* middleNode(ListNode* head) {
    int count = 1;

    ListNode* current = head;
    while (current != nullptr) {
      count++;
      current = current->next;
    }

    int mid = count % 2 == 0
        ? count / 2
        : (count / 2) + 1;
    current = head;
    for (int i = 0; i < mid; ++i) {
      current = current->next;
    }

    return current;
  }

  ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
      return nullptr;

    std::unordered_set<ListNode*> nodes;
    while (head->next != nullptr) {
      if (nodes.find(head->next) != nodes.end())
        return head->next;

      nodes.insert(head);
      head = head->next;
    }

    return nullptr;
  }
}
