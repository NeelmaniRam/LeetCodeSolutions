/*
An array arr is a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.

 

Example 1:

Input: arr = [0,1,0]
Output: 1
Example 2:

Input: arr = [0,2,1,0]
Output: 1
Example 3:

Input: arr = [0,10,5,2]
Output: 1
 

Constraints:

3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
*/


class Solution {
private:
    int MaxElement(vector<int>& arr){
        int num=arr[0];
        for(int i =1;i<arr.size();i++){
            num=max(num, arr[i]);
        }
        return num;

    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int max= MaxElement(arr);
        for(int i =0;i<arr.size();i++){
            if(max==arr[i]){
                return i;
            }
        }
        return 0;

    }
};


Runtime
87ms
Beats 54.20% of users with C++
Memory
60.02MB
Beats 38.47% of users with C++




class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int res = 0;
        //int n = arr.size();
        for (int i = 1; i < arr.size()-1; ++i) {
            if (arr[i-1] < arr[i] && arr[i] > arr[i+1])
                res=i; 
        }
        return res;
    }
};


Runtime
86ms
Beats 59.46% of users with C++
Memory
60.20MB
Beats 6.84% of users with C++