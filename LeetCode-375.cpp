/*
LeetCode-375-Guess Number Higher or Lower II
22/11/16 08:46:55
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
const int MAX = 0x3f3f3f3f;
class Solution {
public:
    int getMoneyAmount(int n) {
        if(n==1)
            return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int gap = 1; gap<n; ++gap)
        {
            for(int i = 1; i+gap<=n; ++i)
            {
                int _min = i+dp[i+1][i+gap];
                int tmp;
                for(int j=i+1; j<i+gap; ++j)
                {
                    tmp = j + max(dp[i][j-1], dp[j+1][i+gap]);
                    _min = min(_min, tmp);
                }
                dp[i][i+gap] = _min;
            }
        }
        return dp[1][n];
        
    }
};
