/*
LeetCode-452-Minimum Number of Arrows to Burst Balloons
04/12/16 10:13:35
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

const int MAX = 0x3f3f3f3f;

class Solution {
private:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second==p2.second ? p1.first < p2.first : p1.second < p2.second;
    }

public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int ret = 0;
        int arrow = INT_MIN;
        sort(points.begin(), points.end(), cmp);
        for(int i=0; i<points.size(); ++i)
        {
            if(points[i].first!=INT_MIN && arrow >= points[i].first)
            {
                continue;
            }
            else
            {
                ret += 1;
                arrow = points[i].second;
            }
        }
        return ret;
        
    }
};
