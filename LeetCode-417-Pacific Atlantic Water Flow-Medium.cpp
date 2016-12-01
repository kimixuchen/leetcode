/*
LeetCode-417-Pacific Atlantic Water Flow
01/12/16 09:03:40
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
private:
    void dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<bool>> &visited)
    {
        int dirs[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
        for(int i=0; i<4; ++i)
        {
            int x1 = x+dirs[i][0];
            int y1 = y+dirs[i][1];
            if(x1<matrix.size() && x1>=0 && y1<matrix[0].size() && y1>=0)
            {
                if(visited[x1][y1]==false && matrix[x1][y1]>=matrix[x][y])
                {
                    visited[x1][y1] = true;
                    dfs(x1, y1, matrix, visited);
                }
            }
        }
    }

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ret;
        int m = matrix.size();
        if(m==0)
            return ret;
        int n = matrix[0].size();
        
        vector<vector<bool>> pVisited(m, vector<bool>(n, false));
        vector<vector<bool>> aVisited(m, vector<bool>(n, false));
        for(int i=0; i<m; ++i)
        {
            pVisited[i][0] = true;
            aVisited[i][n-1] = true;
            dfs(i, 0, matrix, pVisited);
            dfs(i, n-1, matrix, aVisited);
        }
        for(int i=0; i<n; ++i)
        {
            pVisited[0][i] = true;
            aVisited[m-1][i] = true;
            dfs(0, i, matrix, pVisited);
            dfs(m-1, i, matrix, aVisited);
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(pVisited[i][j] && aVisited[i][j])
                    ret.push_back(make_pair(i, j));
            }
        }
        
        return ret;
    }
};
