/*
LeetCode-373-Find K Pairs with Smallest Sums
21/11/16 20:26:53
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

class Solution {
private:
    struct tuple{
        int id1;
        int id2;
        int val;
        tuple(int x1, int x2, int v)
        {
            id1 = x1;
            id2 = x2;
            val = v;
        }
    };
    
    
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ret;
        if(nums1.size()==0 || nums2.size()==0)
            return ret;
        int sum = 0;
        auto cmp = [] (tuple &t1, tuple &t2) -> bool {return t1.val>t2.val;};
        priority_queue<tuple, std::vector<tuple>, decltype(cmp)> queue(cmp);
        
        for(int i=0; i<nums1.size(); ++i)
        {
            queue.push(tuple(i, 0, nums1[i]+nums2[0]));
        }
        
        for(int i=0; i<k && !queue.empty(); ++i)
        {
            tuple t = queue.top();
            queue.pop();
            pair<int, int> p = make_pair(t.id1, t.id2);
            ret.push_back(make_pair(nums1[t.id1], nums2[t.id2]));
            if(t.id2+1 < nums2.size())
                queue.push(tuple(t.id1, t.id2+1, nums1[t.id1]+nums2[t.id2+1]));
        }
        
        return ret;
        
    }
};
