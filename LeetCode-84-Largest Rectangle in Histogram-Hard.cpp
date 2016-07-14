/**
LeetCode-84-Largest Rectangle in Histogram
14/07/16 12:41:41
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
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int ret = 0;
        for(int i=0; i<heights.size(); ++i)
        {
            if(s.empty() || s.top().first<=heights[i])
            {
                s.push(make_pair(heights[i], 1));
            }
            else
            {
                int width = 0;
                while(!s.empty() && s.top().first>heights[i])
                {
                    auto r = s.top();
                    s.pop();
                    width += r.second;
                    ret = max(ret, r.first*width);
                }
                s.push(make_pair(heights[i], width+1));
            }
        }
        int width = 0;
        while(!s.empty())
        {
            auto r = s.top();
            s.pop();
            width += r.second;
            ret = max(ret, r.first*width);
        }
        
        return ret;
        
    }
};
