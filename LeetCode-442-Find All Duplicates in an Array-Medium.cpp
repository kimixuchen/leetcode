/*
LeetCode-442-Find All Duplicates in an Array
12/01/17 09:36:20
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
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int num : nums)
        {
            int id = abs(num)-1;
            if(nums[id]<0)
                ret.push_back(id+1);
            nums[id] = -nums[id];
        }
        for(int i=0; i<nums.size(); ++i)
            nums[i] = abs(nums[i]);
        
        return ret;
    }
};
