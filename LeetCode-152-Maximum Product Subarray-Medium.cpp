/**
LeetCode-152-Maximum Product Subarray
19/09/16 08:11:11
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
private:
    int getMax(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return INT_MIN;
        
        int pos1=-1, pos2=-1;
        int _max=INT_MIN, product=1;
        for(int i=start; i<=end; ++i)
        {
            product *= nums[i];
            if(nums[i]<0)
            {
                if(pos1==-1)
                    pos1 = i;
                pos2 = i;
            }
        }
        _max = product;
        if(_max < 0)
        {
            int product1=INT_MIN, product2=INT_MIN;
            if(pos2 > start)
            {
                product1 = 1;
                for(int i=start; i<pos2; ++i)
                    product1 *= nums[i];
            }
            if(pos1 < end)
            {
                product2 = 1;
                for(int i=pos1+1; i<=end; ++i)
                    product2 *= nums[i];
            }
            _max = max(_max, product1);
            _max = max(_max, product2);
        }
        return _max;
    }
public:
    int maxProduct(vector<int>& nums) {
        int start;
        start=0;
        int maxP = INT_MIN;
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i]==0)
            {
                maxP = max(maxP, getMax(nums, start, i-1));
                maxP = max(maxP, 0);
                start = i+1;
            }
        }
        if(start < nums.size())
            maxP = max(maxP, getMax(nums, start, nums.size()-1));
        
        return maxP;
        
    }
};
