/**
LeetCode-154-Find Minimum in Rotated Sorted Array II
19/09/16 09:09:28
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        int left = 0, right = n-1;
        int mid;
        while(left < right)
        {
            mid = left + (right-left)/2;
            if(nums[mid] < nums[right])
                right = mid;
            else if(nums[mid] > nums[right])
                left = mid+1;
            else
                --right;
        }
        
        return nums[left];
        
    }
};
