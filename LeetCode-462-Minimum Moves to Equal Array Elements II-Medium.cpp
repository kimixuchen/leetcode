/*
LeetCode-462-Minimum Moves to Equal Array Elements II
20/11/16 10:50:02
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

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sums(n);
        sums[0] = nums[0];
        for(int i=1; i<n; ++i)
        {
            sums[i] = nums[i] + sums[i-1];
        }
        
        long long pre = 0;
        long long after = 0;
        long long moves = INT_MAX;
        for(int i=0; i<n; ++i)
        {
            if(i==0)
                pre = 0;
            else
            {
                pre = (long long)nums[i]*(i) - sums[i-1];
            }
            if(i==n-1)
                after = 0;
            else
            {
                after = sums[n-1]-sums[i]-(long long)nums[i]*(n-1-i);
            }
            moves = min(moves, pre+after);
        }
        return moves;
        
    }
};
