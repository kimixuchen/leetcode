/*
LeetCode-456-132 Pattern
05/12/16 09:55:16
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

const int MAX = 0x3f3f3f3f;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()==0)
            return false;
        
        bool flag = false;
        stack<int> stack;
        int s1, s2, s3;
        s1 = s2 = s3 = INT_MIN;
        
        for(int i=nums.size()-1; i>=0; --i)
        {
            s1 = nums[i];
            if(s1 < s3)
            {
                flag = true;
                break;
            }
            while(!stack.empty() && stack.top() < nums[i])
            {
                s3 = stack.top();
                stack.pop();
            }
            stack.push(nums[i]);
        }
        
        return flag;
    }
};
