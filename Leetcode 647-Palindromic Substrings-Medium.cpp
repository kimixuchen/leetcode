/*
 * Leetcode 647-Palindromic Substrings
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

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for(int i=0; i<n; i++) {
            dp[i][i] = true;
        }
        for(int k=1; k<n; k++) {
            for(int i=0; i+k<n; i++) {
                if(s[i] == s[i+k]) {
                    if(k==1 || dp[i+1][i+k-1]==true) {
                        dp[i][i+k] = true;
                    }
                }
            }
        }
        
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(dp[i][j])
                    ++sum;
            }
        }
        
        return sum;
    }
};