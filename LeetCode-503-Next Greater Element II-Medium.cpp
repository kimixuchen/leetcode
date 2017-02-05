/*
LeetCode-503-Next Greater Element II
05/02/17 10:48:41
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
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret;
        
        int n = nums.size();
        for(int i=0; i<n; ++i)
        {
            int next = nums[i];
            for(int j=i+1; j<=n && j!=i; ++j)
            {
                if(j==n)
                {
                    j=-1;
                    continue;
                }
                if(nums[j]>nums[i])
                {
                    next = nums[j];
                    break;
                }
            }
            if(next==nums[i])
                ret.push_back(-1);
            else
                ret.push_back(next);
        }
        return ret;
    }
};
