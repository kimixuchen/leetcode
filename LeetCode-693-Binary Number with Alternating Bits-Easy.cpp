/**
LeetCode-693-Binary Number with Alternating Bits
08/10/17 09:31:36
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
#include <limits>
#include "limits.h"
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int preBit = -1;
        bool flag = true;
        
        while(n > 0)
        {
            int b = n%2;
            if(preBit == -1)
            {
                preBit = b;
            }
            else
            {
                if(preBit == b)
                {
                    flag = false;
                    break;
                }
                else
                {
                    preBit = b;
                }
            }
            n>>=1;
        }
        return flag;
    }
};
