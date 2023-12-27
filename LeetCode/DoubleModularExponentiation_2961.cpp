/*
You are given a 0-indexed 2D array variables where variables[i] = [ai, bi, ci, mi], and an integer target.

An index i is good if the following formula holds:

0 <= i < variables.length
((aibi % 10)ci) % mi == target
Return an array consisting of good indices in any order.

 

Example 1:

Input: variables = [[2,3,3,10],[3,3,3,1],[6,1,1,4]], target = 2
Output: [0,2]
Explanation: For each index i in the variables array:
1) For the index 0, variables[0] = [2,3,3,10], (23 % 10)3 % 10 = 2.
2) For the index 1, variables[1] = [3,3,3,1], (33 % 10)3 % 1 = 0.
3) For the index 2, variables[2] = [6,1,1,4], (61 % 10)1 % 4 = 2.
Therefore we return [0,2] as the answer.
Example 2:

Input: variables = [[39,3,1000,1000]], target = 17
Output: []
Explanation: For each index i in the variables array:
1) For the index 0, variables[0] = [39,3,1000,1000], (393 % 10)1000 % 1000 = 1.
Therefore we return [] as the answer.
 

Constraints:

1 <= variables.length <= 100
variables[i] == [ai, bi, ci, mi]
1 <= ai, bi, ci, mi <= 103
0 <= target <= 103
*/

class Solution {
 public:
  vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
    vector<int> ans;
    for (int i = 0; i < variables.size(); ++i) {
      const int a = variables[i][0];
      const int b = variables[i][1];
      const int c = variables[i][2];
      const int m = variables[i][3];
      if (modPow(modPow(a, b, 10), c, m) == target)
        ans.push_back(i);
    }
    return ans;
  }

 private:
  long modPow(long x, long n, int mod) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % mod, (n - 1), mod) % mod;
    return modPow(x * x % mod, (n / 2), mod) % mod;
  }
};



Runtime
8
ms
Beats
70.02%
of users with C++
Memory
18.97
MB
Beats
33.01%
of users with C++
