/*
LeetCode-414-Third Maximum Number
30/11/16 10:35:45
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
    int thirdMax(vector<int>& nums) {
        int max1=INT_MIN;
        int max2=INT_MIN;
        int max3=INT_MIN;
        
        bool hasmin = false;
        for(int a : nums)
        {
            if(a==INT_MIN)
                hasmin = true;
            
            if(a>max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = a;
            }
            else if(a>max2 && a!=max1)
            {
                max3 = max2;
                max2 = a;
            }
            else if(a>max3 && a!=max2 && a!=max1)
            {
                max3 = a;
            }
        }
        
        if(hasmin && max1!=INT_MIN && max2!=INT_MIN)
            return max3;
        
        if(max3==INT_MIN)
            return max1;
        else
            return max3;
        
    }
};
