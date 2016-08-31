/**
LeetCode-115-Distinct Subsequences
31/08/16 08:11:43
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

/**
 * 1. Use one dimension array otherwise two dimension to save memory.
 * 2. The size of array is t.length() otherwise s.length(), this can also save
 * memory without extra time complexity
**/
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> dp(t.length()+1, 0);
        int preVal;
        int tmpPre;
        for(int i=0; i<s.length(); ++i)
        {
            preVal = 1;
            for(int j=0; j<t.length(); ++j)
            {
                tmpPre = dp[j+1];
                if(s[i]==t[j])
                    dp[j+1] += preVal;
                
                preVal = tmpPre;
            }
        }
        return dp[t.length()];
    }
};
