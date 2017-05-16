/*
LeetCode-581-Shortest Unsorted Continuous Subarray
16/05/17 10:43:49
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
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightmin(n);
        vector<int> leftmax(n);
        
        int _min = INT_MAX;
        for(int i=n-1; i>=0; --i)
        {
            rightmin[i] = _min;
            _min = min(nums[i], _min);
        }
        int _max = INT_MIN;
        for(int i=0; i<n; ++i)
        {
            leftmax[i] = _max;
            _max = max(nums[i], _max);
        }
        
        int beg=0, end=n-1;
        while(beg<n && nums[beg]<=rightmin[beg])
            ++beg;
        while(end>=0 && nums[end]>=leftmax[end])
            --end;
        
        return max(end-beg+1, 0);
    }
};
