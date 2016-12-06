/*
LeetCode-464-Can I Win
06/12/16 10:14:58
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
private:
    int getState(vector<bool> &used)
    {
        int state = 0;
        for(int i=1; i<used.size(); ++i)
        {
            state <<= 1;
            if(used[i])
                state |= 1;
        }
        return state;
    }
    
    bool search(int desiredTotal, unordered_map<int, bool> &states, 
            vector<bool> &used)
    {
        if(desiredTotal <= 0)
            return false;
        int state = getState(used);
        if(states.find(state) == states.end())
        {
            for(int i=1; i<used.size(); ++i)
            {
                if(used[i]==false)
                {
                    used[i] = true;
                    if(!search(desiredTotal-i, states, used))
                    {
                        states[state] = true;
                        used[i] = false;
                        return true;
                    }
                    used[i] = false;
                }
            }
            states[state] = false;
        }
        
        return states[state];
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        unordered_map<int, bool> states;
        vector<bool> used(maxChoosableInteger+1, false);
        
        if((maxChoosableInteger+1)*maxChoosableInteger/2<desiredTotal)
            return false;
        if(desiredTotal <= 0)
            return true;
        
        if(search(desiredTotal, states, used))
            return true;
        return false;
    }
};
