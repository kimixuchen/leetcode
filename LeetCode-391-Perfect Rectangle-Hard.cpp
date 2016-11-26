/*
LeetCode-391-Perfect Rectangle
26/11/16 10:28:43
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
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class Solution {

public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> pointsCounts;
        int m = 0;
        
        pair<int, int> leftdown = make_pair(INT_MAX, INT_MAX);
        pair<int, int> leftup = make_pair(INT_MAX, INT_MIN);
        pair<int, int> rightdown = make_pair(INT_MIN, INT_MAX);
        pair<int, int> rightup = make_pair(INT_MIN, INT_MIN);
        
        for(auto rect : rectangles)
        {
            m += (rect[3]-rect[1])*(rect[2]-rect[0]);
            if(pointsCounts.find(make_pair(rect[0], rect[1])) == 
                    pointsCounts.end())
                pointsCounts[make_pair(rect[0], rect[1])] = 1;
            else
                pointsCounts[make_pair(rect[0], rect[1])]++;
            
            if(pointsCounts.find(make_pair(rect[2], rect[3])) == 
                    pointsCounts.end())
                pointsCounts[make_pair(rect[2], rect[3])] = 1;
            else
                pointsCounts[make_pair(rect[2], rect[3])]++;
            
            if(pointsCounts.find(make_pair(rect[0], rect[3])) == 
                    pointsCounts.end())
                pointsCounts[make_pair(rect[0], rect[3])] = 1;
            else
                pointsCounts[make_pair(rect[0], rect[3])]++;
            
            if(pointsCounts.find(make_pair(rect[2], rect[1])) == 
                    pointsCounts.end())
                pointsCounts[make_pair(rect[2], rect[1])] = 1;
            else
                pointsCounts[make_pair(rect[2], rect[1])]++;
            
            if(rect[0]<leftdown.first)
            {
                leftdown.first = rect[0];
                leftdown.second = rect[1];
            }
            else if(rect[0]==leftdown.first)
                leftdown.second = min(rect[1], leftdown.second);
            
            if(rect[0] < leftup.first)
            {
                leftup.first = rect[0];
                leftup.second = rect[3];
            }
            else if(rect[0]==leftup.first)
                leftup.second = max(rect[3], leftup.second);
            
            if(rect[2]>rightdown.first)
            {
                rightdown.first = rect[2];
                rightdown.second = rect[1];
            }
            else if(rect[2]==rightdown.first)
                rightdown.second = min(rect[1], rightdown.second);
            
            if(rect[2]>rightup.first)
            {
                rightup.first = rect[2];
                rightup.second = rect[3];
            }
            else if(rect[2]==rightup.first)
                rightup.second = max(rect[3], rightup.second);
        }
        
        int m1 = (rightup.first-leftdown.first)*(rightup.second-leftdown.second);
        if(m!=m1)
            return false;
        
        bool flag = true;
        for(auto it = pointsCounts.begin(); it != pointsCounts.end(); ++it)
        {
            if((it->second)%2 == 1)
            {
                if(it->first != leftdown && it->first != leftup && 
                    it->first != rightdown && it->first != rightup)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(pointsCounts[leftdown]!=1 || pointsCounts[leftup]!=1 || pointsCounts[rightdown]!=1 || 
                pointsCounts[rightup]!=1)
            flag = false;
        
        return flag;
    }
};
