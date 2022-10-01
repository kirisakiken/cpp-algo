#include "leetcode75.h"

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
}
