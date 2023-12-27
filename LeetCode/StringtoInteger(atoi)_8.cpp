/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 

Example 1:

Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
Example 2:

Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
Example 3:

Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
 

Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/






class Solution {
public:
    int myAtoi(string s) {
       int sign = 1;
      int base = 0;
      int i = 0;
      int n = s.size();
      while(i < n && s[i] == ' '){
         i++;
      }
      if(s[i] == '-' || s[i] == '+') sign = 1 - 2*(s[i++] =='-');
      while(s[i] >= '0' && s[i] <='9'){
         if(base > INT_MAX/10 || base == INT_MAX/10 && s[i]- '0' > INT_MAX %10){
            if(sign == 1)return INT_MAX;
               return INT_MIN;
            }
            base = (base * 10) + (s[i++] - '0');
         }
         return base * sign;
   }
};


Runtime
3ms
Beats 57.86% of users with C++
Memory
6.63MB
Beats 37.32% of users with C++




class Solution {
public:
        int myAtoi(string str) {
        int sign = 1, pt = 0; 
        long long base = 0;
        while (str[pt] == ' ')
            pt++;
        if (str[pt] == '+' || str[pt] == '-')
            sign = 1 - 2 * (str[pt++] == '-');
        while (str[pt] >= '0' && str[pt] <= '9') {
            base = 10 * base + (str[pt++] - '0');
            if (base > INT_MAX)
                return sign == 1 ? INT_MAX : INT_MIN;
        }
        return (int) (base * sign);
    }
};




Runtime
0ms
Beats 100.00% of users with C++
Memory
6.60MB
Beats 68.06% of users with C++