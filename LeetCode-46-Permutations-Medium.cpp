/**
LeetCode-46-Permutations
25/05/16 19:43:07
xuchen
**/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        solve(ans, nums, 0);
        
        return ans;
        
    }

    void solve(vector<vector<int>>& ans, vector<int>& nums, int begin){
        if(begin>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=begin; i<nums.size(); ++i)
        {
            swap(nums[begin], nums[i]);
            solve(ans, nums, begin+1);
            swap(nums[begin], nums[i]);
        }
    }
};
