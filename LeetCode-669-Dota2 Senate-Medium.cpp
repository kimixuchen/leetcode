/**
LeetCode-669-Dota2 Senate
17/10/17 14:04:36
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
    string predictPartyVictory(string senate) {
        queue<int> qd;
        queue<int> qr;
        
        for(int i=0; i<senate.size(); i++)
        {
            char c = senate[i];
            if(c == 'R')
            {
                qr.push(i);
            }
            else
            {
                qd.push(i);
            }
        }
        
        while(!qr.empty() && !qd.empty())
        {
            int a = qr.front();
            int b = qd.front();
            if(a<b)
            {
                qr.pop();
                qd.pop();
                qr.push(a+senate.size());
            }
            else
            {
                qr.pop();
                qd.pop();
                qd.push(b+senate.size());
            }
        }
        
        if(!qr.empty())
            return "Radiant";
        else
            return "Dire";
    }
};
