/*
LeetCode-441-Arranging Coins
04/12/16 08:56:56
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

//We can also solve it with binary search
class Solution {
public:
    int arrangeCoins(int n) {
        long long sum = 0;
        int row = 0;
        while(sum <= n)
        {
            row += 1;
            sum += row;
        }
        return row-1;
        
    }
};
