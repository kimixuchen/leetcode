/**
LeetCode-56-Merge Intervals
30/06/16 09:07:50
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;
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
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(), intervals.end(), [this](Interval& a, Interval& b)
                {
                    return a.start < b.start;
                }    
            );
        Interval cur(intervals[0].start, intervals[0].end);
        for(vector<Interval>::iterator it=intervals.begin()+1; it<intervals.end();
                ++it)
        {
            if(it->start > cur.end)
            {
                ans.push_back(cur);
                cur.start = it->start;
                cur.end = it->end;
            }
            else if(it->start <= cur.end)
            {
                cur.end = max(it->end, cur.end);
            }
        }
        ans.push_back(cur);
        return ans;
    }
};
