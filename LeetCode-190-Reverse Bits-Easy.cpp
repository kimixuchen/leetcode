/**
LeetCode-190-Reverse Bits
22/09/16 10:25:25
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
    uint32_t reverseBits(uint32_t n) {
        int ret = 0;
        for(int i=0; i<31; ++i)
        {
            if(n&1 == 1)
                ++ret;
            ret <<= 1;
            n >>= 1;
        }
        return ret+n;
        
    }
};
