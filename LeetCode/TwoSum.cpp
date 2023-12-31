/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int first = 0; first < nums.size(); first++){
			
            for (int second = first + 1; second < nums.size(); second++){
				
                if (nums[first] + nums[second] == target){
			
                    return {first, second};
                }
            }
        }
        return {};
    }
};


Runtime
310ms
Beats 23.39%of users with C++
Memory
10.47MB
Beats 77.59%of users with C++



//second solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        //We will store our values and the indices here.
        unordered_map<int,int> map;        
		
        //We iterate through the loop.
        for(int index = 0; index < nums.size(); index++){
			if(map.find(target-nums[index]) != map.end()){
                //If map contains the value target - nums[index] return the indices of these two values.
                return {index, map[target-nums[index]]};
            }			
            map[nums[index]] = index;
            //If nota dd nums[index] to map.
        }
        
        //If there is no solution return an empty vector.        
        return {};
    }   
};


Runtime
7ms
Beats 90.10%of users with C++
Memory
11.14MB
Beats 33.72%of users with C++




//3rd solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                v.push_back(m[target-nums[i]]);
                v.push_back(i);
                return v;
            }
            m[nums[i]]=i;
        }
        return v;
    }
};

Runtime
13ms
Beats 57.80%of users with C++
Memory
11.44MB
Beats 16.77%of users with C++



//sort + two pointer
//Runtime: 8 ms, faster than 99.93% of C++ online submissions for Two Sum.
//Memory Usage: 9.5 MB, less than 70.01% of C++ online submissions for Two Sum.
//time: O(NlogN), space: O(N)
class Solution {
public:
    template <typename T>
    vector<int> sort_indexes(const vector<T> &v) {

      // initialize original index locations
      vector<int> idx(v.size());
      iota(idx.begin(), idx.end(), 0);

      // sort indexes based on comparing values in v
      sort(idx.begin(), idx.end(),
           [&v](int i1, int i2) {return v[i1] < v[i2];});

      return idx;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ixs = sort_indexes(nums);
        
        int i = 0, j = nums.size()-1;
        
        while(i < j){
            int ix1 = ixs[i], ix2 = ixs[j];
            if(nums[ix1] + nums[ix2] == target){
                return vector<int> {ix1, ix2};
            }else if(nums[ix1] + nums[ix2] < target){
                i++;
            }else{
                j--;
            }
        }
        return vector<int>();
    }
};

//sort + two pointer, easier to understand
//https://leetcode.com/problems/two-sum/discuss/7/Java-O(nlogn)-beats-98.85
//Runtime: 340 ms, faster than 86.87% of C++ online submissions for Number of Subsequences That Satisfy the Given Sum Condition.
//Memory Usage: 50.1 MB, less than 100.00% of C++ online submissions for Number of Subsequences That Satisfy the Given Sum Condition.
//time: O(NlogN), space: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        we still need nums to get the numbers' indices,
        so here we make a copy
        */
        int n = nums.size();
        vector<int> nums2 = nums;
        
        sort(nums2.begin(), nums2.end());
        
        //find the two elements whose sum is target is the sorted array
        int a, b;
        for(int l = 0, r = n-1; l <= r; ){
            if(nums2[l] + nums2[r] < target){
                ++l;
            }else if(nums2[l] + nums2[r] > target){
                --r;
            }else{
                a = nums2[l];
                b = nums2[r];
                break;
            }
        }
        
        //find a and b's indices in original array
        vector<int> ans(2);
        
        for(int i = 0; i < n; ++i){
            if(nums[i] == a){
                ans[0] = i;
                break;
            }
        }
        
        for(int i = n-1; i >= 0; --i){
            if(nums[i] == b){
                ans[1] = i;
                break;
            }
        }
        
        return ans;
    }
};

/**
Approach 1: Brute Force
**/

/**
Complexity Analysis

Time complexity : O(n^2). 
For each element, 
we try to find its complement by looping through the rest of array which takes O(n) time. 
Therefore, the time complexity is O(n^2).
Space complexity : O(1). 
**/

/**
Approach 2: Two-pass Hash Table
build map and then check for each key whether its complement exists
**/

/**
Complexity Analysis:
Time complexity : O(n). 
We traverse the list containing nn elements exactly twice. 
Since the hash table reduces the look up time to O(1), the time complexity is O(n).
Space complexity : O(n). 
The extra space required depends on the number of items stored in the hash table, which stores exactly nn elements. 
**/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> ixs;
        for(int i = 0; i < nums.size(); i++){
            ixs[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(ixs.find(complement) != ixs.end() && ixs[complement] != i){
                return vector<int> {i, ixs[complement]};
            }
        }
        
        return vector<int> {};
    }
};

/**
Approach 3: One-pass Hash Table
build and check for complement at the same time
**/

/**
Complexity Analysis:
Time complexity : O(n).
We traverse the list containing nn elements only once. 
Each look up in the table costs only O(1) time.
Space complexity : O(n). 
The extra space required depends on the number of items stored in the hash table, which stores at most nn elements.
**/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> ixs;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(ixs.find(complement) != ixs.end()){
                return vector<int> {i, ixs[complement]};
            }
            ixs[nums[i]] = i;
        }
        return vector<int> {};
    }
};