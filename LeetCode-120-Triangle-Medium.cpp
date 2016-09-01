/**
LeetCode-120-Triangle
01/09/16 08:29:57
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <map>
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
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> sum(triangle.size());
        if(sum.size()==0)
            return 0;
        sum[0] = triangle[0][0];
        for(int i=1; i<sum.size(); ++i)
        {
            int pre = sum[0];
            int tmp;
            sum[0] += triangle[i][0];
            for(int j=1; j<i; ++j)
            {
                tmp = sum[j];
                sum[j] = min(triangle[i][j]+pre, triangle[i][j]+sum[j]);
                pre = tmp;
            }
            sum[i]  = pre + triangle[i][i];
        }
        int minsum = sum[0];
        for(int i=1; i<sum.size(); ++i)
        {
            minsum = min(minsum, sum[i]);
        }
        
        return minsum;
    }
};
