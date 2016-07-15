#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

class Solution {
public:
    void search(vector<int>& nums, vector<vector<int>>& ret, vector<int>& cur, int begin)
    {
        ret.push_back(cur);
        
        for(int i=begin; i<nums.size(); ++i)
        {
            if(i==begin || nums[i]!=nums[i-1])
            {
                cur.push_back(nums[i]);
                search(nums, ret, cur, i+1);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        search(nums, ret, cur, 0);
        
        return ret;
    }
};