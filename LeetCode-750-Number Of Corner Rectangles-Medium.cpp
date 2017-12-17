/**
LeetCode-750-Number Of Corner Rectangles
17/12/17 11:11:27
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
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int ret = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> rowCol(row, vector<int>());
        vector<vector<int>> colRow(col, vector<int>());
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == 1)
                {
                    rowCol[i].push_back(j);
                    colRow[j].push_back(i);
                }
            }
        }
        
        for(int i=0; i<row; i++)
        {
            for(int pos1 = 0; pos1<rowCol[i].size(); pos1++)
            {
                for(int pos2 = pos1+1; pos2<rowCol[i].size(); pos2++)
                {
                    auto row1s = colRow[rowCol[i][pos1]];
                    auto row2s = colRow[rowCol[i][pos2]];
                    int pin1=0, pin2=0;
                    while(pin1<row1s.size() && pin2<row2s.size())
                    {
                        if(row1s[pin1]<=i)
                        {
                            pin1++;
                            continue;
                        }
                        if(row2s[pin2]<=i)
                        {
                            pin2++;
                            continue;
                        }
                        if(row1s[pin1]==row2s[pin2])
                        {
                            ret++;
                            pin1++;
                            pin2++;
                        }
                        else if(row1s[pin1]<row2s[pin2])
                        {
                            pin1++;
                        }
                        else if(row1s[pin1]>row2s[pin2])
                        {
                            pin2++;
                        }
                    }
                
                }
            }
        }
        return ret;
        
        
    }
};
