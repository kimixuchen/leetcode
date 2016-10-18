/**
LeetCode-268-Missing Number
18/10/16 08:32:10
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
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int left=0, right=nums.size(), mid;
        while(left<right)
        {
            mid = (left+right)/2;
            if(nums[mid]>mid)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};
