/**
LeetCode-162-Find Peak Element
19/09/16 10:19:34
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
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        
        if(nums[0] > nums[1])
            return 0;
        
        if(nums[n-1] > nums[n-2])
            return n-1;
        
        int i=1;
        for( ; i<n-1; ++i)
        {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
                break;
        }
        return i;
        
    }
};
