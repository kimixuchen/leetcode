/**
LeetCode-172-Factorial Trailing Zeroes
21/09/16 10:38:35
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
    int trailingZeroes(int n) {
        int count = 0;
        for(long long t=5; t<=n; t*=5)
            count += n/t;
        
        return count;
        
    }
};
