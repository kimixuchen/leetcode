/**
LeetCode-179-Largest Number
04/03/16 08:33:23
xuchen
**/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace std;

bool cmp(int a, int b)
{
    return to_string(a)+to_string(b) > to_string(b)+to_string(a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string retStr = "";
        sort(nums.begin(), nums.end(), cmp);
        for(auto i: nums)
        {
            retStr += to_string(i);
        }
        if(retStr.length() > 1)
        {
            int i=0;
            while(i<retStr.size()-1 && retStr[i]=='0') ++i;
            retStr = retStr.substr(i);
        }
        return retStr;
        
    }
};

int main()
{
    Solution s = new Solution();
    printf("%s\n", s.largestNumber({3, 30, 34, 5, 9}));

    return 0;
}
