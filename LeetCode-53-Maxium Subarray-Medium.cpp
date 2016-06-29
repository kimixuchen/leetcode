/**
LeetCode-53-Maxium Subarray
29/06/16 09:36:29
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
    int maxSubArray(vector<int>& nums) {
        int ans = 0x80000000;
        int sum = 0x80000000;
        
        if(nums.size() == 0)
            return ans;
        
        for(int i=0; i<nums.size(); ++i)
        {
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
            sum += nums[i];
        }
        ans = max(ans, sum);
        return ans;
    }
};
