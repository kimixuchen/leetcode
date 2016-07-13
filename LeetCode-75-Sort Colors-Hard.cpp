/**
LeetCode-75-Sort Colors
13/07/16 08:27:26
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
public:
    void sortColors(vector<int>& nums) {
        int dump[3]={0,0,0};
        for(int i=0; i<nums.size(); ++i)
            dump[nums[i]]++;
        
        int pos = 0;
        for(int i=0; i<3; ++i)
        {
            for(int j=0; j<dump[i]; ++j)
            {
                nums[pos] = i;
                ++pos;
            }
        }
    }
};
