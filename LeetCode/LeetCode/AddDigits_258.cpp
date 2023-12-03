/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0


*/

class Solution {
public:


    int SumOfDigits(int num) {
        int sum=0;
        while(num!=0){
            int i = num%10;
            sum+=i;
            num/=10;
        }
        return sum;

    }
    
    int addDigits(int num) {
        
        while(num>9){
            num = SumOfDigits(num);
        }
        return num;
    }
    
};


Runtime
5ms
Beats 14.57%of users with C++
Memory
6.26MB
Beats 58.03%of users with C++






class Solution {
public:
    int addDigits(int num) {
        long long n=num;
        while(n>9){
           long long int sum=0;
          while(n>0){
          sum+=(n%10);
          n=n/10;
        }
        n=sum;
        }
        
       
        return n;
    }
};


Runtime
0ms
Beats 100.00%of users with C++
Memory
6.39MB
Beats 27.74%of users with C++




class Solution {
public:
    int addD(int x)
        {
            int dS=0;
            while(x>0)
            {
                dS+=x%10;
                x=x/10;
            }
            return dS;
        }
    int addDigits(int num) {
        int res=num;
        while(res>9)
        {
            res=addD(res);
        }
        return res;
    }
};