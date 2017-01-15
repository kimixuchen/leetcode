/*
LeetCode-474-Ones and Zeros
15/01/17 09:35:40
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
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        for(string &s : strs)
        {
            int numOnes=0, numZeros=0;
            for(char c : s)
            {
                if(c=='1')
                    ++numOnes;
                else
                    ++numZeros;
            }
            
            for(int i=m; i>=numZeros; --i)
            {
                for(int j=n; j>=numOnes; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i-numZeros][j-numOnes]+1);
                }
            }
        }
        return dp[m][n];
    }
};
