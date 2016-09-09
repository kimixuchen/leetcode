/**
LeetCode-137-Single Number II
09/09/16 09:03:38
xuchen
**/

#include <iostream>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <map>
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
    int singleNumber(vector<int>& nums) {
        vector<int> digits(32, 0);
        for(int i=0; i<32; ++i)
        {
            for(int j=0; j<nums.size(); ++j)
            {
                digits[i] += ((nums[j] & (1<<i))!=0);
                digits[i] %= 3;
            }
        }
        
        int single = 0;
        for(int i=0; i<32; ++i)
        {
            if(digits[i] > 0)
                single |= (1<<i);
        }
        
        return single;

    }
};
