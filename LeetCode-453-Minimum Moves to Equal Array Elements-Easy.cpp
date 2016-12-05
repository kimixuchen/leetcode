/*
LeetCode-453-Minimum Moves to Equal Array Elements
05/12/16 08:54:33
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
    int minMoves(vector<int>& nums) {
        int ret = 0;
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-2; i>=0; --i)
        {
            ret += (nums[i+1]-nums[i])*(nums.size()-i-1);
        }
        return ret;
        
    }
};
