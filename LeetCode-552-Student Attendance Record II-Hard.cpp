/*
LeetCode-552-Student Attendance Record II
16/04/17 10:07:25
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

const int M = 1000000007;
const int N = 100005;

long long dp[2][2][3];

class Solution {
public:
    int checkRecord(int n) {
        
        dp[1][0][0] = 3;
        dp[1][0][1] = 3;
        dp[1][0][2] = 2;
        dp[1][1][0] = 2;
        dp[1][1][1] = 2;
        dp[1][1][2] = 1;
        for(int i=2; i<=n; ++i)
        {
            int k = i%2;
            int p = 1-k;
            dp[k][0][0] = (dp[p][0][0] + dp[p][1][0] + dp[p][0][1])%M;
            dp[k][0][1] = (dp[p][0][0] + dp[p][1][0] + dp[p][0][2])%M;
            dp[k][0][2] = (dp[p][0][0] + dp[p][1][0])%M;
            dp[k][1][0] = (dp[p][1][0] + dp[p][1][1])%M;
            dp[k][1][1] = (dp[p][1][0] + dp[p][1][2])%M;
            dp[k][1][2] = (dp[p][1][0])%M;
        }
        return dp[n%2][0][0];
    }
};
