/**
LeetCode-96-Unique Binary Search Trees
19/07/16 09:20:43
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
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=i; ++j)
            {
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        
        return dp[n];
        
    }
};
