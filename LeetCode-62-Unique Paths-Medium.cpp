/**
LeetCode-62-Unique Paths
06/07/16 20:19:22
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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        vector<int> row(n, 0);
        for(int i=0; i<2; ++i)
        {
            dp.push_back(row);
        }
        
        int k = 0;
        dp[0][0] = 1;
        dp[1][0] = 1;
        for(int j=0; j<m; ++j)
        {
            for(int i=1; i<n; ++i)
            {
                dp[k][i] =  dp[k][i-1] + dp[(k+1)%2][i];  
            }
            k = (k+1)%2;
        }
        return dp[(k+1)%2][n-1];
    }
};
