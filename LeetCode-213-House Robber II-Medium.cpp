/**
LeetCode-213-House Robber II
27/09/16 10:22:32
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        
        vector<int> norob(n);
        vector<int> rob(n);
        int maxrob = INT_MIN;
        rob[0] = nums[0];
        norob[1] = rob[0];
        for(int i=2; i<n-1; ++i)
        {
            rob[i] = norob[i-1]+nums[i];
            norob[i] = max(rob[i-1], norob[i-1]);
            maxrob = max(maxrob, rob[i]);
            maxrob = max(maxrob, norob[i]);
        }
        maxrob = max(maxrob, max(rob[n-2], norob[n-2]));
        rob[0] = 0;
        norob[0] = 0;
        for(int i=1; i<n; ++i)
        {
            rob[i] = norob[i-1]+nums[i];
            norob[i] = max(rob[i-1], norob[i-1]);
            maxrob = max(maxrob, rob[i]);
            maxrob = max(maxrob, norob[i]);
        }
        return maxrob;
    }
};
