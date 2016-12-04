/*
LeetCode-434-Number of Segments in a String
04/12/16 10:33:43
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
    int countSegments(string s) {
        int counter = 0;
        bool words = false;
        for(char c : s)
        {
            if(c==' ' && words)
            {
                ++counter;
                words = false;
            }
            else if(c!=' ')
            {
                if(!words)
                    words = true;
            }
        }
        if(words)
            ++counter;
        
        return counter;
        
    }
};

