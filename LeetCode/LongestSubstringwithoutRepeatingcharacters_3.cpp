
/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1);
        int maxlen =0,start=-1;
        for(int i =0; i<s.size(); i++){
            if(dict[s[i]]> start){
                start= dict[s[i]];
            }
            dict[s[i]]=i;
            maxlen=max(maxlen, i-start);
        }
        return maxlen;
    }
};


Runtime
3 ms
Beats 96.59% of users with C++
Memory
8.64 MB
Beats 74.45% of users with C++