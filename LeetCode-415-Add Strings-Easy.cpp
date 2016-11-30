/*
LeetCode-415-Add Strings
30/11/16 10:51:51
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
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        string ans;
        if(len1 > len2)
            ans = "0" + num1;
        else
            ans = "0" + num2;
        
        int len3 = ans.length();
        
        int inc = 0;
        int i = 0;
        for(i=0; i<len1 && i<len2; ++i)
        {
            int sum = num1[len1-i-1]+num2[len2-i-1]-'0'-'0';
            ans[len3-i-1] = (sum+inc)%10 + '0';
            inc = (sum+inc)/10;
        }
        
        if(i==len1)
        {
            while(i<len2)
            {
                int sum = num2[len2-i-1]-'0'+inc;
                ans[len3-i-1] = sum%10 + '0';
                inc = sum/10;
                ++i;
            }
        }
        else
        {
            while(i<len1)
            {
                int sum = num1[len1-i-1]-'0'+inc;
                ans[len3-i-1] = sum%10 + '0';
                inc = sum/10;
                ++i;
            }
        }
        
        ans[0] = inc+'0';
        
        if(ans[0]=='0')
            return ans.substr(1, ans.length()-1);
        
        return ans;
        
        
        
    }
};
