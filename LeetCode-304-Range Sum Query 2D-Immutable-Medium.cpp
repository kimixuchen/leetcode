/*
LeetCode-304-Range Sum Query 2D-Immutable
24/10/16 08:51:44
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

class NumMatrix {
private:
    vector<vector<int>> in;
    int m, n;
    
    int lowbit(int n)
    {
        return n&(-n);
    }
    
    void plus(int i, int j, int num)
    {
        for(int x=i ; x<=m; x+=lowbit(x))
        {
            for(int y=j ; y<=n; y+=lowbit(y))
                in[x][y] += num;
        }
    }
    
    int sum(int i, int j)
    {
        int sum = 0;
        for(int x=i ; x>0; x-=lowbit(x))
        {
            for(int y=j ; y>0; y-=lowbit(y))
                sum += in[x][y];
        }
        
        return sum;
    }
    
public:
    NumMatrix(vector<vector<int>> &matrix) {
        m = matrix.size();
        n = 0;
        if(m!=0)
            n = matrix[0].size();
        
        in = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                plus(i, j, matrix[i-1][j-1]);
            }
        }
        
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2+1, col2+1)+sum(row1, col1) - sum(row2+1, col1) - 
            sum(row1, col2+1);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
