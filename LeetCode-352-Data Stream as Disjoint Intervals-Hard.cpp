/*
LeetCode-352-Data Stream as Disjoint Intervals
16/11/16 09:21:43
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
class SummaryRanges {
private:
    vector<Interval> container;
    static bool cmp(const Interval &it1, const Interval &it2)
    {
        return it1.start < it2.start;
    }
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval it(val, val);
        if(container.size() == 0)    //be first interval
        {
            container.push_back(it);
            return;
        }
        auto l = lower_bound(container.begin(), container.end(), it, 
                cmp);
        
        auto a = l==container.begin() ? l : l-1;
        auto b = l==container.end() ? l-1 : l;
        
        //already exists
        if(a->start<=val && a->end>=val)    return;
        if(b->start<=val && b->end>=val)    return;
        
        if(a->end+1==val && b->start-1==val)
        {
            a->end = b->end;
            container.erase(b);
            return;
        }
        if(a->end+1==val)
        {
            a->end = val;
            return;
        }
        if(b->start-1==val)
        {
            b->start = val;
            return;
        }
        
        container.insert(l, it);
        
    }
    
    vector<Interval> getIntervals() {
        return container;
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
