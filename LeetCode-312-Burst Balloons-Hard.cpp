/*
LeetCode-312-Burst Balloons
27/10/16 08:46:57
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
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int i=1; i<=n; ++i)
        {
            dp[i][i] = nums[i-1]*nums[i]*nums[i+1];
        }
        
        for(int k=2; k<=n; ++k)
        {
            for(int left = 1; left<=n+1-k; ++left)
            {
                for(int i=left; i<=left+k-1; ++i)
                    dp[left][left+k-1] = max(dp[left][left+k-1], 
                        dp[left][i-1]+nums[i]*nums[left-1]*nums[left+k]
                        +dp[i+1][left+k-1]);
            }
        }
        return dp[1][n];
        
    }
};
