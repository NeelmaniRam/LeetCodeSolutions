/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
class Solution {
private:
    bool validchar(char ch){
        if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return 1;
        }
        return 0;
    }
    char lowercase(char ch){
        if( (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
    bool checkPalindrome(string s){
        int st =0;
        int e = s.length()-1;
        while(st<e){
            if(s[st]!=s[e]){
                return 0;
            }
            else{
                st++;
                e--;
            }
        }
        return 1;
    }

public:
    bool isPalindrome(string s) {
        // phaltu character hatane
        string str = "";
        for(int i = 0; i < s.length();i++){
            if(validchar(s[i])){
                str.push_back(s[i]);
            }
        }
        for(int j = 0; j < str.length();j++){
            str[j]= lowercase(str[j]);
        }
        return checkPalindrome(str);

    }
};



Runtime
9ms
Beats 18.63% of users with C++
Memory
7.99MB
Beats 27.12% of users with C++




class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while ( left < right ) {
            if ( !isalnum(s[left]) ) {
                left++;
                continue;
            }
            if  ( !isalnum(s[right]) ) {
                right--;
                continue;
            }
            if ( !( tolower(s[left]) == tolower(s[right]) ) ) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};


Runtime
5ms
Beats 48.51% of users with C++
Memory
7.52MB
Beats 81.71% of users with C++













class Solution {
    private : 
    // check for valid character :
    int valid(char ch){
        if((ch >= 'a' && ch <= 'z')|| (ch >= 'A' && ch <= 'Z')|| (ch >= '0' && ch <= '9'))
        return 1;
        else 
        return 0;
    }
    char convert(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return ch;
        else{
        ch = ch - 'A' + 'a';
        return ch;
        }

    }
    bool check_palindrome(string temp){
        int i = 0;
        int j = temp.length()-1;
        while(i <= j){
            if(temp[i] != temp[j])
            return 0;
            else{
                i++;
                j--;
            }
        }
        return 1;
    }
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i =0 ; i < s.length(); i++){
            if(valid(s[i]))
            temp.push_back(s[i]);
        }
        //converting to lower case : 
        for(int i =0 ; i < temp.length(); i++){
            temp[i] = convert(temp[i]);

        }
        return check_palindrome(temp);
    }
};



Runtime
3ms
Beats 89.82% of users with C++
Memory
8.20MB
Beats 11.60% of users with C++