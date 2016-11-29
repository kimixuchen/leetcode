/*
LeetCode-402-Remove K Digits
29/11/16 09:49:24
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
    string removeKdigits(string num, int k) {
        int n = num.length();
        
        if(n==k)
            return "0";
        
        int zeropos = k;
        while(zeropos<n && num[zeropos]=='0')
            ++zeropos;
        if(zeropos > k)
            return zeropos==n ? "0":num.substr(zeropos, n-zeropos);
        
        unordered_set<int> removepos;
        int startpos = 0;
        int base = k;
        while(removepos.size() < k)
        {
            int _min = INT_MAX;
            int minpos = 0;
            for(int i=base; i>=startpos; --i)
            {
                if(num[i]-'0' <= _min)
                {
                    _min = num[i]-'0';
                    minpos = i;
                }
            }
            for(int i=startpos; i<minpos; ++i)
            {
                removepos.insert(i);
            }
            startpos = minpos+1;
            base = startpos + k-removepos.size();
        }
        
        string ret;
        bool iszero = true;
        for(int i=0; i<n; ++i)
        {
            if(removepos.find(i)==removepos.end())
            {
                if(num[i]!='0')
                    iszero = false;
                if(!iszero)
                    ret += string(1, num[i]);
            }
        }
        
        return ret;
        
    }
};
