/*
LeetCode-447-Number of Boomerangs
04/12/16 09:47:58
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
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ret = 0;
        for(auto p : points)
        {
            unordered_map<int, int> map;
            for(auto a : points)
            {
                int dis = (p.first-a.first)*(p.first-a.first) + 
                    (p.second-a.second)*(p.second-a.second);
                if(map.find(dis)==map.end())
                    map[dis] = 1;
                else
                {
                    ret += map[dis]*2;
                    map[dis]++;
                }
            }
        }
        return ret;
        
    }
};
