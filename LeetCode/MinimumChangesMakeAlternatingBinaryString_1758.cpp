/*
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

 

Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.
Example 2:

Input: s = "10"
Output: 0
Explanation: s is already alternating.
Example 3:

Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".
 

Constraints:

1 <= s.length <= 104
s[i] is either '0' or '1'.
*/


class Solution {
public:
    int minOperations(string s) {
       int m=0;int n=0;
       for(int i =0;i< s.size();i++){
           if(i%2==0 && s[i]=='1') ++m;
           else if(i%2==1 && s[i]=='0') ++m;
           if(i%2==0 && s[i]=='0') ++n;
           else if(i%2==1 && s[i]=='1') ++n;
       }
       return min(m,n);
    }
};


Runtime
6
ms
Beats
35.61%
of users with C++
Memory
7.60
MB
Beats
12.76%
of users with C++



class Solution {
public:
    int minOperations(string s) {
        //very tricky
        int cost10;
        for(int i=0;i<s.length();i++) {
            if(s[i]-'0'==i%2) {
                cost10++;
            }
        }
        int cost01=s.length()-cost10;
        return min(cost01,cost10);
    }
};


Runtime
3
ms
Beats
78.34%
of users with C++
Memory
7.38
MB
Beats
45.10%
of users with C++





class Solution {
public:
        int minOperations(string s) {
        int res = 0, n = s.length();
        for (int i = 0; i < n; ++i)
            if (s[i] - '0' != i % 2)
                res++;
        return min(res, n - res);
    }
};