/*
LeetCode-553-Optimal Division
16/04/17 09:49:40
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
    string optimalDivision(vector<int>& nums) {
        string s;
        s.append(to_string(nums[0]));
        if(nums.size()==1)
            return s;
        
        if(nums.size()==2)
        {
            s.append("/");
            s.append(to_string(nums[1]));
            return s;
        }
        
        s.append("/");
        s.append("(");
        for(int i=1; i<nums.size()-1; ++i)
        {
            s.append(to_string(nums[i]));
            s.append("/");
        }
        s.append(to_string(nums[nums.size()-1]));
        s.append(")");
        
        return s;
        
    }
};
