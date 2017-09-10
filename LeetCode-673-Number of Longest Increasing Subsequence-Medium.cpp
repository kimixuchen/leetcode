/**
LeetCode-673-Number of Longest Increasing Subsequence
10/09/17 09:56:31
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
#include <limits>
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
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int n = nums.size();
        vector<int> counts(n+1);
        vector<int> lens(n);
        vector<int> poscounts(n+1);
        
        lens[0] = 1;
        counts[1]++;
        poscounts[0] = 1;
        
        for(int i=1; i<n; i++)
        {
            int max_len = 1;
            int max_count = 1;
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                {
                    if(max_len < lens[j]+1)
                    {
                        max_len = lens[j]+1;
                        max_count = poscounts[j];
                    }
                    else if(max_len == lens[j]+1)
                    {
                        max_count += poscounts[j];
                    }
                }
            }
            lens[i] = max_len;
            counts[max_len] += max_count;
            poscounts[i] = max_count;
        }
        
        int ret = 0;
        for(int i=n; i>0; i--)
        {
            if(counts[i]>0)
            {
                ret = counts[i];
                break;
            }
        }
        
        return ret;
    }
};
