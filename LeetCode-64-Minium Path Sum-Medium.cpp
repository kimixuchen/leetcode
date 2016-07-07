/**
LeetCode-64-Minium Path Sum
07/07/16 08:59:06
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
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> sum(grid);
        for(int i=1; i<col; ++i)
        {
            sum[0][i] += sum[0][i-1];
        }
        for(int i=1; i<row; ++i)
        {
            sum[i][0] += sum[i-1][0];
        }
        
        for(int i=1; i<row; ++i)
        {
            for(int j=1; j<col; ++j)
            {
                sum[i][j] += min(sum[i][j-1], sum[i-1][j]);
            }
        }
        return sum[row-1][col-1];
        
    }
};
