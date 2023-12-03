/*
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.

 

Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 104
*/


class Solution {
public:
    


    vector<int> sortByBits(vector<int>& arr) {
        
        auto key = [&](int &a , int &b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            if(countA == countB){
                return a<b;
            }
            return countA < countB;
        };

        sort(begin(arr),end(arr), key);
        return arr;

    }
    
};


Runtime
6ms
Beats 76.61%of users with C++
Memory
10.38MB
Beats 81.00%of users with C++

--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------


class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end(),[](int a , int b){
            if(__builtin_popcount(a) == __builtin_popcount(b)) return a < b;
            return __builtin_popcount(a) < __builtin_popcount(b); 
        });      
        return arr;
    }
};


Runtime
9ms
Beats 43.13%of users with C++
Memory
10.52MB
Beats 53.39%of users with C++







--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------



class Solution {
public:
    int countOf1bits(int num){
        int count = 0;
        while(num!=0){
            count += (num&1);
            num>>=1;
        }
        return count;
    }


    vector<int> sortByBits(vector<int>& arr) {
        
        auto key = [&](int &a , int &b) {
            int countA = countOf1bits(a);
            int countB = countOf1bits(b);
            if(countA == countB){
                return a<b;
            }
            return countA < countB;
        };

        sort(begin(arr),end(arr), key);
        return arr;

    }
    
};


Runtime
8ms
Beats 53.22%of users with C++
Memory
10.61MB
Beats 45.81%of users with C++



--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        //__builtin_popcount(num);
        
        map<int,vector<int>> ff;
        for(auto &it : arr){
           int x = __builtin_popcount(it);
           ff[x].push_back(it);
        }
        
        vector<int> ans;
        for(auto &it : ff){
            vector<int> temp;
            for(auto &val : it.second){
               temp.push_back(val);
            }
            sort(temp.begin(),temp.end());
            for(auto &e : temp){
                ans.push_back(e);
            }
        }
        return ans;

    }
};

Runtime
8ms
Beats 53.22%of users with C++
Memory
11.65MB
Beats 6.73%of users with C++
