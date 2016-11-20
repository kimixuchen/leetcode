/*
LeetCode-463-Island Perimeter
20/11/16 10:33:31
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row==0)
            return 0;
        int col = grid[0].size();
        
        int dirs[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
        int counter = 0;
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(grid[i][j]==1)
                {
                    for(int k=0; k<4; ++k)
                    {
                        int x = i+dirs[k][0];
                        int y = j+dirs[k][1];
                        if(x<0 || x>=row || y<0 || y>=col || grid[x][y]==0)
                            counter++;
                    }
                }
            }
        }
        return counter;
        
    }
};

