/*
 * Leetcode 646-Maximum Length of Pair Chain
 */
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

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int n = pairs.size();
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for(int i=1; i<n; i++) {
            dp[i] = 1;
            for(int j=0; j<i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        
        int _max = INT_MIN;
        for(int i=0; i<n; i++) {
            _max = max(_max, dp[i]);
        }
        return _max;
    }
};
