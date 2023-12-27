/*



*/





class Solution {
public:
    int maxArea(vector<int>& H) {
        int ans = 0, i = 0, j = H.size()-1, res = 0;
        while (i < j) {
            if (H[i] <= H[j]) {
                res = H[i] * (j - i);
                i++;
            } else {
                res = H[j] * (j - i);
                j--;
            }
            if (res > ans) ans = res;
        }
        return ans;
    }
};


Runtime
69ms
Beats 60.63% of users with C++
Memory
59.42MB
Beats 21.02% of users with C++






class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};




Runtime
60
ms
Beats
91.29%
of users with C++
Memory
59.32
MB
Beats
48.90%
of users with C++