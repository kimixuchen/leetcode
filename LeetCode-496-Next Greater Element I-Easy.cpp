/*
LeetCode-496-Next Greater Element I
05/02/17 10:32:03
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
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n1 = findNums.size();
        int n2 = nums.size();
        unordered_map<int, int> numpos;
        
        for(int i=0; i<n2; ++i)
        {
            numpos[nums[i]] = i;
        }
        
        vector<int> ret;
        for(int i : findNums)
        {
            int pos = numpos[i];
            int next = i;
            for(int j=pos+1; j<n2; ++j)
            {
                if(nums[j]>i)
                {
                    next = nums[j]; 
                    break;
                }
            }
            if(next == i)
                ret.push_back(-1);
            else
                ret.push_back(next);
        }
        return ret;
    }
};
