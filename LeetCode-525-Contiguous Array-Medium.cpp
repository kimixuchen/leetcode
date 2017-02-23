/*
LeetCode-525-Contiguous Array
23/02/17 20:02:40
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
    int findMaxLength(vector<int>& nums) {
        vector<int> cpnums;
        
        for(int i : nums)
        {
            cpnums.push_back(i==0 ? -1:1);
        }
        
        unordered_map<int, int> sums;
        sums[0] = -1;
        
        int sum = 0;
        int len = 0;
        for(int i=0; i<cpnums.size(); ++i)
        {
            sum += cpnums[i];
            if(sums.find(sum) != sums.end())
            {
                len = max(len, i-sums[sum]);
            }
            else
            {
                sums[sum] = i;
            }
        }
        return len;
    }
};
