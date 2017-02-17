/*
LeetCode-493-Reserve Pairs
12/02/17 11:04:56
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <priority_queue>
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
private:
    int mergeSort(vector<int>& nums, int s, int e)
    {
        if(s>=e)
            return 0;
        
        int mid = s+(e-s)/2;
        
        int ret = mergeSort(nums, s, mid) + mergeSort(nums, mid+1, e);
        
        for(int i=s, j=mid+1; i<=mid; ++i)
        {
            while(j<=e && (long long)nums[i]>2LL*nums[j])
                ++j;
            ret += j-(mid+1);
        }
        
        merge(nums, s, mid, e);
        
        return ret;
    }
    
    void merge(vector<int>& nums, int s, int mid, int e)
    {
        vector<int> helper(nums.begin()+s, nums.begin()+e+1);
        
        int p1=s;
        int p2=mid+1;
        int p=s;
        
        while(p1<=mid || p2<=e)
        {
            if(p1>mid || (p2<=e && helper[p1-s]>=helper[p2-s]))
            {
                nums[p++] = helper[p2++-s];
            }
            else
            {
                nums[p++] = helper[p1++-s];
            
            }
        }
    }

public:
    int reversePairs(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        
        if(n<2)
            return ret;
        
        ret = mergeSort(nums, 0, n-1);
        /**
        for(int v : nums)
        {
            printf("%d ", v);
        }
        printf("\n");
        **/
        
        return ret;
    }
};
