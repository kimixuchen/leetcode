/**
LeetCode-694-Number of Distinct Islands
08/10/17 10:02:08
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

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first==b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

class Solution {
private:
    unordered_map<int, vector<vector<pair<int, int>>>> islands;
    
    int bfs(vector<vector<int>>& grid, int i, int j, int m, int n, 
            vector<vector<bool>>& visit)
    {
        int area = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        vector<pair<int, int>> stones;
        stones.push_back(make_pair(i, j));
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
                    stones.push_back(make_pair(x, y));
                }
            }
        }
        sort(stones.begin(), stones.end(), cmp);
        int xdif = stones[0].first;
        int ydif = stones[0].second;
        for(int i=0; i<stones.size(); i++)
        {
            stones[i].first -= xdif;
            stones[i].second -= ydif;
        }
        
        if(islands.find(area) == islands.end())
        {
            islands[area].push_back(stones);
        }
        else
        {
            auto sameAreas = islands[area];
            bool hasSame = false;
            for(int i=0; i<sameAreas.size(); i++)
            {
                bool isSame = true;
                for(int j=0; j<sameAreas[i].size(); j++)
                {
                    if(stones[j].first != sameAreas[i][j].first || 
                            stones[j].second != sameAreas[i][j].second)
                    {
                        isSame = false;
                        break;
                    }
                }
                if(isSame)
                {
                    hasSame = true;
                    break;
                }
            }
            if(!hasSame)
            {
                islands[area].push_back(stones);
            }
        }
        return area;
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
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
                    bfs(grid, i, j, m, n, visit);
                }
            }
        } 
        
        
        int count = 0;
        for(auto stones : islands)
        {
            auto l = stones.second;
            count += l.size();
        }
        return count;
    }
};
