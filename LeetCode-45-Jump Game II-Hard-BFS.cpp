/**
LeetCode-45-Jump Game II
23/05/16 10:25:05
xuchen
BFS
o(n)
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
    int jump(vector<int>& nums) {
        int i=0, maxPos=0, nextPos=0;
        int level = 0;
        int len = nums.size();
        
        while(maxPos-i+1>0 && maxPos<len-1)
        {
            ++level;
            for(; i<=maxPos && i<len; ++i)
            {
                nextPos = max(nextPos, i+nums[i]);
            }
            maxPos = nextPos;
        }
        return level;
        
    }
};
