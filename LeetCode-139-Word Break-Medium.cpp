/**
LeetCode-139-Word Break
12/09/16 08:55:10
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
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
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s=="")
            return true;
        
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<=n; ++j)
            {
                if(dp[i] && wordDict.find(s.substr(i, j-i))!=wordDict.end())
                    dp[j] = true;
            }
        }
        
        return dp[n];
    }
};
