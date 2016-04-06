/**
LeetCode-41-First Missing Positive
06/04/16 10:42:25
xuchen
**/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; )
        {
            if(nums[i] <= 0 || nums[i] > len)
            {
                ++i;
                continue;
            }
            
            if(nums[i] != i+1)
            {
                if(nums[nums[i]-1] == nums[i])
                {
                    ++i;
                    continue;
                }
                int tmp = nums[i];
                nums[i] = nums[tmp-1];
                nums[tmp-1] = tmp;
            }
            else
            {
                ++i;
            }
        }
        int ans = len+1;;
        for(int i=0; i<len; ++i)
        {
            if(nums[i] != i+1)
            {
                ans = i+1;
                break;
            }
        }
        
        return ans;
    }
};
