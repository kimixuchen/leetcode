/*
LeetCode-416-Partition Equal Subset Sum
01/12/16 08:40:32
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
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int dp[20005];
        int n = nums.size();
        int sum = 0;
        
        memset(dp, 0, sizeof(dp));
        
        for(int a : nums)
            sum += a;
        
        if(sum%2 == 1)
            return false;
        
        int cursum = 0;
        dp[0] = 1;
        for(int i=0; i<n; ++i)
        {
            cursum += nums[i];
            for(int j=cursum-nums[i]; j>=0; --j)
                if(dp[j]==1)
                    dp[j+nums[i]] = 1;
        }
        return dp[sum/2]==1;
        
    }
};
