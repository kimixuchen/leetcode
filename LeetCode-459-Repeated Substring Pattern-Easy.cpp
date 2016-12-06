/*
LeetCode-459-Repeated Substring Pattern
05/12/16 11:49:32
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
    bool repeatedSubstringPattern(string str) {
        int n = str.length();
        bool flag = false;
        for(int i=1; i<=n/2; ++i)
        {
            if(n%i==0)
            {
                string seed = str.substr(0, i);
                int j=0;
                for( ; j<n/i; ++j)
                {
                    if(str.substr(j*i, i) != seed)
                    {
                        break;
                    }
                }
                if(j==n/i)
                    flag = true;
                if(flag)
                    break;
            }
        }
        
        return flag;
        
    }
};
