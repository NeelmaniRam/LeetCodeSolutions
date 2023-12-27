/*



Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

 

Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
 

Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.

*/



class Solution {
private:
    string Word(vector<string>& word){
        string str="";
        for(string part:word){
            str+=part;
        }
        return str;
    }
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1= Word(word1);
        string str2= Word(word2);
        return str1==str2;
        
    }
};


Runtime
0ms
Beats 100.00% of users with C++
Memory
12.16MB
Beats 12.80% of users with C++








class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        if (n1 > 1) {
            for (int i = 1; i < n1; ++i) {
                word1[0] += word1[i];
            }
        }
        if (n2 > 1) {
            for (int i = 1; i < n2; ++i) {
                word2[0] += word2[i];
            }
        }
        return word1[0] == word2[0];
    }
};
