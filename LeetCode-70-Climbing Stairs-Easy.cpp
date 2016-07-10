/**
LeetCode-70-Climbing Stairs
10/07/16 07:59:25
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
    int climbStairs(int n) {
        int dp[3];
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; ++i)
        {
            dp[i%3] = dp[(i+2)%3] + dp[(i+1)%3];
        }
        return dp[n%3];
    }
};
