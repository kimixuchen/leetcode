/**
LeetCode-81-Search in Rotated Sorted Array II
14/07/16 08:37:48
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
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
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = (left+right)>>1;
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] == nums[left])     //duplicate number, don't have to solve all of them
                ++left;
            else if(nums[mid] > nums[left])
            {
                if(target >= nums[left] && target < nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(target > nums[mid] && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return false;
    }
};
