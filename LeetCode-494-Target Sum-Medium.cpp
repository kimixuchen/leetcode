/*
LeetCode-494-Target Sum
07/02/17 19:30:53
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <priority_queue>
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

using namespace std;

class Solution {
private:
    int search(vector<int>& nums, int target)
    {
        int dp[target+1] = {0};
        dp[0] = 1;
        
        for(int i=0; i<nums.size(); ++i)
        {
            for(int j=target; j>=nums[i]; --j)
            {
                dp[j] += dp[j-nums[i]];
            }
        }
        
        return dp[target];
    }

public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = ((long long)S+sum)>>1;
        if(target>sum || (S+sum)%2==1)
            return 0;
        
        int ret = search(nums, target);
        
        return ret;
    }
};
