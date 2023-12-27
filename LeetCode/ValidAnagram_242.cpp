/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?


*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> frq(26);
        if(s.length()!=t.length()){
            return false;
        }
        for(char str:s){
            frq[str-'a']++;
        }
        for(char str:t){
            if(frq[str-'a']==0){
                return false;
            }
            frq[str-'a']--;
        }
        return true;


    }
};



Runtime
2
ms
Beats
98.77%
of users with C++
Memory
7.82
MB
Beats
20.94%
of users with C++



class Solution {

private:
    int arr[26] = {0};
public:
    bool isAnagram(string s, string t) {
      if (s.size() != t.size()) {
          return false;
      }

      for (int i = 0; i < s.size(); i++) {
          int idx = s[i] - 'a';
          arr[idx]++;
      }

      for (int j = 0; j < t.size(); j++) {
          int idx = t[j] - 'a';
          arr[idx]--;
      }

      for (int k = 0; k < 26; k++) {
          if (arr[k] != 0)
            return false;
      }

      return true;
    }
};










Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.74
MB
Beats
45.96%
of users with C++