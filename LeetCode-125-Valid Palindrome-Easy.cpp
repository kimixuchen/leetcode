/**
LeetCode-125-Valid Palindrome
02/09/16 08:08:34
xuchen
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
private:
    bool isAlpha(char c)
    {
        if((c>='A' && c<='Z') || (c>='a' && c<='z'))
            return true;
        else
            return false;
    }
    bool isNum(char c)
    {
        if(c>='0' && c<='9')
            return true;
        else
            return false;
    }
    
public:
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.length()-1;
        while(i<=j)
        {
            if(!isAlpha(s[i]) && !isNum(s[i]))
            {
                ++i;
            }
            else if(!isAlpha(s[j]) && !isNum(s[j]))
            {
                --j;
            }
            else
            {
                int diff = abs(s[i]-s[j]);
                if(diff==0 || (diff==32 && isAlpha(s[i]) && isAlpha(s[j])))
                {
                    ++i;
                    --j;
                }
                else
                    return false;
            }
        }
        
        return true;
        
    }
};
