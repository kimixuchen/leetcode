/**
LeetCode-57-Insert Interval
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i=0;
        while(i<intervals.size() && intervals[i].end < newInterval.start)
            ++i;
        int a = i, b;
        while(i<intervals.size() && intervals[i].start <= newInterval.end)
        {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            ++i;    
        }
        b = i;
        intervals.erase(intervals.begin()+a, intervals.begin()+b);
        intervals.insert(intervals.begin()+a, newInterval);
        
        return intervals;
        
    }
};
