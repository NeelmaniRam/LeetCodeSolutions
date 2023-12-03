"""
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
website: https://leetcode.com/problems/single-number/description/
 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 
"""


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int x : nums){
            res^=x;
        }
        return res;

    }
};

//XOR approach used


Runtime
11ms
Beats 88.22%of users with C++

Memory
17.09MB
Beats 67.85%of users with C++

