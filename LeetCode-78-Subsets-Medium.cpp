/**
LeetCode-78-Subsets
13/07/16 10:06:40
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
private:
    void search(vector<vector<int>>& ret, vector<int>& cell, vector<int>& nums, 
            int begin)
    {
        ret.push_back(cell);
        
        for(int i=begin; i<nums.size(); ++i)
        {
            cell.push_back(nums[i]);
            search(ret, cell, nums, i+1);
            cell.pop_back();
        }
        
        return;
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cell;
        
        search(ret, cell, nums, 0);
        
        return ret;
    }

};
