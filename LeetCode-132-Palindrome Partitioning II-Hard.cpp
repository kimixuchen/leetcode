/**
LeetCode-132-Palindrome Partitioning II
08/09/16 07:53:55
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
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
    int minCut(string s) {
        int n = s.length();
        vector<int> cut(n+1, 0);
        for(int i=0; i<=n; ++i)
            cut[i] = i-1;
        
        for(int i=0; i<n; ++i)
        {
            //odd length palindrome
            for(int j=0; i-j>=0 && i+j<n && s[i-j]==s[i+j]; ++j)
                cut[i+j+1] = min(cut[i+j+1], cut[i-j]+1);
            
            //even length palindrome
            for(int j=0; i-j>=0 && i+j+1<n && s[i-j]==s[i+j+1]; ++j)
                cut[i+j+2] = min(cut[i+j+2], cut[i-j]+1);
        }
        return cut[n];
        
    }
};
