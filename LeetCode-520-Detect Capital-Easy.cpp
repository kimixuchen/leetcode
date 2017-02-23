/*
LeetCode-520-Detect Capital
23/02/17 09:55:53
xuchen
**/

#include <iostream>
#include <sstream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <priority_queue>
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
    bool detectCapitalUse(string word) {
        bool hasUpper = false;
        bool firstUpper = false;
        int upperCount = 0;
        
        if(word[0]>='A' && word[0]<='Z')   
        {
            hasUpper = true;
            firstUpper = true;
            ++upperCount;
        }
        
        for(int i=1; i<word.length(); ++i)
        {
            if(word[i]>='A' && word[i]<='Z')
            {
                ++upperCount;
            }
        }
        
        if((hasUpper && upperCount==1) || (upperCount==word.length()) || 
                (upperCount==0))
            return true;
        else
            return false;
    }
};
