/*
LeetCode-330-Patching Array
04/11/16 09:29:48
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
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int counter = 0;
        long long miss = 1;
        int pos=0;
        while(miss<=n)
        {
            if(pos<nums.size() && nums[pos]<=miss)
            {
                miss += nums[pos];
                ++pos;
            }
            else
            {
                counter++;
                miss += miss;
            }
        }
        return counter;
        
    }
};
