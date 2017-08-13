/*
 * Leetcode 657-Judge Route Circle
 */
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
    bool judgeCircle(string moves) {
        int dirNums[4];
        memset(dirNums, 0, sizeof(dirNums));
        
        for(char c : moves) {
            if(c=='U')
                dirNums[0]++;
            else if(c=='D')
                dirNums[1]++;
            else if(c=='L')
                dirNums[2]++;
            else if(c=='R')
                dirNums[3]++;
        }
        if (dirNums[0]==dirNums[1] && dirNums[2]==dirNums[3])
            return true;
        else
            return false;
    }
};




















