/**
LeetCode-287-Find the Duplicate Number
20/10/16 08:33:21
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
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n;
        int mid;
        while(left < right)
        {
            mid = (left+right)/2;
            int counter = 0;
            for(int i=0; i<n; ++i)
                if(nums[i]<=mid)
                    ++counter;
            if(counter>mid)
                right = mid;
            else
                left = mid+1;
        }
        return left;
        
    }
};
