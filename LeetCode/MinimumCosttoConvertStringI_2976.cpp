/*
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.
 

Constraints:

1 <= source.length == target.length <= 105
source, target consist of lowercase English letters.
1 <= cost.length == original.length == changed.length <= 2000
original[i], changed[i] are lowercase English letters.
1 <= cost[i] <= 106
original[i] != changed[i]
*/



class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int num_chars = 26;
        vector<vector<long long>> distance(num_chars, vector<long long>(num_chars, LLONG_MAX));

        for (int i = 0; i < num_chars; ++i) {
            distance[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int src = original[i] - 'a';
            int dst = changed[i] - 'a';
            int weight = cost[i];
            distance[src][dst] = min(static_cast<long long>(weight), distance[src][dst]);
        }

        for (int k = 0; k < num_chars; ++k) {
            for (int i = 0; i < num_chars; ++i) {
                for (int j = 0; j < num_chars; ++j) {
                    if (distance[i][k] != LLONG_MAX && distance[k][j] != LLONG_MAX) {
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < source.length(); ++i) {
            int src = source[i] - 'a';
            int dest = target[i] - 'a';

            if (src == dest) {
                continue;
            }

            if (distance[src][dest] == LLONG_MAX) {
                return -1;
            } else {
                totalCost += distance[src][dest];
            }
        }

        return totalCost;
    }
};



Runtime
227
ms
Beats
22.22%
of users with C++
Memory
93.91
MB
Beats
11.11%
of users with C++



class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int e[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                e[i][j] = 1e9 + 10;
            }
            e[i][i] = 0;
        }
        for (int i = 0; i < cost.size(); i++) {
            e[original[i] - 'a'][changed[i] - 'a'] = min(e[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
                for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                    e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
                }
            }
        } 
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (e[source[i] - 'a'][target[i] - 'a'] > 1e9) {
                return -1;
            }
            ans += e[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};




Runtime
158
ms
Beats
66.67%
of users with C++
Memory
87.72
MB
Beats
22.22%
of users with C++









class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        unordered_set<int> len;
        
        long long e = -1;
        for (int i = 0; i < h.size(); ++i) {
            for (int j = i + 1; j < h.size(); ++j) {
                len.insert(h[j] - h[i]);
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                int l = v[j] - v[i];
                if (len.count(l)) {
                    e = max(e, (long long) l);
                }
            }
        }
        if (e == -1) {
            return -1;
        }
        return e * e % 1000000007;
    }
};







class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long dis[26][26];
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                dis[i][j] = INF;
            }
            dis[i][i] = 0;
        }
        
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            
            dis[u][v] = min(dis[u][v], (long long) cost[i]);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0;i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (i != j && j != k && k != i) {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }
        
        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            auto u = source[i] - 'a';
            auto v = target[i] - 'a';
                dp[i + 1] = min(dp[i + 1], dp[i] + dis[u][v]);
        }
        if (dp[n] >= INF) {
            return -1;
        }
        return dp[n];
        
    }
};
