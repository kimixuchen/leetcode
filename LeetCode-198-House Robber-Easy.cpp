/**
LeetCode-198-House Robber
23/09/16 08:02:38
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<1)
            return 0;
        
        int prerobmax, prenorobmax;
        prerobmax = nums[0];
        prenorobmax = 0;
        for(int i=1; i<n; ++i)
        {
            int t = prenorobmax;
            prenorobmax = max(prerobmax, prenorobmax);
            prerobmax = t + nums[i];
        }
        
        return max(prerobmax, prenorobmax);
        
    }
};
