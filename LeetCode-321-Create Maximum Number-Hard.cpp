/*
LeetCode-321-Create Maximum Number
28/10/16 09:40:24
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
private:
    vector<int> maxArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(k, 0);
        int pos = -1;
        for(int i=0; i<n; ++i)
        {
            while(pos>=0 && (ans[pos]<nums[i]) && (k-pos<=n-i))
            {
                --pos;
            }
            if(pos<k-1)
            {
                ++pos;
                ans[pos] = nums[i];
            }
        }
        return ans;
    }
    
    vector<int> mergeSort(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ret;
        int pos1 = 0, pos2 = 0;
        int k = nums1.size() + nums2.size();
        int r = 0;
        for( ; r<k; ++r)
        {
            if(bigger(nums1, nums2, pos1, pos2))
                ret.push_back(nums1[pos1++]);
            else
                ret.push_back(nums2[pos2++]);
        }
        return ret;
    }
    
    bool bigger(vector<int> &nums1, vector<int> &nums2, int pos1, int pos2)
    {
        while(pos1<nums1.size() && pos2<nums2.size())
        {
            if(nums1[pos1]>nums2[pos2])
                return true;
            else if(nums1[pos1]<nums2[pos2])
                return false;
            ++pos1;
            ++pos2;
        }
        if(pos1<nums1.size())
            return true;
        
        return false;
    }
    
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int mincount, maxcount;
        int a = k-nums2.size();
        if(a>0)
        {
            mincount = k-nums2.size();
        }
        else
            mincount = 0;
        int b = k-nums1.size();
        if(b>0)
            maxcount = nums1.size();
        else
            maxcount = k;
        
        vector<int> ret;
        for(int i=mincount; i<=maxcount; ++i)
        {
            vector<int> max1 = maxArray(nums1, i);
            vector<int> max2 = maxArray(nums2, k-i);
            vector<int> max3 = mergeSort(max1, max2);
            if(bigger(max3, ret, 0, 0))
                ret = max3;
        }
        return ret;
    }
};
