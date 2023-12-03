
/*
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
*/






class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0;i<=(n-1)/2;i++)
        {
            swap(s[i],s[n-1-i]);
        }
    }
};









class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size()-1;
        while(start<end){
            swap(s[start++] , s[end--]);
        }
    }
};





Runtime
19
ms
Beats
51.04%
of users with C++
Memory
23.68
MB
Beats
31.93%
of users with C++




class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int st=0;
        int e=n-1;
        while(st<e){
            swap(s[st],s[e]);
            st++;
            e--;
        }
    }
};


Runtime
15
ms
Beats
79.76%
of users with C++
Memory
23.58
MB
Beats
61.05%
of users with C++