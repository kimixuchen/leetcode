/**
LeetCode-221-Maximal Square
09/10/16 16:02:10
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
    bool check(int row, int l, int r, vector<vector<char>>& matrix)
    {
        int len = r-l+1;
        if(row+len > matrix.size())
            return false;
        for(int i=row; i<row+len; ++i)
        {
            if(matrix[i][r]=='0')
                return false;
        }
        for(int i=l; i<=r; ++i)
            if(matrix[row+len-1][i]=='0')
                return false;
        return true;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<int> dp(matrix[0].size(), 0);
        int square = 0;
        int row=matrix.size(), col=matrix[0].size();
        int len1, len2;
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(matrix[i][j]=='0')
                {
                    dp[j] = 0;
                    continue;
                }
                len1 = dp[j];
                len2 = j>0 ? dp[j-1] : 0;
                len1 = max(len1, len2);
                len1 = max(len1, 1);
                int k=j+len1-1;
                for( ; k<col && matrix[i][k]=='1'; ++k)
                {
                    if(!check(i, j, k, matrix))
                        break;
                }
                dp[j] = k-j;
                square = max(square, dp[j]*dp[j]);
            }
        }
        
        return square;
        
    }
};
