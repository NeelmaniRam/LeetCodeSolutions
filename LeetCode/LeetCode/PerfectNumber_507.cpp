/*
A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

 

Example 1:

Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
Example 2:

Input: num = 7
Output: false
 

Constraints:

1 <= num <= 108


*/




class Solution {
public:
    bool checkPerfectNumber(int n){
        if (n <= 1)return false;

        int sum = 1; 

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) {
                    sum += n / i;
                }
            }
        }

        return sum == n;
}

};

Runtime
3ms
Beats 78.91%of users with C++
Memory
6.13MB
Beats 70.50%of users with C++



--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------


class Solution {
public:

    int SumofFactors(int n){
        int sum=0;
        for(int i = 1; i<n; i++){
            if(n % i == 0){
                sum += i ;
            }
        }
        return sum;

    }

    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        int check = SumofPrimeFactors(num);
        if(check == num) return true;
        else return false;

    }
};


Runtime
2073ms
Beats 30.31%of users with C++
Memory
6.20MB
Beats 70.50%of users with C++

--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------




class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;

        int sum = 1;
        for (int i = 2; i*i <= num; i++)
        {
            std::cout << i << ' ' << sum << '\n';
            if (num % i == 0)
                sum += i + num / i;
        }

        return (sum == num);
    }
};


Runtime
39ms
Beats 68.99%of users with C++
Memory
6.54MB
Beats 12.68%of users with C++


--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
