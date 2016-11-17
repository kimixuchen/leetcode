/*
LeetCode-357-Count Numbers with Unique Digits
17/11/16 10:36:07
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
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;    //zero
        for(int i=1; i<=n; ++i)
        {
            int inc = 9;
            for(int j=0; j<i-1; ++j)
                inc *= (9-j);
            sum += inc;
        }
        return sum;
        
    }
};
