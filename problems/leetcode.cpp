#include "leetcode.h"

#include <map>
#include <set>

namespace leetcode {
  bool isIsomorphic(std::string s, std::string t) {
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

  bool validAnagram(const std::string &a, const std::string &b) {
    if (a.length() != b.length())
      return false;

    std::map<char, int> hashA;
    std::map<char, int> hashB;

    for (char c : a) {
      if (hashA[c] == 0) {
        hashA[c] = 1;
        continue;
      }

      ++hashA[c];
    }

    for (char c : b) {
      if (hashB[c] == 0) {
        hashB[c] = 1;
        continue;
      }

      ++hashB[c];
    }

    for (char c : a) {
      if (hashA[c] != hashB[c])
        return false;
    }

    return true;
  }

  bool isSubsequence(std::string s, std::string t) {
    int j = 0;
    for (int i = 0; i < t.length() && j < s.length(); ++i) {
      if (s[j] == t[i]) {
        ++j;
      }
    }

    return j == s.length();
  }

  int pivotIndex(std::vector<int>& nums) {
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

  std::vector<int> runningSum(std::vector<int> &nums) {
    int sum = 0;
    std::vector<int> res;
    res.push_back(nums[0]);

    for (int i = 1; i < nums.size(); ++i)
      res.push_back(res[i - 1] + nums[i]);

    return res;
  }
}
