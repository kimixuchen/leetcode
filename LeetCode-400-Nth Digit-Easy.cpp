/*
LeetCode-400-Nth Digit
18/11/16 12:55:02
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
    int findNthDigit(int n) {
        int level = 1;
        long long sum = 0;
        
        while(sum < n)
        {
            sum += pow(10, level-1)*9*level;
            ++level;
        }
        level--;
        sum -= pow(10, level-1)*9*level;
        n -= sum;
        n--;
        int index = n/level;
        int pos = level-(n%level);
        int num = pow(10, level-1)+index;
        int ret = 0;
        
        for(int i=1; i<pos; ++i)
        {
            num /= 10;
        }
        ret = num%10;
        
        return ret;
        
    }
};
