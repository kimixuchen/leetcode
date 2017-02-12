/*
LeetCode-516
12/02/17 09:43:53
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
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; ++i)
            dp[i][i] = 1;
        
        for(int k = 2; k<=n; ++k)
        {
            for(int i=0; i+k-1<n; ++i)
            {
                
                dp[i][i+k-1] = max(dp[i+1][i+k-1], dp[i][i+k-2]);
                if(s[i]==s[i+k-1])
                    dp[i][i+k-1] = max(dp[i+1][i+k-2]+2, dp[i][i+k-1]);
            }
        }
        
        return dp[0][n-1];
        
    }
};
