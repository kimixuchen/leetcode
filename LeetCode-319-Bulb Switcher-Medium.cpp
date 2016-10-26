/*
LeetCode-319-Bulb Switcher
26/10/16 09:58:22
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int counter = 0;
        for(int i=1; i*i<=n; ++i)
            ++counter;
        
        return counter;
    }
};
