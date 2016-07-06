/**
LeetCode-63-Unique Paths II
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp;
        vector<int> r(obstacleGrid[0].size(), 0);
        for(int i=0; i<2; ++i)
        {
            dp.push_back(r);
        }
        if(obstacleGrid[0][0]!=1)
            dp[0][0] = 1;
        if(row > 1)
        {
            if(obstacleGrid[1][0]!=1)
                dp[1][0] = dp[0][0];
            else
                dp[1][0] = 0;
        }
        
        for(int i=0; i<row; ++i)
        {
            if(i>0)
            {
                if(obstacleGrid[i][0]==1)
                    dp[i%2][0] = 0;
                else
                    dp[i%2][0] = dp[(i+1)%2][0];
            }
            for(int j=1; j<col; ++j)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i%2][j] = 0;
                }
                else
                {
                    dp[i%2][j] = dp[i%2][j-1] + dp[(i+1)%2][j];
                }
            }
        }
        return dp[(row-1)%2][col-1];
        
    }
};
