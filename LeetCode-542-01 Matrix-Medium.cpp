/*
LeetCode-542-01 Matrix
10/04/17 09:49:52
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

using namespace std;

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
private:
    bool isOK(int x, int y, int m, int n)
    {
        return x>=0 && x<m && y>=0 && y<n;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> ret(m, vector<int>(n, -1));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    q.push(make_pair(i, j));
                    ret[i][j] = 0;
                }
            }
        }
        
        int step = 0;
        while(!q.empty())
        {
            int len = q.size();
            for(int i=0; i<len; ++i)
            {
                auto point = q.front();
                q.pop();
                for(int j=0; j<4; ++j)
                {
                    int x1 = point.first+dirs[j][0];
                    int y1 = point.second+dirs[j][1];
                    if(isOK(x1, y1, m, n) && ret[x1][y1]==-1)
                    {
                        ret[x1][y1] = step+1;
                        q.push(make_pair(x1, y1));
                    }
                }
            }
            ++step;
        }
        
        return ret;
        
    }
};
