/*
The Longest Palindromic Substring LeetCode Solution – “Longest Palindromic Substring” states that You are Given a string s, return the longest palindromic substring in s.

Note: A palindrome is a word that reads the same backward as forwards, e.g. madam.

Example:
Longest Palindromic Substring LeetCode Solution

 

s = "babad"
"bab"
Explanation:

All the unique palindromic substrings are: “b”, “a”, “d”, “bab”, “aba”.

Out of these, “bab” and “aba” are the longest substrings.

s = "cbbd"
"bb"
Explanation:

All the unique palindromic substrings are: “c”, “b”, “d”, “bb”.

Out of these, “bb” is the longest substrin
*/



class Solution {
public:
    string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0) return "";

    bool dp[n][n];
    int start = 0;
    int max_length = 1;

    // Initialize the DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = false;
        }
    }

    // All substrings of length 1 are palindromic
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            max_length = 2;
        }
    }

    // Check for substrings of length 3 or more
    for (int k = 3; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;

            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
                if (k > max_length) {
                    start = i;
                    max_length = k;
                }
            }
        }
    }

    return s.substr(start, max_length);
}

        
    
};


Runtime
124ms
Beats 47.13%of users with C++
Memory
8.46MB
Beats 65.02%of users with C++




class Solution {
public:
    bool check(string &s, int i, int j){
        while (i <= j){
            if (s[i] != s[j]){
                return false;}
        i++, j--;}
    return true;}
    string longestPalindrome(string s){
        int n = s.length();
        int max_len = 0;
        int starting_index = 0;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (check(s, i, j)){
                    if (j - i + 1 > max_len){
                        max_len = j - i + 1;
                        starting_index = i;}
            }
        }
    }
    return s.substr(starting_index, max_len);
}
};




Runtime
1042ms
Beats 8.46%of users with C++
Memory
7.18MB
Beats 86.68%of users with C++