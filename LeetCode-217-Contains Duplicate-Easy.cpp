/**
LeetCode-217-Contains Duplicate
28/09/16 10:40:03
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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); ++i)
        {
            if(s.find(nums[i]) != s.end())
            {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
        
    }
};
