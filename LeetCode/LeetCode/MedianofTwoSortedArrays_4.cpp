/*

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        vector<int> comb(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),comb.begin());
        sort(comb.begin(),comb.end());
        int n = comb.size();
        /*
        for(int i= 0 ;i<n;i++){
            cout<<comb[i]<<" ";
        }
        */
        
        if(n%2==0){
            median = float(comb[(n-2)/2] + comb[n/2]) / 2 ;
            
        }
        else{
            median = comb[n/2];
        }
        return median;
    }
};


Runtime
20ms
Beats 82.99%of users with C++
Memory
89.94MB
Beats 48.04% of users with C++