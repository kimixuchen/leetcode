/**
LeetCode-54-Spiral Matrix
29/06/16 10:12:25
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        if(0==row)
            return ans;
        int col = matrix[0].size();
        if(0==col)
            return ans;
        
        int x=0, y=0;
        while(row>0 && col>0)
        {
            for(int i=y; i<y+col; ++i)
                ans.push_back(matrix[x][i]);
            for(int i=x+1; i<x+row; ++i)
                ans.push_back(matrix[i][y+col-1]);
            if(row>1)
            {
                for(int i=y+col-2; i>=y; --i)
                    ans.push_back(matrix[x+row-1][i]);
            }
            if(col > 1)
            {
                for(int i=x+row-2; i>x; --i)
                    ans.push_back(matrix[i][y]);
            }
            
            row-=2;
            col-=2;
            x+=1;
            y+=1;
        }
        return ans;
    }
};
