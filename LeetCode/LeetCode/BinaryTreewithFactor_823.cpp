/*
Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 


*/


class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        static const int M = 1e9 + 7;
        sort(A.begin(), A.end());
        unordered_map<int, int64_t> dp;
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0 && dp.count(A[i] / A[j])) {
                   dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % M;
                }
            }
        }
        return accumulate(dp.cbegin(), dp.cend(), 0L,
                          [](int64_t x, const pair<int, int>& p) {
                              return x + p.second;
                          }) % M;
    
    }
};

Runtime
42ms
Beats 76.38%of users with C++
Memory
9.46MB
Beats 65.35%of users with C++