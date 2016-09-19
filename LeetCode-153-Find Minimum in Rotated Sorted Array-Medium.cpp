/**
LeetCode-153-Find Minimum in Rotated Sorted Array
19/09/16 08:43:44
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
        int left = 0, right = n-1;
        while(left <= right)
        {
            if(nums[left] > nums[right])
            {
                if(right == left+1)
                {
                    left = right;
                    break;
                }
                left = (left+right)/2;
            }
            else
            {
                if(nums[left] <= nums[(left-1+n)%n])
                    break;
                else
                {
                    right = left;
                    left = 0;
                }
            }
        }
        
        return nums[left];
        
    }
};
