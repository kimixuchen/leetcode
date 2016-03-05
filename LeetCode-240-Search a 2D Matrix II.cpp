/**
LeetCode-240-Search a 2D Matrix II
05/03/16 19:03:39
xuchen
**/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool searchMatrix( vector<vector<int> >& matrix, int target) {
        int matrixRowSize = matrix.size();
        if(matrixRowSize < 1)
            return false;
        int matrixColSize = matrix[0].size();
        int cRow = 0;
        int cCol = matrixColSize-1;
        while(cRow >= 0 && cCol >= 0 && cRow < matrixRowSize && 
                cCol < matrixColSize)
        {
            if(target > matrix[cRow][cCol])
                ++cRow;
            else if(target < matrix[cRow][cCol])
                --cCol;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution *s = new Solution();
    vector< vector<int> > m;
    vector<int> e;
    e.push_back(1);
    e.push_back(3);
    e.push_back(5);
    m.push_back(e);
    s->searchMatrix(m, 0);

    return 0;
}
