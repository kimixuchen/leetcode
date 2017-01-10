/*
LeetCode-476-Number Complement
08/01/17 10:35:23
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

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int ret = 0;
        int len = 0;
        int n1 = num;
        int mask = 0;
        while(n1 > 0)
        {
            mask <<= 1;
            mask |= 1;
            n1 >>= 1;
        }
        
        return (num^0x7fffffff)&mask;
    }
};
