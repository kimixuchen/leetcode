/*
LeetCode-435-Non-overlapping Intervals
02/12/16 09:40:49
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

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool cmp(Interval &interval1, Interval &interval2)
    {
        if(interval1.start==interval2.start)
            return interval1.end < interval2.end;
        else
            return interval1.start < interval2.start;
    }

public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        int n = intervals.size();
        int pos = 0;
        int counter = 0;
        for(int i=1; i<n; ++i)
        {
            if(intervals[pos].end > intervals[i].start)
            {
                ++counter;
                if(intervals[pos].end > intervals[i].end)
                {
                    pos = i;
                }
            }
            else
                pos = i;
        }
        
        return counter;
        
    }
};
