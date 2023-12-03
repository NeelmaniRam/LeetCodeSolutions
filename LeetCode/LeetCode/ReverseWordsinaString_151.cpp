/*

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 
*/








class Solution {

private:
  void reverseWords(string& s, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      while (i < j || i < n && s[i] == ' ')
        ++i;
      while (j < i || j < n && s[j] != ' ')  
        ++j;
      reverse(s.begin() + i, s.begin() + j); 
    }
  }
  string cleanSpaces(string& s, int n) {
    int i = 0;
    int j = 0;

    while (j < n) {
      while (j < n && s[j] == ' ')  
        ++j;
      while (j < n && s[j] != ' ') 
        s[i++] = s[j++];
      while (j < n && s[j] == ' ')  
        ++j;
      if (j < n)  
        s[i++] = ' ';
    }

    return s.substr(0, i);
  }

public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        reverseWords(s, s.length());        
        return cleanSpaces(s, s.length());
    }
};



Runtime
3ms
Beats 86.26% of users with C++
Memory
7.59MB
Beats 86.36% of users with C++






class Solution {
public:
    string reverseWords(string s) {
        string str="";
        vector<string> v;
        str.clear();
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                str.push_back(s[i]);
            }
            else{
                if(!str.empty()){
                    cout<<str<<endl;
                    v.push_back(str);
                }
                str.clear();
            }
        }
        if(!str.empty()){
            v.push_back(str);
            cout<<str;
        }
        str.clear();
        //cout<<v.size();
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<endl;
            str+=v[i];
            str+=" ";
        }
        str.pop_back();
        return str;
    }
};




Runtime
8ms
Beats 27.03% of users with C++
Memory
8.44MB
Beats 48.70% of users with C++






class Solution {
public:
    string reverseWords(string s) {
    int n = s.length();
    stack<string>st;
    string temp ="";
    string ans = "";
    for(int i =0;i<n;i++){
	    if(s[i] == ' '){
            if(temp.length() > 0)
                st.push(temp);
            temp ="";
        }
	    else{
		    temp+=s[i];
        }
    }

    ans+=temp;

    while(!st.empty()){
	    ans+= " " + st.top();
	    st.pop();
    }
    if(ans.length() != 0 && ans[0] == ' ')
        ans=ans.substr(1);
    return ans;
    }
};





Runtime
2ms
Beats 87.65% of users with C++
Memory
8.14MB
Beats 59.00% of users with C++