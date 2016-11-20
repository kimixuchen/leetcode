/*
LeetCode-368-Largest Divisible Subset
20/11/16 09:40:01
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return vector<int>();
        vector<vector<int>> sets(n);
        
        sort(nums.begin(), nums.end());
        sets[0].push_back(nums[0]);
        
        for(int i=1; i<n; ++i)
        {
            int tmp = 0;
            int index = -1;
            for(int j=0; j<i; ++j)
            {
                if(nums[i]%nums[j]==0 && sets[j].size()>tmp)
                {
                    tmp = sets[j].size();
                    index = j;
                }
            }
            if(index != -1)
                sets[i] = sets[index];
            sets[i].push_back(nums[i]);
        }
        
        int tmp = 0;
        int index = 0;
        for(int i=0; i<n; ++i)
        {
            if(sets[i].size()>tmp)
            {
                tmp = sets[i].size();
                index = i;
            }
        }
        
        return sets[index];
        
    }
};
