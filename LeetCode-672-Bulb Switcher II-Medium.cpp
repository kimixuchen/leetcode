/*
LeetCode-672-Bulb Switcher II
07/09/17 09:23:49
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

using namespace std;

class Solution {
public:
    int flipLights(int n, int m) {
        if(n == 0)
            return 0;
        else if(n == 1)
        {
            if(m == 0)
                return 1;
            else if(m >= 1)
                return 2;
        }
        else if(n == 2)
        {
            if(m == 0)
                return 1;
            else if(m == 1)
                return 3;
            else if(m >= 2)
                return 4;
        }
        else if(n >= 3)
        {
            if(m == 0)
                return 1;
            else if(m == 1)
                return 4;
            else if(m == 2)
                return 7;
            else if(m >= 3)
                return 8;
        }
    }
};
