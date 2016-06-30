/**
LeetCode-55-Jump Game
30/06/16 08:25:35
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

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right = 0;
        int pos = 0;
        while(pos<=right)
        {
            right = max(right, pos+nums[pos]);
            if(right >= nums.size()-1)
                break;
            ++pos;
        }
        if(right >= nums.size()-1)
            return true;
        else
            return false;
    }
};
