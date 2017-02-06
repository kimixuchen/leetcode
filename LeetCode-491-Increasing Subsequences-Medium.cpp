/*
LeetCode-491-Increasing Subsequences
06/02/17 09:03:48
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
private:
    void search(vector<int> &nums, vector<vector<int>> &ret, int pos, 
            vector<int> cur)
    {
        if(pos>=nums.size())
            return;
        
        cur.push_back(nums[pos]);
        if(cur.size()>1)
        {
            ret.push_back(cur);
        }
        
        unordered_map<int, bool> used;
        for(int i=pos+1; i<nums.size(); ++i)
        {
            if(nums[i]>=nums[pos] && 
                    used.find(nums[i])==used.end())
            {
                search(nums, ret, i, cur);
                used[nums[i]] = true;
            }
        }
        
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ret;
        
        unordered_map<int, bool> used;
        for(int i=0; i<nums.size(); ++i)
        {
            if(used.find(nums[i])==used.end())
            {
                search(nums, ret, i, vector<int>());
                used[nums[i]] = true;
            }
        }
        
        return ret;
    }
};
