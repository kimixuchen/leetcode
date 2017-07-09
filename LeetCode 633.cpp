/*
 * Leetcode 633
 */
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
    bool judgeSquareSum(int c) {
        int sq = sqrt(c);
        bool flag = false;
        for(int i=0; i*i <= c/2; i++) {
            int r = c-i*i;
            int sq = sqrt(r);
            if(sq*sq == r) {
                flag = true;
                break;
            }
        }
        return flag;
    }
};