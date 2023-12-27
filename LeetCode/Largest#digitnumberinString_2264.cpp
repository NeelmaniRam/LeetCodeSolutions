/*
You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
 

Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
 

Constraints:

3 <= num.length <= 1000
num only consists of digits.

*/


class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        for(int i=2; i<num.length();i++){
            if(num[i-2]==num[i-1] && num[i-1]==num[i]){
                ans = max(ans, num.substr(i-2,3));
            }
        }
        return ans;
    }
};



Runtime
0ms
Beats 100.00% of users with C++
Memory
6.75MB
Beats 89.56% of users with C++



class Solution {
public:
    string largestGoodInteger(string num) {
    //approch 1:
        int i = 0;
        int j = 2;
        string ans = "";
        int temp = -1;
        while(j<num.size()){
            if(num[i] > temp){ 
                if(num[i] == num[j]){
                    if(num[j-1] == num[j]){
                        ans = "";
                        ans = num.substr(i,3);
                        temp = num[j];
                    }
                }
            }
            i++;
            j++;   
        }
        return ans;
    }
};

Runtime
0ms
Beats 100.00% of users with C++
Memory
6.71MB
Beats 89.56% of users with C++