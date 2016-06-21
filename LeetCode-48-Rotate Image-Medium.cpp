/**
LeetCode-48-Rotate Image
2016-06-20 19:19:26
**/
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include "stdio.h"
using namespace std;

class Solution {
private:
    void rotateOneRound(vector<vector<int> >& matrix, int i, int j)
    {
        int n = matrix.size();
        int a, b, tmp;
        a = i; b = j;
        for(int i=0; i<4; ++i)
        {
            matrix[b][n-a] = matrix[a][b];
            tmp = a;
            a = b;
            b = n-tmp;
        }
    }
    
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int level = n/2 + (n%2==0 ? 0:1);
        for(int i=0; i<level; ++i)
        {
            for(int j=i; j<n-i; ++j)
            {
                rotateOneRound(matrix, i, j);
            }
        }
    }
};
