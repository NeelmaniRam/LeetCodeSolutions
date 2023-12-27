/*
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

 

Example 1:


Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.
Example 2:


Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 

Constraints:

1 <= path.length <= 104
path[i] is either 'N', 'S', 'E', or 'W'.
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        int i = 0, j = 0;
        unordered_set<int> s{{0}};
        for (char& c : path) {
            if (c == 'N') {
                --i;
            } else if (c == 'S') {
                ++i;
            } else if (c == 'E') {
                ++j;
            } else {
                --j;
            }
            int t = i * 20000 + j;
            if (s.count(t)) {
                return true;
            }
            s.insert(t);
        }
        return false;
    }
};


Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.26
MB
Beats
35.91%
of users with C++

class Solution {
    private boolean isStrictlyIncreasing(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
    public int incremovableSubarrayCount(int[] nums) {
        int count = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int[] copy = new int[n - (j - i + 1)];
                int index = 0;
                
                for (int k = 0; k < n; k++) {
                    if (k < i || k > j) {
                        copy[index++] = nums[k];
                    }
                }

                if (isStrictlyIncreasing(copy)) {
                    count++;
                }
            }
        }

        return count;
    }
}



class Solution {
    public long largestPerimeter(int[] nums) {
        
        Arrays.sort(nums);
        int count = 0;
        long sum = 0, curr = 0;
        sum = 1L * (nums[0] + nums[1]);
        count = 2;

        for (int i = 2; i <nums.length; i++) {
            if (1L * nums[i] < sum) {
                sum += 1L * nums[i];
                curr = sum;
                count++;
            } else {
                sum += 1L * nums[i];
            }
        }

        if (count ==2) {
            return -1;
        }

        return curr;
    }
}



class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> ans;
        int n= nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i+=2){
            ans.push_back(nums[i+1]);
            ans.push_back(nums[i]);
        }
        return ans;
            
    }
};


