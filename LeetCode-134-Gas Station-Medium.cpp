/**
LeetCode-134-Gas Station
08/09/16 10:03:44
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int pos = 0;
        int tank = 0;
        int lack = 0;
        for(int i=0; i<n; ++i)
        {
            if((tank=tank+gas[i]-cost[i]) < 0)
            {
                lack += tank;
                tank = 0;
                pos = i+1;
            }
        }
        
        if(tank+lack >= 0)
            return pos%n;
        else
            return -1;
        
    }
};
