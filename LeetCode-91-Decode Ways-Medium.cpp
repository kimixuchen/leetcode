/**
LeetCode-91-Decode Ways
16/07/16 10:28:06
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
private:
    int getNum(string &s, int pos)
    {
        int ret = 0;
        ret += 10*(s[pos-1]-'0');
        ret += s[pos]-'0';
        
        return ret;
    }

public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        vector<int> dp(len+1, 0);
        dp[0] = 1;
        if(s[0] > '0')
            dp[1] = 1;
        if(len == 1)
            return dp[1];
        
        for(int i=2; i<=len; ++i)
        {
            if(dp[i-1]>0 && s[i-1]>'0')
                dp[i] = dp[i-1];
            if(getNum(s, i-1)<=26 && s[i-2]>'0' && dp[i-2]>0)
                dp[i] += dp[i-2];
        }
        return dp[len];
    }
};
