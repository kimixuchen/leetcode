/**
LeetCode-219-Contains Duplicate II
09/10/16 09:46:51
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int pos = 0;
        for( ; pos<=k && pos<nums.size(); ++pos)
        {
            if(s.find(nums[pos]) != s.end())
                return true;
            s.insert(nums[pos]);
        }
        
        while(pos<nums.size())
        {
            s.erase(nums[pos-1-k]);
            if(s.find(nums[pos]) != s.end())
                return true;
            s.insert(nums[pos]);
            ++pos;
        }
        return false;
    }
};
