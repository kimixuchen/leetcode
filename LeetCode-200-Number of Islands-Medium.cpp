/**
LeetCode-200-Number of Islands
23/09/16 08:38:32
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
private:
    struct point{
        int x, y;
        point(int a, int b){x=a; y=b;}
    };
    void search(vector<vector<char>> &grid, int x, int y)
    {
        queue<point> q;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        q.push(point(x, y));
        while(!q.empty())
        {
            point cur = q.front();
            q.pop();
            if(grid[cur.x][cur.y]=='0')
                continue;
            grid[cur.x][cur.y] = '0';
            for(int i=0; i<4; ++i)
            {
                point tmp = point(cur.x+dir[i][0], cur.y+dir[i][1]);
                if(tmp.x>=0 && tmp.x<grid.size() && tmp.y>=0 && tmp.y<grid[0].size())
                    if(grid[tmp.x][tmp.y]=='1')
                        q.push(tmp);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row==0)
            return 0;
        int col = grid[0].size();
        auto cgrid = grid;
        
        int ret = 0;
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(cgrid[i][j]=='1')
                {
                    ++ret;
                    search(cgrid, i, j);
                }
            }
        }
        
        return ret;
    }
};
