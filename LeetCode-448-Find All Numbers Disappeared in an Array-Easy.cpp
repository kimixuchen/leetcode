/*
LeetCode-448-Find All Numbers Disappeared in an Array
13/01/17 09:06:37
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        
        for(int num : nums)
        {
            int id = abs(num)-1;
            if(nums[id]>0)
                nums[id] = -nums[id];
        }
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i]>0)
                ret.push_back(i+1);
            nums[i] = abs(nums[i]);
        }
        return ret;
    }
};
