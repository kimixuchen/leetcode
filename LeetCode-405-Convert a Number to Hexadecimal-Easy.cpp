/**
LeetCode-405-Convert a Number to Hexadecimal
25/09/16 09:51:53
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
    string toHex(int num) {
        if(num==0)
            return "0";
        int bnum[32];
        string dToHex = "0123456789abcdef";
        for(int i=31; i>=0; --i)
        {
            bnum[i] = num & 1;
            num>>=1;
        }
        
        string ret;
        for(int j=0; j<8; ++j)
        {
            int id = 8*bnum[j*4] + 4*bnum[j*4+1] + 2*bnum[j*4+2] + bnum[j*4+3];
            ret += dToHex[id];
        }
        int pos = 0;
        while(pos < ret.length() && ret[pos]=='0')
            ++pos;
        
        return ret.substr(pos, ret.length()-pos);
        
    }
};

