/**
LeetCode-279-Perfect Squares
19/10/16 09:55:10
xuchen
**/

#include <iostream>
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
    int numSquares(int n) {
        if(n <= 0)
            return 0;
        
        static vector<int> cnts(1, 0);
        
        while(cnts.size()<=n+1)
        {
            int m = cnts.size();
            int cnt = INT_MAX;
            for(int i=1; i*i<=m; ++i)
            {
                cnt = min(cnt, cnts[m-i*i]+1);
            }
            cnts.push_back(cnt);
        }
        return cnts[n];
        
    }
};
