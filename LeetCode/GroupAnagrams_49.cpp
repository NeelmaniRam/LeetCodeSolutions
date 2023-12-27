/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/


class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> keyToAnagrams;

    for (const string& str : strs) {
      string key = str;
      ranges::sort(key);
      keyToAnagrams[key].push_back(str);
    }

    for (const auto& [_, anagrams] : keyToAnagrams)
      ans.push_back(anagrams);

    return ans;
  }
};


Runtime
20ms
Beats 45.04% of users with C++
Memory
20.07MB
Beats 81.94% of users with C++




class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> final_result;
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<strs.size(); i++) {
            auto x = strs[i];
            sort(x.begin(), x.end());
            mp[x].push_back(strs[i]);
        }

        for(auto i:mp) {
            final_result.push_back(i.second);
        }
        return final_result;
    }
};


Runtime
30ms
Beats 60.39% of users with C++
Memory
21.30MB
Beats 36.09% of users with C++