/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        vector<int> cnt(n, 0);
        for(int i = 0; i < n; i++){ 
            switch(s[i]){
                case 'I':
                    cnt[i] = 1;
                    break;
                case 'V':
                    cnt[i] = 5;
                    break;
                case 'X':
                    cnt[i] = 10;
                    break;
                case 'L':
                    cnt[i] = 50;
                    break;
                case 'C':
                    cnt[i] = 100;
                    break;
                case 'D':
                    cnt[i] = 500;
                    break;
                case 'M':
                    cnt[i] = 1000;
                    break;
            }
        }
        int sum = 0;
        for(int i = 0; i < n - 1; i++) {
            if(cnt[i] >= cnt[i+1]){
                sum += cnt[i];
            }
            else {
                sum -= cnt[i];
            }
        }
        sum += cnt[n-1];
        return sum;
    }
};


Runtime
3ms
Beats 93.28% of users with C++
Memory
6.54MB
Beats 76.23% of users with C++



class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> m = {{'I', 1}, {'V', 5},{'X', 10},{'L', 50},
        {'C', 100},{'D', 500},{'M', 1000}};
        
        int total = 0;
        for(int i = 0; i < s.length(); i++){
            if(m[s[i+1]] <= m[s[i]])  total += m[s[i]]; 
            else  total -= m[s[i]];  
        }
        return total;
    }
};



Runtime
16ms
Beats 23.45% of users with C++
Memory
8.98MB
Beats 7.79% of users with C++