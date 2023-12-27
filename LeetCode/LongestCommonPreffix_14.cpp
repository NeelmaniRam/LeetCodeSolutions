/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
      return "";

    for (int i = 0; i < strs[0].length(); ++i)
      for (int j = 1; j < strs.size(); ++j)
        if (i == strs[j].length() || strs[j][i] != strs[0][i])
          return strs[0].substr(0, i);

    return strs[0];
  }
};



Runtime
0ms
Beats 100.00% of users with C++
Memory
9.67MB
Beats 38.50% of users with C++