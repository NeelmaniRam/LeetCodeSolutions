/*
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 

Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
 

Constraints:

1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.
*/


class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    if (s.length() != goal.length())
      return false;
    if (s == goal && hasDuplicateLetters(s))
      return true;

    vector<int> diffIndices;

    for (int i = 0; i < s.length(); ++i)
      if (s[i] != goal[i])
        diffIndices.push_back(i);

    return diffIndices.size() == 2 &&
           s[diffIndices[0]] == goal[diffIndices[1]] &&
           s[diffIndices[1]] == goal[diffIndices[0]];
  }

 private:
  bool hasDuplicateLetters(const string& s) {
    vector<int> count(26);
    for (const char c : s)
      ++count[c - 'a'];
    return ranges::any_of(count, [](int freq) { return freq > 1; });
  }
};


Runtime
5ms
Beats 52.21% of users with C++
Memory
7.30MB
Beats 41.88% of users with C++




class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length() || s.size() <= 1){return false;}
        if(s==goal){unordered_set<char> S(s.begin(),s.end());return S.size() < s.length();}
        vector<int> Index;
        for(int i=0;i<s.size();i++){if(s[i]!=goal[i]){Index.push_back(i);}}
        if(Index.size()!=2){return false;}
        swap(s[Index[0]],s[Index[1]]);
        return s == goal;
    }
};



Runtime
6ms
Beats 26.94% of users with C++
Memory
7.20MB
Beats 82.47% of users with C++