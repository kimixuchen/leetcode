/**
LeetCode-238-Product of Array Except Self
12/10/16 10:43:53
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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size());
        int p = 1;
        for(int i=0; i<nums.size(); ++i)
        {
            ret[i] = p;
            p *= nums[i];
        }
        p = 1;
        for(int i=nums.size()-1; i>=0; --i)
        {
            ret[i] = ret[i]*p;
            p*=nums[i];
        }
        return ret;
        
    }
};
