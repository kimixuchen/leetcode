/*
LeetCode-338-Counting Bits
15/11/16 08:50:01
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
#include <cstring>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        unordered_map<int, int> bit1s;
        
        bit1s[0] = 0;
        int sum = 1;
        for(int i=1; i<32; ++i)
        {
            bit1s[sum] = i;
            sum += 1<<i;
        }
        
        vector<int> ret(num+1, 0);
        ret[0] = 0;
        int tails;
        for(int i=0; i<num; ++i)
        {
            tails = i&(i^(i+1));
            ret[i+1] = ret[i]-bit1s[tails]+1;
        }
        return ret;
    }
};
