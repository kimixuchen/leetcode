/*
LeetCode-436-Find Right Interval
02/12/16 10:09:58
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
    struct InterPos{
        int pos;
        int start;
        InterPos(int pos, int start)
        {
            this->pos = pos;
            this->start = start;
        }
    };

    static bool cmp(InterPos &ip1, InterPos &ip2)
    {
        return ip1.start < ip2.start;
    }

    int bsearch(int end, vector<InterPos> &interpos)
    {
        int l = 0;
        int r = interpos.size();
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(interpos[mid].start < end)
                l = mid+1;
            else
                r = mid;
        }
        int rightpos;
        if(l==interpos.size())
            rightpos = -1;
        else
            rightpos = interpos[l].pos;
        return rightpos;
    }

public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<InterPos> interpos;
        for(int i=0; i<intervals.size(); ++i)
        {
            InterPos t(i, intervals[i].start);
            interpos.push_back(t);
        }
        
        sort(interpos.begin(), interpos.end(), cmp);
        
        vector<int> ret;
        for(int i=0; i<intervals.size(); ++i)
        {
            int rightpos = bsearch(intervals[i].end, interpos);
            ret.push_back(rightpos);
        }
        
        return ret;
        
    }
};
