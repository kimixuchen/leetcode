/**
LeetCode-228-Summary Ranges
11/10/16 08:46:52
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
private:
    string getRange(int l, int r)
    {
        string s = to_string(l);
        if(l==r)
            return s;
        s += "->"+to_string(r);
        
        return s;
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if(nums.size()==0)
            return ret;
        int l = nums[0];
        
        for(int i=1; i<nums.size(); ++i)
        {
            if(nums[i]-nums[i-1]==1)
                continue;
            
            ret.push_back(getRange(l, nums[i-1]));
            l = nums[i];
        }
        ret.push_back(getRange(l, nums.back()));
        
        return ret;
        
    }
};
