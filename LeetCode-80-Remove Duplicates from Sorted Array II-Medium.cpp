/**
LeetCode-80-Remove Duplicates from Sorted Array II
14/07/16 08:27:05
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
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int counter = 0;
        int ret = 0;
        int pos = 0;
        int cpos = 0;
        int pre = INT_MAX;
        while(pos < len)
        {
            if(nums[pos]!=pre)
            {
                ++ret;
                counter = 1;
                pre = nums[pos];
                nums[cpos++] = nums[pos];
            }
            else
            {
                if(counter<2)
                {
                    ++counter;
                    ++ret;
                    nums[cpos++] = nums[pos];
                }
            }
            ++pos;
        }
        
        return ret;
    }
};
