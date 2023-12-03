/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/







class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length()<3 || numRows==1){
            return s;
        }
        vector<string> vec(numRows);
        int i=0,j=0;
        string res="";
        while(i<s.length()){
            while(j<numRows && i<s.length()){
                vec[j++] += s[i++];
            }
            if(j==numRows){
                j = numRows - 2;
            }
            while(j>=0 && i<s.length()){
                vec[j--]+=s[i++];
            }
            if(j==-1){
                j=1;
            }
        }    
        for(int i=0;i<vec.size();i++){
            res +=vec[i];
        }
        return res;
    }
};




Runtime
7ms
Beats 81.98% of users with C++
Memory
10.70MB
Beats 61.77% of users with C++








class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        for (size_t i = 0; i < numRows; ++i) {
            for (size_t j = i; j < s.size(); j += 2 * (numRows - 1 - j % (numRows - 1))) {
                res.push_back(s[j]);
            }
        }
        return res;
    }
};

Runtime
6ms
Beats 86.59% of users with C++
Memory
8.42MB
Beats 73.68% of users with C++


class Solution {
public:
    string convert(string s, int numRows) {
         string result="";
        if(numRows==1)
			return s;
        int step1,step2;
        int len=s.size();
        for(int i=0;i<numRows;++i){
            step1=(numRows-i-1)*2;
            step2=(i)*2;
            int pos=i;
            if(pos<len)
                result+=s.at(pos);
            while(1){
                pos+=step1;
                if(pos>=len)
                    break;
				if(step1)
					result+=s.at(pos);
                pos+=step2;
                if(pos>=len)
                    break;
				if(step2)
					result+=s.at(pos);
            }
        }
        return result;
    }
};




Runtime
7ms
Beats 81.98% of users with C++
Memory
8.32MB
Beats 79.50% of users with C++

