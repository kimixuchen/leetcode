/*
LeetCode-403-Frog Jump
29/11/16 10:53:11
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
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

const int MAX = 0x3f3f3f3f;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<set<int>> reach(n, set<int>());
        unordered_map<int, int> distances;
        for(int i=0; i<stones.size(); ++i)
        {
            distances[stones[i]] = i;
        }
        
        reach[0].insert(1);
        for(int i=0; i<n; ++i)
        {
            for(int step : reach[i])
            {
                int next = stones[i]+step;
                if(distances.find(next)!=distances.end())
                {
                    if(step-1>=0)
                        reach[distances[next]].insert(step-1);
                    reach[distances[next]].insert(step);
                    reach[distances[next]].insert(step+1);
                }
            }
        }
        
        return reach[n-1].size()>0;
        
    }
};
