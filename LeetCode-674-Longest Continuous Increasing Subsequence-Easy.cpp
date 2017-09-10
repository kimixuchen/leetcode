/**
LeetCode-674-Longest Continuous Increasing Subsequence
10/09/17 09:31:03
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
#include <limits>
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
    int findLengthOfLCIS(vector<int>& nums) {
        int len = 1;
        if(nums.size() == 0)
            return 0;
        
        int t = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
            {
                t++;
            }
            else
            {
                t = 1;
            }
            len = max(len, t);
        }
        
        return len;
    }
};
