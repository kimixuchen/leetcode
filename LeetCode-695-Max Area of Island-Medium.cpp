/**
LeetCode-695-Max Area of Island
08/10/17 09:45:41
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
#include <limits>
#include "limits.h"
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

using namespace std;

class Solution {
private:
    int bfs(vector<vector<int>>& grid, int i, int j, int m, int n, 
            vector<vector<bool>>& visit)
    {
        int area = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visit[i][j] = true;
        
        while(!q.empty())
        {
            auto point = q.front();
            q.pop();
            area++;
            for(int i=0; i<4; i++)
            {
                int x = point.first+dirs[i][0];
                int y = point.second+dirs[i][1];
                
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1 && !visit[x][y])
                {
                    visit[x][y] = true;
                    q.push(make_pair(x, y));
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m, n;
        m = grid.size();
        n = grid[0].size();
        int area = 0;
        
        vector<vector<bool>> visit(m, vector<bool>(n));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visit[i][j] && grid[i][j]==1)
                {
                    int t = bfs(grid, i, j, m, n, visit);
                    area = max(area, t);
                }
            }
        }
        
        return area;
    }
};
