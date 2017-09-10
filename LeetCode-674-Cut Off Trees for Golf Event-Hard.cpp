/**
LeetCode-674-Cut Off Trees for Golf Event
10/09/17 10:21:50
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

struct tree{
    int height;
    int x;
    int y;
    tree(int a, int b, int c)
    {
        height = a;
        x = b;
        y = c;
    }
};

bool cmp(const tree &a, const tree &b)
{
    return a.height < b.height;
}

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
private:
    int m, n;
    vector<tree> trees;
    int treeNum;
    int posx, posy;
    int step;

    int moveTo(vector<vector<int>>& forest, tree target)
    {
        int step = 0;
        int c = 1;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push(make_pair(posx, posy));
        while(!q.empty())
        {
            int nextc = 0;
            for(int i=0; i<c; i++)
            {
                auto position = q.front();
                q.pop();
                if(position.first==target.x && position.second==target.y)
                {
                    posx = position.first;
                    posy = position.second;
                    return step;
                }
                for(int k=0; k<4; k++)
                {
                    int x = position.first+dirs[k][0];
                    int y = position.second+dirs[k][1];
                    if(x>=0 && x<m && y>=0 && y<n && forest[x][y] > 0 && 
                            !visit[x][y])
                    {
                        visit[x][y] = true;
                        nextc++;
                        q.push(make_pair(x, y));
                    }
                }
                
            }
            c = nextc;
            step++;
        }
        
        return -1;
    
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();
        if(m == 0)
            return 0;
        
        n = forest[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(forest[i][j] > 1)
                {
                    tree t(forest[i][j], i, j);
                    trees.push_back(t);
                }
            }
        }
        
        treeNum = trees.size();
        
        sort(trees.begin(), trees.end(), cmp);
        
        for(int i=0; i<treeNum; i++)
        {
            tree target = trees[i];
            int t = moveTo(forest, target);
            if(t == -1)
                return -1;
            step += t;
        }
        
        return step;
        
        
        
        
    }
};
