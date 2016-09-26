/**
LeetCode-205-Isomorphic Strings
26/09/16 09:20:25
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
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
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ms;
        unordered_map<char, char> mt;
        for(int i=0; i<s.length(); ++i)
        {
            if(ms.find(s[i]) == ms.end())
            {
                ms[s[i]] = t[i];
                if(mt.find(t[i]) == mt.end())
                {
                    mt[t[i]] = s[i];
                }
                else
                {
                    if(mt[t[i]] != s[i])
                        return false;
                }
            }
            else
            {
                if(ms[s[i]] != t[i])
                    return false;
            }
            
        }
        
        return true;
        
    }
};
