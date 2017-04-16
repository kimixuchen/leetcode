/*
LeetCode-551-Student Attendance Record I
16/04/17 09:34:04
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
    bool checkRecord(string s) {
        bool isReward = true;
        
        int numL = 0;
        int numA = 0;
        for(char c : s)
        {
            if('A'==c)
            {
                ++numA;
                if(numA>1)
                {
                    isReward = false;
                    break;
                }
                numL = 0;
            }
            else if('L'==c)
            {
                ++numL;
                if(numL>2)
                {
                    isReward = false;
                    break;
                }
            }
            else
            {
                numL = 0;
            }
        }
        
        return isReward;
        
    }
};
