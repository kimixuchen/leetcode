/*
LeetCode-485-Max Consecutive Ones
15/01/17 10:32:32
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
        int _max = 0;
        int cur = 0;
        for(int i : nums)
        {
            if(i==0)
            {
                _max = max(_max, cur);
                cur = 0;
            }
            else
            {
                ++cur;
            }
        }
        _max = max(_max, cur);
        
        return _max;
        
    }
};
