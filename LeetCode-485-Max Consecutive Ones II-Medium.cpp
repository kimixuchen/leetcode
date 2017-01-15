/*
LeetCode-485-Max Consecutive Ones II
15/01/17 10:36:41
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        int _max = 0;
        int start = 0, end = 0;
        int posZero = -1;
        int numZero = 0;
        while(end < nums.size())
        {
            if(nums[end]==0)
            {
                if(numZero==0)
                {
                    ++numZero;
                }
                else
                {
                    _max = max(_max, end-start);
                    start = posZero+1;
                }
                posZero = end;
            }
            ++end;
        }
        _max = max(_max, end-start);
        
        return _max;
        
    }
};
