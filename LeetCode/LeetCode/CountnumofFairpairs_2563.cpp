/*
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
 

Constraints:

1 <= nums.length <= 105
nums.length == n
-109 <= nums[i] <= 109
-109 <= lower <= upper <= 109
*/



class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    // nums[i] + nums[j] == nums[j] + nums[i], so the condition that i < j
    // degrades to i != j and we can sort the array.
    ranges::sort(nums);
    return countLess(nums, upper) - countLess(nums, lower - 1);
  }

 private:
  long long countLess(const vector<int>& nums, int sum) {
    long long res = 0;
    for (int i = 0, j = nums.size() - 1; i < j; ++i) {
      while (i < j && nums[i] + nums[j] > sum)
        --j;
      res += j - i;
    }
    return res;
  }
};

Runtime
134ms
Beats 80.34%of users with C++
Memory
56.93MB
Beats 31.28%of users with C++






class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            auto j = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto k = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1);
            ans += k - j;
        }
        return ans;
    }
};

Runtime
192ms
Beats 66.15%of users with C++
Memory
57.07MB
Beats 18.46%of users with C++


