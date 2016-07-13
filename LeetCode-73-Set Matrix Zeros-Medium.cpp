/**
LeetCode-73-Set Matrix Zeros
13/07/16 09:34:37
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
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
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rowflags(matrix.size(), false);
        vector<bool> colflags(matrix[0].size(), false);
        
        for(int i=0; i<matrix.size(); ++i)
        {
            for(int j=0; j<matrix[0].size(); ++j)
            {
                if(matrix[i][j] == 0)
                {
                    rowflags[i] = true;
                    colflags[j] = true;
                }
            }
        }
        
        for(int i=0; i<matrix.size(); ++i)
        {
            for(int j=0; j<matrix[0].size(); ++j)
            {
                if(rowflags[i] || colflags[j])
                    matrix[i][j] = 0;
            }
        }
    }
};
