/**
LeetCode-239-Sliding Window Maximum
17/10/16 10:04:14
xuchen
**/

#include <iostream>
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        vector<int> leftmax(nums.size());
        vector<int> rightmax(nums.size());
        if(nums.size()==0 || k==0)
            return ret;
        
        int _max;
        for(int i=0; i<nums.size(); ++i)
        {
            if(i%k==0)
            {
                leftmax[i] = nums[i];
            }
            else
            {
                leftmax[i] = max(leftmax[i-1], nums[i]);
            }
        }
        
        for(int i=nums.size()-1; i>=0; --i)
        {
            if(i==nums.size()-1 || (i+1)%k==0)
            {
                rightmax[i] = nums[i];
            }
            else
            {
                rightmax[i] = max(nums[i], rightmax[i+1]);
            }
        }
        
        for(int pos=0; pos<nums.size()-k+1; ++pos)
        {
            ret.push_back(max(rightmax[pos], leftmax[pos+k-1]));
        }
        
        return ret;
    }
};
