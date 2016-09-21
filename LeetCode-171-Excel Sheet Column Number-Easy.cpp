/**
LeetCode-171-Excel Sheet Column Number
21/09/16 10:32:49
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
    int titleToNumber(string s) {
        const int BASE = 26;
        int ret = 0;
        int len = s.length();
        
        for(int i=0; i<len; ++i)
            ret += (s[i]-'A'+1)*pow(BASE, len-i-1);
        
        return ret;
        
    }
};
