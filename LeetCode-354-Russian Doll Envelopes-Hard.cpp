/*
LeetCode-354-Russian Doll Envelopes
17/11/16 09:15:06
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

class Solution {
private:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first < b.first;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if(n==0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        vector<int> dp(n, 1);
        int _max = 0;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(envelopes[j].first < envelopes[i].first && 
                    envelopes[j].second < envelopes[i].second)
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            _max = max(_max, dp[i]);
        }
        
        return _max;
        
    }
};
