/*
LeetCode-376-Wiggle Subsequence
22/11/16 10:35:30
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <set>
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
const int MAX = 0x3f3f3f3f;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        vector<int> pos(n, 1);
        vector<int> neg(n, 1);
        
        int ret = 0;
        for(int i=1; i<n; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(nums[i]>nums[j])
                {
                    pos[i] = max(pos[j], 1+neg[j]);
                }
                if(nums[i]<nums[j])
                {
                    neg[i] = max(neg[j], 1+pos[j]);
                }
            }
        }
        return max(pos[n-1], neg[n-1]);
        
        
        
    }
};
