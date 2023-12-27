/*

You are given a 0-indexed array of positive integers nums.

A subarray of nums is called incremovable if nums becomes strictly increasing on removing the subarray. For example, the subarray [3, 4] is an incremovable subarray of [5, 3, 4, 6, 7] because removing this subarray changes the array [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.

Return the total number of incremovable subarrays of nums.

Note that an empty array is considered strictly increasing.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 10
Explanation: The 10 incremovable subarrays are: [1], [2], [3], [4], [1,2], [2,3], [3,4], [1,2,3], [2,3,4], and [1,2,3,4], because on removing any one of these subarrays nums becomes strictly increasing. Note that you cannot select an empty subarray.
Example 2:

Input: nums = [6,5,7,8]
Output: 7
Explanation: The 7 incremovable subarrays are: [5], [6], [5,7], [6,5], [5,7,8], [6,5,7] and [6,5,7,8].
It can be shown that there are only 7 incremovable subarrays in nums.
Example 3:

Input: nums = [8,7,6,6]
Output: 3
Explanation: The 3 incremovable subarrays are: [8,7,6], [7,6,6], and [8,7,6,6]. Note that [8,7] is not an incremovable subarray because after removing [8,7] nums becomes [6,6], which is sorted in ascending order but not strictly increasing.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109*/




from typing import List

class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        n = len(nums)

        def binary_search(start, x):
            l, r = start, n - 1
            if nums[r] <= x:
                return n
            while l < r:
                mid = l + (r - l) // 2
                if nums[mid] > x:
                    r = mid
                else:
                    l = mid + 1
            return l

        p2 = n - 2
        while p2 >= 0 and nums[p2] < nums[p2 + 1]:
            p2 -= 1
        p2 += 1

        res = 0
        for i in range(n):
            if i > 1 and nums[i - 1] <= nums[i - 2]:
                break
            x = -1 if i == 0 else nums[i - 1]
            idx = binary_search(p2, x)
            if idx <= i:
                idx = i + 1
            res += n - idx + 1

        return res    





class Solution {
public:
    long long countSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();

        long long result = 0;
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (arr1[i] < arr2[j]) {
                // If arr1[i] is less than arr2[j], you can form sorted arrays with arr1[0..i] and arr2[j..n2-1]
                result += (n2 - j);
                i++;
            } else {
                // If arr1[i] is greater than arr2[j], move to the next element in arr2
                j++;
            }
        }

    return result;
}
    long long incremovableSubarrayCount(vector<int>& a) {
        long long n = a.size();
		
        if(n==1)
            return 1;
        
		int i=0;
        int j=n-1;
		
        vector<int>arr1,arr2;

        while((i+1)<n and a[i]<a[i+1])
        {
            arr1.push_back(a[i]);
            i++;
        }
        arr1.push_back(a[i]);
  
        while((j-1)>=0 and a[j]>a[j-1]){
            arr2.push_back(a[j--]);
        }
        arr2.push_back(a[j]);
		
        reverse(arr2.begin(),arr2.end());
        if(j<i)
        {
            long long ans = (1ll*n*(n+1)*1LL)/2;
            return ans;
        }
		
        long long ans = 0;
		ans += arr1.size();   //1
        ans += arr2.size();  //2
        ans += countSortedArrays(arr1,arr2); //3
		ans++; //4
        
		return ans;
        
    }
};






class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        const int n = nums.size();
        long long r = 1;
        int s = n - 1;
        for (; s >= 0 && (s + 1 >= n || nums[s] < nums[s + 1]); --s) {
            if (s) {
                ++r;
            }
        }
        ++s;
        for (int i = 0; i + 1 < n && (i == 0 || nums[i] > nums[i - 1]); ++i) {
            while (s < n  && (s <= i + 1 || nums[s] <= nums[i])) {
                ++s;
            }
            r += n - s + 1;
        }
        return r;
    }
};


