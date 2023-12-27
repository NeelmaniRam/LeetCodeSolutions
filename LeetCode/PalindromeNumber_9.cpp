/*

Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 

Follow up: Could you solve it without converting the integer to a string?
*/


class Solution {
public:
    bool isPalindrome(long x) {
        long rev=0,temp=x;
        if(x<0){
            return false;
        }
        while(x!=0){
            rev = rev*10 + x%10 ;
            x = x/10;
        }
        if(temp==rev)
            return true;
        else
            return false;
    }
};

Runtime
0ms
Beats 100.00% of users with C++
Memory
6.53MB
Beats 10.06% of users with C++



class Solution {
public:
    bool isPalindrome(long x) {
        string s= to_string(x);
        reverse(s.begin(),s.end());
        if(s==to_string(x))
            return true;
        else
            return false;    
    }
};

Runtime
3ms
Beats 93.37% of users with C++
Memory
6.35MB
Beats 39.73% of users with C++