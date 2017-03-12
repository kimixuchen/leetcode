/*
LeetCode-539-Minimum Time Difference
12/03/17 10:49:15
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
private:
    int toMiniutes(string& t)
    {
        int h = 10*(t[0]-'0') + t[1]-'0';
        int m = 10*(t[3]-'0') + t[4]-'0';
        
        return h*60+m;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> miniutes(n);
        
        for(int i=0; i<n; ++i)
        {
            miniutes[i] = toMiniutes(timePoints[i]);
        }
        
        sort(miniutes.begin(), miniutes.end());
        
        int M = 24*60;
        int _min = (miniutes[0]+M-miniutes[n-1]) % M;
        for(int i=1; i<n; ++i)
        {
            _min = min(_min, miniutes[i]-miniutes[i-1]);
        }
        
        return _min;
        
    }
};
