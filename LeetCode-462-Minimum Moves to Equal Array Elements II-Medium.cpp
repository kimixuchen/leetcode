/*
LeetCode-462-Minimum Moves to Equal Array Elements II
06/12/16 09:34:34
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
public:
    int minMoves2(vector<int>& nums) {
        vector<long long> sums(nums.size(), 0);
        long long ret = INT_MAX;
        
        sort(nums.begin(), nums.end());
        sums[0] = nums[0];
        for(int i=1; i<nums.size(); ++i)
        {
            sums[i] = sums[i-1] + nums[i];
        }
        
        long long moves;
        for(int i=0; i<sums.size(); ++i)
        {
            long long base = nums[i];
            moves = i*base-(sums[i]-base) + sums.back()-sums[i]-
                (sums.size()-i-1)*base;
            ret = min(ret, moves);
        }
        
        return (int)ret;
        
    }
};
