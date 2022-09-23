#include "leetcode.h"

#include <map>
#include <set>

namespace algo {
  bool leetcode::isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length())
      return false;

    std::map<char, char> hash;
    std::set<char> set;

    for (int i = 0; i < s.length(); ++i) {
      if (set.count(t[i]) == 1)
        continue;

      hash[s[i]] = t[i];
      set.insert(t[i]);
    }

    for (int i = 0; i < t.length(); ++i)
      s[i] = hash[s[i]];

    return s == t;
  }

  bool leetcode::isSubsequence(std::string s, std::string t) {
    int j = 0;
    for (int i = 0; i < t.length() && j < s.length(); ++i) {
      if (s[j] == t[i]) {
        ++j;
      }
    }

    return j == s.length();
  }

  int leetcode::pivotIndex(std::vector<int>& nums) {
    int leftSum = 0;
    int sum = 0;

    for (int num : nums)
      sum += num;

    for (int i = 0; i < nums.size(); ++i) {
      // nums[i] = PIVOT
      if (leftSum == sum - leftSum - nums[i])
        return i;

      leftSum += nums[i];
    }

    return -1;
  }
}
