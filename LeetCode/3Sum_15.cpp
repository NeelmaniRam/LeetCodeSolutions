/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/


3 approaches

1. brute force

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int>v(3);
                        v[0]=nums[i];v[1]=nums[j];v[2]=nums[k];
                        sort(v.begin(),v.end());
                        s.insert(v);
                    }
                }
            }
        }
        vector<vector<int>>v;
        for(auto i:s)
        {
            v.push_back(i);
        }
        return v;
    }
};

Time Complexity: The time complexity of the above approach is O(n3)(log m)

Space Complexity: The space complexity of the above algorithm is O(m)




2. Using Hash Map/ Hash Table



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        unordered_map<int,int> m;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            m[nums[i]]--;
            for(int j=i+1;j<n;j++)
            {
                m[nums[j]]--;
                int c = -1*(nums[i]+nums[j]);
                if(m.find(c) != m.end() && m[c]>0)
                {
                    vector<int>v(3);
                    v[0]=nums[i],v[1]=nums[j],v[2]=c;
                    sort(v.begin(),v.end());
                    s.insert(v);
                }
                m[nums[j]]++;
            }
            m[nums[i]]++;
        }
        vector<vector<int>>v;
        for(auto i:s)
        {
            v.push_back(i);
        }
        return v;
    }
};


Time Complexity: The time complexity of the above approach is O(n2 logm).

Space Complexity: The space complexity of the above approach is O(n).



3. 2 pointer



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        if(nums.size() < 3) return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-2; i++){            
            
            if(i == 0 || nums[i-1] != nums[i]){
                
                int low = i+1, high = nums.size()-1, sum = -nums[i];
                
                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        
                        ans.push_back({nums[i], nums[low], nums[high]});
                        
                        while(low < high && nums[low] == nums[low+1])
                         low++;
                                               
                          while(low < high && nums[high] == nums[high-1])  
                         high--;
                          low++;
                          high--;
                      }
                      
                      else if(nums[low] + nums[high] < sum){
                          low++;
                      }
                      else{
                          high--;
                      }
                  }                
              }
          }
          return ans;
      }
  };



  Runtime
128
ms
Beats
56.39%
of users with C++
Memory
24.30
MB
Beats
97.64%
of users with C++
