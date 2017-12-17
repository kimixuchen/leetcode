/**
LeetCode-746-Min Cost Climbing Stairs
17/12/17 10:43:34
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
#include "limits.h"
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 2)
            return 0;
        
        int cost1, cost2;
        cost1 = cost2 = 0;
        
        int tmp;
        for(int step = 3; step <= n+1; step++)
        {
            tmp = cost2;
            cost2 = min(cost2+cost[step-2], cost1+cost[step-3]);
            cost1 = tmp;
        }
        return cost2;
        
    }
};
