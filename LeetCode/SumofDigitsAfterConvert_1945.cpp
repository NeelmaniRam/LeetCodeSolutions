


/*
You are given a string s consisting of lowercase English letters, and an integer k.

First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.

 

Example 1:

Input: s = "iiii", k = 1
Output: 36
Explanation: The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.
Example 2:

Input: s = "leetcode", k = 2
Output: 6
Explanation: The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.
Example 3:

Input: s = "zbax", k = 2
Output: 8
 
*/


class Solution {
public:
    int getLucky(string s, int k) {
        int total = accumulate(cbegin(s), cend(s), 0,
                               [](const auto& total, const auto& x) {
                                   const auto num = x - 'a' + 1;
                                   return total + num / 10 + num % 10;
                               });
        while (--k && total > 9) {
            int new_total = 0;
            for (; total; total /= 10) {
                new_total += total % 10;
            }
            total = new_total;
        }
        return total;
    }
};




Runtime
0ms
Beats 100.00%of users with C++
Memory
6.58MB
Beats 52.15%of users with C++







class Solution {
public:
    int getLucky(string s, int k) {
        char ch;
        int num, replace = 0;
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            ch = s[i];
            num = ch - 96;
            while (num != 0) {
                sum += num % 10;
                num /= 10;
            }
        }

        for (int i = 1; i < k; i++) {
            while (sum != 0) {
                replace += sum % 10;
                sum /= 10;
            }
            sum = replace;
            replace = 0;
        }

        return sum;
    }
};





Runtime
0ms
Beats 100.00%of users with C++
Memory
6.72MB
Beats 21.77%of users with C++