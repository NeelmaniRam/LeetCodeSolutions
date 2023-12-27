/*
There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.

Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).

Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.

Since the answer may be large, return it modulo 109 + 7.

Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.

 

Example 1:



Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
Output: 4
Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
Example 2:



Input: m = 6, n = 7, hFences = [2], vFences = [4]
Output: -1
Explanation: It can be proved that there is no way to create a square field by removing fences.
 

Constraints:

3 <= m, n <= 109
1 <= hFences.length, vFences.length <= 600
1 < hFences[i] < m
1 < vFences[i] < n
hFences and vFences are unique.
*/


class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
          hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        set<int> horizontalDifferences;
        for (int i = static_cast<int>(hFences.size()) - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                int diff = hFences[i] - hFences[j];
                horizontalDifferences.insert(diff);
            }
        }

        vector<int> verticalDifferences;
        for (int i = static_cast<int>(vFences.size()) - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                int diff = vFences[i] - vFences[j];
                verticalDifferences.push_back(diff);
            }
        }

        sort(verticalDifferences.begin(), verticalDifferences.end());

        int ans = -1;
        for (int i = static_cast<int>(verticalDifferences.size()) - 1; i >= 0; --i) {
            if (horizontalDifferences.find(verticalDifferences[i]) != horizontalDifferences.end()) {
                ans = verticalDifferences[i];
                break;
            }
        }

        int mod = 1e9 + 7;

        if (ans != -1) {
            ans = static_cast<int>((1LL * ans * ans) % mod);
        }

        return ans;
    }
};

Runtime
2344
ms
Beats
10.00%
of users with C++
Memory
369.75
MB
Beats
30.00%
of users with C++










class Solution {
     unordered_set<int> make(vector<int> &v, int p) {
         v.push_back(1);
         v.push_back(p);
         unordered_set<int> s;
         for (int i = 0; i < v.size(); ++i) {
             for (int j = 0; j < i; ++j) {
                 s.insert(abs(v[i] - v[j]));  
             }
         }
        return s;
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const auto& s = make(hFences, m);
        vFences.push_back(1);
        vFences.push_back(n);
        int e = 0;
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                const int x = abs(vFences[i] - vFences[j]);
                if (x > e && s.count(x)) {
                    e = x;
                }
            }
            
        }
        return e ? (1LL * e * e) % 1000000007 : -1;
        
    }
};


Runtime
939
ms
Beats
100.00%
of users with C++
Memory
262.64
MB
Beats
100.00%
of users with C++