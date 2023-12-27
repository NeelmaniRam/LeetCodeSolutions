/*
You are given a 0-indexed array nums consisting of positive integers.

A partition of an array into one or more contiguous subarrays is called good if no two subarrays contain the same number.

Return the total number of good partitions of nums.

Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 8
Explanation: The 8 possible good partitions are: ([1], [2], [3], [4]), ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]), and ([1,2,3,4]).
Example 2:

Input: nums = [1,1,1,1]
Output: 1
Explanation: The only possible good partition is: ([1,1,1,1]).
Example 3:

Input: nums = [1,2,1,3]
Output: 2
Explanation: The 2 possible good partitions are: ([1,2,1], [3]) and ([1,2,1,3]).
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

class Solution {
 public:
  int numberOfGoodPartitions(vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    int ans = 1;
    
    unordered_map<int, int> lastSeen;

    for (int i = 0; i < nums.size(); ++i)
      lastSeen[nums[i]] = i;
    int maxRight = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > maxRight)
        ans = (ans * 2L) % kMod;
      maxRight = max(maxRight, lastSeen[nums[i]]);
    }

    return ans;
  }
};


Runtime
203ms
Beats 97.74% of users with C++
Memory
134.36MB
Beats 94.34% of users with C++