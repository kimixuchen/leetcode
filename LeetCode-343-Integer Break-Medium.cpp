/*
LeetCode-343-Integer Break
15/11/16 10:41:55
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
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        
        int k = n/3;
        int rest = n%3;
        if(rest==1)
        {
            --k;
            rest += 3;
        }
        return (int)pow(3, k) * (rest==0 ? 1 : rest);
        
    }
};
