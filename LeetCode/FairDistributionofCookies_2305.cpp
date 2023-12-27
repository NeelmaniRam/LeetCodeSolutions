/*
You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

Return the minimum unfairness of all distributions.

 

Example 1:

Input: cookies = [8,15,10,20,8], k = 2
Output: 31
Explanation: One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
Example 2:

Input: cookies = [6,1,3,2,2,4,1,2], k = 3
Output: 7
Explanation: One optimal distribution is [6,1], [3,2,2], and [4,1,2]
- The 1st child receives [6,1] which has a total of 6 + 1 = 7 cookies.
- The 2nd child receives [3,2,2] which has a total of 3 + 2 + 2 = 7 cookies.
- The 3rd child receives [4,1,2] which has a total of 4 + 1 + 2 = 7 cookies.
The unfairness of the distribution is max(7,7,7) = 7.
It can be shown that there is no distribution with an unfairness less than 7.
 

Constraints:

2 <= cookies.length <= 8
1 <= cookies[i] <= 105
2 <= k <= cookies.length
*/

class Solution {
 public:
  int distributeCookies(vector<int>& cookies, int k) {
    int ans = INT_MAX;
    dfs(cookies, 0, k, vector<int>(k), ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& cookies, int s, int k, vector<int>&& children,
           int& ans) {
    if (s == cookies.size()) {
      ans = min(ans, ranges::max(children));
      return;
    }

    for (int i = 0; i < k; ++i) {
      children[i] += cookies[s];
      dfs(cookies, s + 1, k, move(children), ans);
      children[i] -= cookies[s];
    }
  }
};

Runtime
1001ms
Beats 32.83% of users with C++
Memory
7.12MB
Beats 82.46% of users with C++



class Solution {
public:
    //zero count = number of children without a cookie

    int dfs(int i, vector<int> & unfairness, vector<int>& cookies, int k, int zeroCount) {
        int n = cookies.size();
        if (n - i < zeroCount)
            return INT_MAX;

        if (i == n)
            return *max_element(unfairness.begin(), unfairness.end());
        
        int ans = INT_MAX;
        for(int j = 0; j < k; j++) {
            //subtract zerocount if current child is fair and can be granted more
            zeroCount -= unfairness[j] == 0? 1: 0;
            unfairness[j] += cookies[i];

            ans = min(ans, dfs(i+1, unfairness, cookies, k, zeroCount));

            unfairness[j] -= cookies[i];
            zeroCount += unfairness[j] == 0 ? 1: 0;
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> unfairness(k, 0); //unfairness of each child
        return dfs(0, unfairness, cookies, k, k);
        

    }

};


Runtime
55ms
Beats 67.54% of users with C++
Memory
7.27MB
Beats 46.22% of users with C++