/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/


class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
    }
};

Runtime
3ms
Beats 42.02% of users with C++
Memory
6.45MB
Beats 33.78% of users with C++





class Solution {
 public:
  double myPow(double x, long n) {
    if (n == 0)
      return 1;
    if (n < 0)
      return 1 / myPow(x, -n);
    if (n % 2 == 1)
      return x * myPow(x, n - 1);
    return myPow(x * x, n / 2);
  }
};


Runtime
0ms
Beats 100.00% of users with C++
Memory
6.26MB
Beats 95.28% of users with C++