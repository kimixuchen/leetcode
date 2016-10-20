/**
LeetCode-290-Word Pattern
20/10/16 09:47:09
xuchen
**/

#include <iostream>
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
    bool wordPattern(string pattern, string str) {
        int i = 0, j = 0;
        int n = pattern.length(), m = str.length();
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        
        for( ;i<n; ++i)
        {
            if(j>=m)
            {
                return false;
            }
            
            string tmp;
            while(j<m && str[j]!=' ')
            {
                tmp += str[j];
                ++j;
            }
            ++j;
            
            if(m1.find(pattern[i]) != m1.end() && m2.find(tmp)!=m2.end())
            {
                if(m1[pattern[i]] != tmp || m2[tmp] != pattern[i])
                    return false;
            }
            else if(m1.find(pattern[i]) == m1.end() && m2.find(tmp)==m2.end())
            {
                m1[pattern[i]] = tmp;
                m2[tmp] = pattern[i];
            }
            else
                return false;
        }
        
        if(j<m)
            return false;
        
        return true;
        
    }
};
