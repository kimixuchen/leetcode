/**
LeetCode-209-Minimum Size Subarray Sum
27/09/16 08:18:08
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
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX;
        vector<int> dp(nums.size(), -1);
        
        int sum = 0;
        int startpos = 0;
        for( ; startpos<nums.size(); ++startpos)
        {
            sum += nums[startpos];
            if(sum >= s)
            {
                for(int i=0; i<=startpos; ++i)
                {
                    if(sum-nums[i] >= s)
                    {
                        sum -= nums[i];
                    }
                    else
                    {
                        dp[startpos] = startpos-i+1;
                        break;
                    }
                }
                break;
            }
        }
        if(startpos == nums.size())
            return 0;
        
        minLen = dp[startpos];
        for(int i=startpos+1; i<nums.size(); ++i)
        {
            sum += nums[i];
            for(int j=i-dp[i-1]; j<=i; ++j)
            {
                if(sum-nums[j] >= s)
                {
                    sum-=nums[j];
                }
                else
                {
                    dp[i] = i-j+1;
                    break;
                }
            }
            minLen = min(minLen, dp[i]);
        }
        
        return minLen;
        
    }
};
