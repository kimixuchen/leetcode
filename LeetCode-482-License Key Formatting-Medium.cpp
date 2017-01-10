/*
LeetCode-482-License Key Formatting
08/01/17 11:49:17
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
    string licenseKeyFormatting(string S, int K) {
        int n = S.length();
        int counter = 0;
        string ret;
        
        for(int i=n-1; i>=0; --i)
        {
            if(S[i]!='-')
            {
                ++counter;
                if(counter > K)
                {
                    ret = "-"+ret;
                    counter = 1;
                }
                if(S[i]>='a' && S[i]<='z')
                {
                    ret = string(1, S[i]+'A'-'a')+ret;
                }
                else
                {
                    ret = string(1, S[i])+ret;
                }
            }
        }
        
        return ret;
        
    }
};
