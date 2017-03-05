/*
LeetCode-532-K-diff Pairs in an Array
05/03/17 10:30:36
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <priority_queue>
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
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> numsmap;
        
        if(k<0)
            return 0;
        int n = nums.size();
        for(int i : nums)
        {
            numsmap[i]++;
        }
        
        int ret = 0;
        for(int i : nums)
        {
            if(numsmap[i] != 0)
            {
                if(k==0)
                {
                    if(numsmap[i]>1)
                    {
                        ++ret;
                        numsmap[i] = 0;
                    }
                }
                else
                {
                    int a1 = i-k;
                    int a2 = i+k;
                    if(numsmap.find(a1)!=numsmap.end() && numsmap[a1]>0)
                    {
                        ++ret;
                        numsmap[i] = 0;
                    }
                    if(numsmap.find(a2)!=numsmap.end() && numsmap[a2]>0)
                    {
                        ++ret;
                        numsmap[i] = 0;
                    }
                }
            }
        }
        return ret;
        
    }
};
