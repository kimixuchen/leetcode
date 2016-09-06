/**
LeetCode-128-Longest Consecutive Sequence
06/09/16 14:18:39
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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> allnums;
        for(int i=0; i<nums.size(); ++i)
            allnums.insert(nums[i]);
        
        int len = 0;
        while(allnums.size() > 0)
        {
            int num = *allnums.begin();
            allnums.erase(num);
            int curlen = 1;
            queue<int> q;
            q.push(num);
            while(!q.empty())
            {
                int curnum = q.front();
                q.pop();
                if(allnums.find(curnum+1) != allnums.end())
                {
                    q.push(curnum+1);
                    allnums.erase(curnum+1);
                    ++curlen;
                }
                if(allnums.find(curnum-1) != allnums.end())
                {
                    q.push(curnum-1);
                    allnums.erase(curnum-1);
                    ++curlen;
                }
            }
            len = max(len, curlen);
        }
        
        return len;
    }
};
