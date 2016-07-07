/**
LeetCode-65-Valid Number
07/07/16 09:07:42
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
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
    bool isNumber(string s) {
        bool hasE, hasDigit, hasDot, hasFirst;
        hasE = hasDigit = hasDot = hasFirst = false;
        int pos=0;
        char c;
        
        s.erase(s.find_last_not_of(" \n\r\t")+1);
        int len = s.length();
        while(pos<len && s[pos]==' ')
            ++pos;
        
        while(pos < len)
        {
            c = s[pos];
            
            if(c >='0' && c<='9')
            {
                hasFirst = true;
                hasDigit = true;
                ++pos;
                continue;
            }
            
            switch(c)
            {
                case '+':
                
                case '-':
                    if(hasFirst)
                        return false;
                    hasFirst = true;
                    ++pos;
                    break;
                
                case 'e':
                
                case 'E':
                    if(hasE || !hasDigit)
                        return false;
                    hasE = true;
                    hasDigit = hasFirst = false;
                    hasDot = true;
                    ++pos;
                    break;
                
                case '.':
                    if(hasDot)
                        return false;
                    hasDot = true;
                    hasFirst = true;
                    ++pos;
                    break; 
                
                default:
                    return false;
            }
        }
        if(!hasDigit)
            return false;
        return true;
    }
};
