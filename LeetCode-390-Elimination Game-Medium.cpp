/*
LeetCode-390-Elimination Game
26/11/16 09:40:07
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
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)
            return 1;
        
        vector<int> nums;
        
        while(n > 0)
        {
            nums.push_back(n);
            n /= 2;
        }
        
        int base = 1;
        for(int i=nums.size()-2; i>=0; --i)
        {
            if(i%2==0)
                base *= 2;
            else
            {
                if(nums[i]%2==1)
                    base *= 2;
                else
                    base = base*2-1;
            }
        }
        
        return base;
    }
};
