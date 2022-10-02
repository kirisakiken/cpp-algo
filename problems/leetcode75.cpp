#include "leetcode75.h"
#include <map>
#include <iostream>

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
}
