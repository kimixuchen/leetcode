/*
LeetCode-455-Assign Cookies
05/12/16 09:51:58
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int sum = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int pos1 = g.size()-1;
        int pos2 = s.size()-1;
        
        while(pos1>=0 && pos2>=0)
        {
            if(g[pos1]<=s[pos2])
            {
                ++sum;
                --pos1;
                --pos2;
            }
            else if(g[pos1]>s[pos2])
            {
                --pos1;
            }
        }
        return sum;
        
    }
};
