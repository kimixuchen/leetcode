/**
LeetCode-74-Search a 2D Matrix
05/03/16 15:59:47
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int matrixRowSize = matrix.size();
        if(matrixRowSize < 1)
            return false;
        int matrixColSize = matrix[0].size();
        int l, r, mid, row;
        l = 0;
        r = matrixRowSize;
        row = -1;
        while(l < r)
        {
            mid = (l+r)>>1;
            if(matrix[mid][0] > target){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        row = l-1;
        if(row<0)
            return false;
        l = 0;
        r = matrixColSize-1;
        while(l<=r)
        {
            mid = (l+r)>>1;
            if(matrix[row][mid]==target)
                return true;
            else if(matrix[row][mid] < target)
                l = mid+1;
            else if(matrix[row][mid] > target)
                r = mid-1;
        }
        return false;
        
    }
};

int main()
{
    Solution s = new Solution();


    return 0;
}
