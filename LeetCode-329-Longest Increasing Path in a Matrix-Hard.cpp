/*
LeetCode-329-Longest Increasing Path in a Matrix
03/11/16 10:32:21
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
private:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> lens;
    
    int search(vector<vector<int>> &matrix, int x, int y)
    {
        if(lens[x][y]>0)
            return lens[x][y];
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        int x1, y1;
        int nextlen = 0;
        for(int i=0; i<4; ++i)
        {
            x1 = x+dirs[i][0];
            y1 = y+dirs[i][1];
            if(x1>=0 && x1<rows && y1>=0 && y1<cols && 
                    matrix[x1][y1]>matrix[x][y])
                nextlen = max(nextlen, search(matrix, x1, y1));
        }
        lens[x][y] = 1+nextlen;
        return lens[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()<1)
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        lens = vector<vector<int>>(rows, vector<int>(cols, 0));
        int maxlen=0;
        for(int i=0; i<rows; ++i)
        {
            for(int j=0; j<cols; ++j)
            {
                maxlen = max(maxlen, search(matrix, i, j));
            }
        }
        
        return maxlen;
        
    }
};
